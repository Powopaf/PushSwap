# PushSwap

In this project, you will sort data in a stack using a limited set of instructions, aiming to achieve the lowest possible number of actions. To succeed, you will need to work with various algorithms and choose the most appropriate one for optimized data sorting

procedure MAIN_PUSH_SWAP(arguments):
    stackA ← build_stack_from_arguments(arguments)
    stackB ← empty_stack()

    n ← size(stackA)

    if is_already_sorted(stackA):
        return

    if n ≤ 3:
        sort_3(stackA)           // small hard-coded sort using sa/ra/rra
        return

    if n ≤ 5:
        sort_5(stackA, stackB)   // e.g. push min to B, sort 3, pa pa
        return

    normalize_indices(stackA)    // give each node an index 0..n-1
    radix_sort(stackA, stackB)   // main algorithm (below)

procedure NORMALIZE_INDICES(stackA):
    n ← size(stackA)

    // 1. copy all values into an array
    array[0..n-1]
    node ← top(stackA)
    i ← 0
    while node ≠ null:
        array[i] ← node.value
        node ← node.next
        i ← i + 1

    // 2. sort the array (any O(n log n) sort is fine)
    SORT(array)      // e.g. quicksort; details not important here

    // 3. for each node in the stack, find its position in the sorted array
    node ← top(stackA)
    while node ≠ null:
        index ← FIND_INDEX_IN_ARRAY(array, n, node.value)
        node.index ← index
        node ← node.next

procedure FIND_INDEX_IN_ARRAY(array, n, value):
    // simplest version: linear search
    i ← 0
    while i < n:
        if array[i] = value:
            return i
        i ← i + 1
    // (value is assumed to be present)

procedure COUNT_MAX_BITS(stackA):
    // find maximum index in stackA
    maxIndex ← 0
    node ← top(stackA)
    while node ≠ null:
        if node.index > maxIndex:
            maxIndex ← node.index
        node ← node.next

    // count bits of maxIndex
    bits ← 0
    while (maxIndex >> bits) ≠ 0:
        bits ← bits + 1

    return bits
procedure RADIX_SORT(stackA, stackB):
    n ← size(stackA)
    maxBits ← COUNT_MAX_BITS(stackA)

    bit ← 0
    while bit < maxBits:
        i ← 0

        // process all elements currently in A
        while i < n:
            value ← top(stackA).index

            if ((value >> bit) AND 1) = 0 then
                // bit is 0 → send to B
                pb(stackA, stackB)     // + print "pb"
            else
                // bit is 1 → keep in A but move to bottom
                ra(stackA)             // + print "ra"
            end if

            i ← i + 1
        end while

        // bring everything back from B to A
        while NOT is_empty(stackB):
            pa(stackA, stackB)         // + print "pa"
        end while

        bit ← bit + 1
    end while
