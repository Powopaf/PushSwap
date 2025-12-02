#!/bin/bash

MOY=0

for i in {1..10000}
do
	NB=$(./push_swap $(./numbers.lua 500 -10000 10000) | wc -l)
	echo "Test $i: $NB opérations"
	MOY=$((MOY + NB))
done
MOY=$((MOY / 10000))
echo "Moyenne pour 10000 tests de 500 nombres : $MOY opérations"