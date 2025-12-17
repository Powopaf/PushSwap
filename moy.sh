#!/bin/bash

MOY=0
TOTAL=100000
BAR_WIDTH=50

PUSH_SWAP=./push_swap
ERROR_LOG=pushswap_errors.log

if [ ! -x "$PUSH_SWAP" ]; then
  echo "Error: $PUSH_SWAP not found or not executable (run: make)"
  exit 1
fi

: > "$ERROR_LOG"

for ((i=1; i<=TOTAL; i++))
do
    ARGS=$(./numbers.perl 10 -1000 1000)

    # count operations, keep stderr out of terminal so the bar stays clean
	TEST=$("$PUSH_SWAP" $ARGS | ./checker_linux $ARGS)
	if [ "$TEST" != "OK" ]; then
		echo "Test $i failed with args: $ARGS" >> "$ERROR_LOG"
		echo "Output: $TEST" >> "$ERROR_LOG"
	fi
    NB=$("$PUSH_SWAP" $ARGS | wc -l)
    NB=${NB//[[:space:]]/}   # remove spaces from wc output

    MOY=$((MOY + NB))

    # progress bar (rebuilt every iteration)
    PERCENT=$(( i * 100 / TOTAL ))
    FILLED=$(( PERCENT * BAR_WIDTH / 100 ))

    BAR=$(printf '%*s' "$FILLED" '' | tr ' ' '#')
    EMPTY=$(printf '%*s' "$((BAR_WIDTH - FILLED))" '')

    # overwrite the same line (clear line then print)
    printf "\r\033[K[%s%s] %3d%% (test %d/%d, last: %d ops)" \
        "$BAR" "$EMPTY" "$PERCENT" "$i" "$TOTAL" "$NB"
done

echo
MOY=$((MOY / TOTAL))
echo "Moyenne pour $TOTAL tests de 500 nombres : $MOY opérations"
echo "stderr logged to: $ERROR_LOG"
