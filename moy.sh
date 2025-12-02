#!/bin/bash

MOY=0
TOTAL=1000000
BAR_WIDTH=50

LAST_ARGS=""
LAST_NB=0

for ((i=1; i<=TOTAL; i++))
do
    # generate numbers once so we can reuse them later
    ARGS=$(./numbers.lua 500 -10000 10000)

    # count operations
    NB=$(./push_swap $ARGS | wc -l)
    MOY=$((MOY + NB))

    # save last test info
    LAST_ARGS="$ARGS"
    LAST_NB="$NB"

    # progress bar
    PERCENT=$(( i * 100 / TOTAL ))
    FILLED=$(( PERCENT * BAR_WIDTH / 100 ))

    BAR=$(printf '%*s' "$FILLED" '' | tr ' ' '#')
    EMPTY=$(printf '%*s' "$((BAR_WIDTH - FILLED))" '')

    printf "\r[%s%s] %3d%% (test %d/%d, last: %d ops)" \
        "$BAR" "$EMPTY" "$PERCENT" "$i" "$TOTAL" "$NB"
done

echo

MOY=$((MOY / TOTAL))
echo "Moyenne pour $TOTAL tests de 500 nombres : $MOY opérations"
