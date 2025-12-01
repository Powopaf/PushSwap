#!/usr/bin/env bash

PUSH_SWAP=./push_swap
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
RESET="\033[0m"
BOLD="\033[1m"
CHECK_MARK="✓"
CROSS_MARK="✗"
USE_VALGRIND=0
VALGRIND=(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes)
TOTAL=0

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

test1() {
	a1="$1"
	a2="$2"
	a3="$3"
	a4="$4"
	TOTAL=$((TOTAL + 1))
	printf "%b[Test %d]%b Input: %s %s %s %s\n" "$BLUE" "$TOTAL" "$RESET" "$a1" "$a2" "$a3" "$a4"
		    if [ "$USE_VALGRIND" -eq 1 ]; then
				logfile="test1.out.valgrind"
				touch "$logfile"
				ops="$("${VALGRIND[@]}" --log-file="$logfile" "$PUSH_SWAP" "$a1" "$a2" "$a3" "$a4")"
				r=$(printf "%s" "$ops" | ./checker_linux "$a1" "$a2" "$a3" "$a4")
				if [ "$r" != "OK" ]; then
					printf "%bError:%b Checker failed for input %s %s %s %s\n" "$RED" "$RESET" "$a1" "$a2" "$a3" "$a4"
				else
					printf "%bSUCCESS%b Checker passed for input %s %s %s %s\n" "$GREEN" "$RESET" "$a1" "$a2" "$a3" "$a4"
				fi
	  else
		  ops="$($PUSH_SWAP "$a1" "$a2" "$a3" "$a4")"
		  r=$(printf "%s" "$ops" | ./checker_linux "$a1" "$a2" "$a3" "$a4")
		  if [ "$r" != "OK" ]; then
			  printf "%bError:%b Checker failed for input %s %s %s %s\n" "$RED" "$RESET" "$a1" "$a2" "$a3" "$a4"
		  else
			  printf "%bSUCCESS%b Checker passed for input %s %s %s %s\n" "$GREEN" "$RESET" "$a1" "$a2" "$a3" "$a4"
		  fi
	  fi
	  printf "%bNB OPERATION:%b %d\n" "$YELLOW" "$RESET" "$(printf "%s" "$ops" | wc -l)"
}

test2() {
	a1="$1"
	TOTAL=$((TOTAL + 1))
	printf "%b[Test %d]%b Input: %s\n" "$BLUE" "$TOTAL" "$RESET" "$a1"
	if [ "$USE_VALGRIND" -eq 1 ]; then
		logfile="test2.out.valgrind"
		touch "$logfile"
		ops="$("${VALGRIND[@]}" --log-file="$logfile" "$PUSH_SWAP" "$a1")"
	else
		ops="$($PUSH_SWAP "$a1")"
	fi
	r=$(printf "%s" "$ops" | ./checker_linux "$a1")
	if [ "$r" != "OK" ]; then
		printf "%bError:%b Checker failed for input %s\n" "$RED" "$RESET" "$a1"
	else
		printf "%bSUCCESS%b Checker passed for input %s\n" "$GREEN" "$RESET" "$a1"
	fi
	printf "%bNB OPERATION:%b %d\n" "$YELLOW" "$RESET" "$(printf "%s" "$ops" | wc -l)"
}

test3() {
	a1="$1"
	a2="$2"
	TOTAL=$((TOTAL + 1))
	printf "%b[Test %d]%b Input: %s %s\n" "$BLUE" "$TOTAL" "$RESET" "$a1" "$a2"
	if [ "$USE_VALGRIND" -eq 1 ]; then
		logfile="test3.out.valgrind"
		touch "$logfile"
		ops="$("${VALGRIND[@]}" --log-file="$logfile" "$PUSH_SWAP" "$a1" "$a2")"
	else
		ops="$($PUSH_SWAP "$a1" "$a2")"
	fi
	r=$(printf "%s" "$ops" | ./checker_linux "$a1" "$a2")
	if [ "$r" != "OK" ]; then
		printf "%bError:%b Checker failed for input %s %s\n" "$RED" "$RESET" "$a1" "$a2"
	else
		printf "%bSUCCESS%b Checker passed for input %s %s\n" "$GREEN" "$RESET" "$a1" "$a2"
	fi
	printf "%bNB OPERATION:%b %d\n" "$YELLOW" "$RESET" "$(printf "%s" "$ops" | wc -l)"
}

test4 () {
	a1="$1"
	TOTAL=$((TOTAL + 1))
	printf "%b[Test %d]%b Input: %s\n" "$BLUE" "$TOTAL" "$RESET" "$a1"
	if [ "$USE_VALGRIND" -eq 1 ]; then
		logfile="test4.out.valgrind"
		touch "$logfile"
		ops="$("${VALGRIND[@]}" --log-file="$logfile" "$PUSH_SWAP" "$a1")"
	else
		ops="$($PUSH_SWAP "$a1")"
	fi
	r=$(printf "%s" "$ops" | ./checker_linux "$a1")
	if [ "$r" != "OK" ]; then
		printf "%bError:%b Checker failed for input %s\n" "$RED" "$RESET" "$a1"
	else
		printf "%bSUCCESS%b Checker passed for input %s\n" "$GREEN" "$RESET" "$a1"
	fi
	printf "%bNB OPERATION:%b %d\n" "$YELLOW" "$RESET" "$(printf "%s" "$ops" | wc -l)"
}

printf "%b[BUILD]%b running make\n" "$BLUE" "$RESET"
if [ ! -f Makefile ] && [ ! -f makefile ]; then
    printf "%bError:%b no Makefile found in this directory\n" "$RED" "$RESET"
    exit 1
