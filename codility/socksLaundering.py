# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(K, C, D):
    # write your code in Python 3.6
    clean = {}
    dirty = {}
    for cs in C:
        if cs not in clean:
            clean[cs] = 1
        else:
            clean[cs] += 1
    for ds in D:
        if ds not in dirty:
            dirty[ds] = 1
        else:
            dirty[ds] += 1
    ans = 0
    for k, v in clean.items():
        rem = v % 2
        ans += v // 2
        if K > 0 and rem and k in dirty and dirty[k] > 0:
            ans += 1
            K -= 1
            dirty[k] -= 1
    for k, v in dirty.items():
        dirty_pair = min(K // 2, dirty[k] // 2)
        ans += dirty_pair
        K -= dirty_pair * 2
    return ans
