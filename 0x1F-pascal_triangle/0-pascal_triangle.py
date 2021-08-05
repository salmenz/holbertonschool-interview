#!/usr/bin/python3
"""list of lists of integers representing the Pascal’s triangle of n"""


def pascal_triangle(n):
    """list of lists of integers representing the Pascal’s triangle of n"""

    m = []
    for i in range(1, n + 1):
        l1 = []
        for j in range(i):
            if j == 0 or j == i - 1:
                l1.append(1)
            else:
                s = m[i - 2][j - 1] + m[i - 2][j]
                l1.append(s)
        m.append(l1)

    return m
