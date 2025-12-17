#!/usr/bin/env bash

PUSH_SWAP=./push_swap
CHECKER=./checker_linux

RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
RESET="\033[0m"
BOLD="\033[1m"
CHECK_MARK="✓"
CROSS_MARK="✗"

USE_VALGRIND=1
VALGRIND=(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes)

if [ "$USE_VALGRIND" -eq 1 ]; then
	if ! command -v valgrind >/dev/null 2>&1; then
		printf "%b[WARN]%b valgrind not found, disabling valgrind checks\n" "$YELLOW" "$RESET"
		USE_VALGRIND=0
	else
		printf "%b[INFO]%b valgrind enabled\n" "$BLUE" "$RESET"
	fi
fi

cleanup() {
	make fclean
}
trap cleanup EXIT

test1() {
	mapfile -t nums < <(perl numbers.perl "$1" "$2" "$3")

	if [ "$USE_VALGRIND" -eq 1 ]; then
		"${VALGRIND[@]}" "$PUSH_SWAP" "${nums[@]}" > /dev/null 2> test1.valgrind
	fi

	res=$("$PUSH_SWAP" "${nums[@]}" | "$CHECKER" "${nums[@]}")
	if [ "$res" = "OK" ]; then
		printf "%b%b %s %b%b\n" "$GREEN" "$BOLD" "$CHECK_MARK" "Test 1 passed" "$RESET" "$RESET"
	else
		printf "%b%b %s %b%b\n" "$RED" "$BOLD" "$CROSS_MARK" "Test 1 failed" "$RESET" "$RESET"
	fi

	echo $("$PUSH_SWAP" "${nums[@]}" | wc -l)
}

test2() {
	nums=(100 a 75 32)

	if [ "$USE_VALGRIND" -eq 1 ]; then
		"${VALGRIND[@]}" "$PUSH_SWAP" "${nums[@]}" > /dev/null 2> test2.valgrind
	fi

	echo $("$PUSH_SWAP" "${nums[@]}")
	echo "We expect an Error"
}

test3() {
	args=("9 6 1" 2 90 61 355 62 77)
	if [ "$USE_VALGRIND" -eq 1 ]; then
		"${VALGRIND[@]}" "$PUSH_SWAP" "${args[@]}" > /dev/null 2> test3.valgrind
	fi
	ops=$("$PUSH_SWAP" "${args[@]}" 2> test3.err)
	if [ -s test3.err ]; then
		printf "%b%b %s %b%b\n" "$RED" "$BOLD" "$CROSS_MARK" "Test 3 failed (stderr not empty)" "$RESET" "$RESET"
		cat test3.err
		return
	fi
	res=$(printf '%s\n' "$ops" | "$CHECKER" "${args[@]}")
	if [ "$res" = "OK" ]; then
		printf "%b%b %s %b%b\n" "$GREEN" "$BOLD" "$CHECK_MARK" "Test 3 passed" "$RESET" "$RESET"
	else
		printf "%b%b %s %b%b\n" "$RED" "$BOLD" "$CROSS_MARK" "Test 3 failed" "$RESET" "$RESET"
	fi
}

make re
test1 100 -1000 1000
test2
test3