fi
make re
BUILD_STATUS=$?
if [ "$BUILD_STATUS" -ne 0 ]; then
    printf "%b%s%b compilation failed (exit code %d)\n" "$RED" "$CROSS_MARK" "$RESET" "$BUILD_STATUS"
    exit 1
fi
if [ ! -x "$PUSH_SWAP" ]; then
    printf "%bError:%b %s not found or not executable after make\n" "$RED" "$RESET" "$PUSH_SWAP"
    exit 1
fi
if [ ! -x ./checker_linux ]; then
	printf "%bError:%b %s not found or not executable after make\n" "$RED" "$RESET" "./checker_linux"
	exit 1
fi
printf "  %b%s%b compilation OK, found %s\n\n" "$GREEN" "$CHECK_MARK" "$RESET" "$PUSH_SWAP"

touch test3.out.valgrind
touch test4.out.valgrind

test1 3 2 1 0
test2 "811362 -686121 -637284 727131 533628 -991222 -156255 -115573 873292 \
-510927 242807 633283 -415219 -713325 342461 -483873 -234164 -326782 -480981 \
-20869 437698 574346 -332183 950544 127329 155112 -206656 -441904 -247903 775995 \
192952 734520 -382250 543076 -780083 -767622 -780659 -494287 384973 572575 -559491 \
-547241 660984 -215557 165809 -790898 21953 -623090 726225 942436 487596 -800190 350812 \
-909228 289178 520464 777574 240377 932378 -546438 895335 595385 -525644 392041 808945 \
735291 -800618 355529 -262773 -356092 151687 834056 -7441 -438531 850885 -407564 -836932 \
42897 -708290 501256 -277733 -442640 740476 334545 -411161 -103820 -683111 -526460 -936392 \
865342 -758723 -200109 -669874 474330 -46267 86502 160751 -422001 -672587 739849"

test2 "50 20 -536 -922 999 -523 524 -229 -749 17 -247 -832 654 818 -761 999 \
934 -245 -641 681 -344 120 -794 -515 505 -185 -188 157 -93 -67 -535 378 -465 \
-132 136 802 0 483 -926 -847 -558 -688 441 547 -427 -854 885 877 -270 -724 \
602 831 -970 -134 -525 -218 -434 -993 163 427 -108 600 -430 118 -125 -771 \
640 614 223 796 -766 975 -317 -492 495 -169 -700 194 -657 673 927 -846 219 \
673 -846 363 -304 687 -514 -677 -73 -870 15 -401 759 799 -849 -207 -806 492 \
776 676 -67 -755 -685 686 -391 -89 -62 -202 -395 -407 470 -813 -269 644 -11 \
-24 335 987 897 -29 256 -398 210 126 244 318 817 852 -539 -552 135 459 -643 \
839 -485 -288 405 -226 -264 -979 658 960 -42 -445 -814 -887 171 122 60 999 \
-682 255 -83 301 979 469 243 24 -408 77 309 469 961 520 426 256 717 286 \
-821 -768 55 750 -765 138 55 452 486 -1000 -143 -585 -869 427 981 -553 385 \
-570 640 -502 348 370 -700 443 -364 236 210 471 160 478 -443 477 921 -882 477 \
231 -330 880 -607 -162 140 -761 -45 -316 500 310 -648 -853 -801 526 370 805 -826 \
741 947 270 661 994 -551 414 -596 284 74 556 672 563 -407 446 849 846 -213 -167 \
649 224 775 -483 -977 47 706 -654 945 822 -171 451 177 609 -906 -674 -166 48 775 \
733 -146 -780 398 -349 294 421 392 -773 -221 -834 394 620 -9 -26 -510 -47 -167 448 \
-96 -718 241 -864 -479 -280 -996 102 -239 789 -323 102 -4 139 -639 -56 -807 811 943 \
737 662 848 164 363 -179 -265 289 -496 -645 214 57 -255 168 -534 -597 956 -649 787 \
832 319 -903 8 911 -74 782 -719 -753 739 605 298 9 481 287 -817 -937 -614 -182 -519 \
-791 786 -68 -281 413 -711 684 -40 794 922 86 -409 -792 682 280 -361 601 -986 -937 \
-369 556 -319 -642 954 808 284 -628 497 842 -985 -584 503 -124 822 -774 702 719 -839 \
-756 -479 -930 826 191 -58 -593 486 -566 -468 638 724 318 -937 770 827 917 -932 -894 \
-476 113 -434 750 -967 764 950 -570 260 656 304 309 -40 -982 -459 171 -836 596 -147 \
-509 840 545 -353 -265 -334 312 -238 -465 -168 -403 724 401 -122 968 531 -991 -598 \
479 -127 214 22 -625 -793 -75 -869 57 55 324 -727 -696 -702 -638 -505 -311 622 -786 \
-228 851 668 368 -341 -700 -618 537 -272 80 745 426 917 605 -703 -17 -592 198 -403 \
-927 740 754 576 -893 507 450 -397 -189 -562 264 777 -85 -904 -176 -33 -587 -31 -738 \
-285 -733 -453 463 934 30 -760 -696 -642 661 479"

test3 42 P

test4 "-42 0 42 7 -7 3 -3 p -1 0"
echo
printf "%b%b[SUMMARY]%b\n" "$BOLD" "$BLUE" "$RESET"
printf "%b%bTotal tests run: %d%b\n\n" "$BOLD" "$GREEN" "$TOTAL" "$RESET"
printf "%b[END]%b Tests completed. Cleaning up...\n" "$BLUE" "$RESET"
cleanup
printf "%b%b[EXIT]%b\n" "$BOLD" "$GREEN" "$RESET"
exit 0
