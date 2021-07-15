#!/usr/bin/python3
"""the perimeter of the island described in grid"""


def island_perimeter(grid):
    """the perimeter of the island described in grid"""
    s = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if i == 0 or grid[i - 1][j] == 0:
                    s += 1
                if j == 0 or grid[i][j - 1] == 0:
                    s += 1
                if i == len(grid) - 1 or grid[i + 1][j] == 0:
                    s += 1
                if j == len(grid[i]) - 1 or grid[i][j + 1] == 0:
                    s += 1
    return s
