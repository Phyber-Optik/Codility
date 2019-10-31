#!/bin/python3

import os
from collections import defaultdict


# Complete the isValid function below.
def isValid(s):
    frequency = defaultdict(int)
    for ch in s:
        frequency[ch] += 1
    freq_list = list(sorted(frequency.values()))
    majority = freq_list[len(freq_list) // 2]
    different = 0
    for freq in freq_list:
        if freq != majority:
            if freq - 1 != 0 and freq - 1 != majority:
                return "NO"
            different += 1
    return "YES" if different <= 1 else "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
