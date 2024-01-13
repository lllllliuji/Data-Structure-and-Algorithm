# 最长不相交子区间
from cmath import inf


def solution(intervals: list([])):
    n = len(intervals)
    intervals.sort(key=lambda x: x[1])
    last_right = -inf
    for i in range(n):
        if intervals[i][0] >= last_right: 