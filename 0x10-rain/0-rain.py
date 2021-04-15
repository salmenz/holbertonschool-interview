#!/usr/bin/python3
"""rain function"""


def rain(walls):
    """calculates how much water will be retained after it rains"""
    if not walls:
        return 0
    if len(walls) <= 2:
        return 0
    r = 0
    for i in range(1, len(walls) - 1):
        left = max(walls[:i])
        right = max(walls[i + 1:])
        mi = min(left, right)
        if walls[i] < mi:
            r += mi - walls[i]
    return r
