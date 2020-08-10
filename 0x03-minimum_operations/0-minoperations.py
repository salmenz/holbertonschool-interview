#!/usr/bin/python3
"""
minimum_operations
"""


def minOperations(n):
    """minimum_operations"""
    b = 1
    r = 0
    h = 1
    if not isinstance(n, int):
        return 0
    if n <= 0:
        return 0
    while n != h:
        if n % h == 0:
            r += 2
            b = h
            h *= 2
        else:
            r += 1
            h += b
    return r
