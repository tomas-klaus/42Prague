#!/bin/bash

# List of numbers to permute
numbers=(0 1 2 3 4)

# Function to generate permutations of the array
permute() {
    local arr=("$@")
    if [ ${#arr[@]} -eq 1 ]; then
        echo "${arr[@]}"
        return
    fi

    for ((i = 0; i < ${#arr[@]}; i++)); do
        local left=("${arr[@]:0:i}")
        local right=("${arr[@]:i+1}")
        permute "${left[@]}" "${right[@]}" | while read -r perm; do
            echo "${arr[i]} $perm"
        done
    done
}

# Run ./push_swap with each permutation
permute "${numbers[@]}" | while read -r perm; do
    echo "Running: ./push_swap $perm"
    ./push_swap $perm
done