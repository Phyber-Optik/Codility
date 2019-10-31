#!/bin/python3

import os


# Complete the substrCount function below.
def substrCount(n, s):
    streak_from_start = [1] * n
    streak_from_end = [1] * n
    for i in range(n):
        streak_from_start[i] = (streak_from_start[i - 1] + 1) if (i > 0 and s[i] == s[i - 1]) else 1
    for i in reversed(range(n)):
        streak_from_end[i] = (streak_from_end[i + 1] + 1) if (i + 1 < n and s[i] == s[i + 1]) else 1
    str_cnt = 0
    for i in range(0, n):
        cur_streak = streak_from_start[i]
        str_cnt += cur_streak
        if i > 0 and i + 1 < n and s[i - 1] == s[i + 1] and streak_from_start[i] == 1:
            str_cnt += min(streak_from_start[i - 1], streak_from_end[i + 1])
    return str_cnt

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = substrCount(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
