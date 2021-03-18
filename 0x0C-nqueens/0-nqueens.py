#!/usr/bin/python3
"""
Script that solves the N queens problem based on the general Backtracking
algorithm.
This is:
procedure bt(c) is
    if reject(P, c) then return
    if accept(P, c) then output(P, c)
    s  first(P, c)
    while s  NULL do
        bt(s)
        s  next(P, s)
"""
import sys


def valid_pos(solution, pos):
    """
    Function that verifies if the position is valid
    """
    for queen in solution:
        if queen[1] == pos[1]:
            return False
        if (queen[0] + queen[1]) == (pos[0] + pos[1]):
            return False
        if (queen[0] - queen[1]) == (pos[0] - pos[1]):
            return False
    return True


def solve_queens(row, n, solution):
    """
    Function that finds the solution recursively, from the root down
    """
    if (row == n):
        print(solution)
    else:
        for col in range(n):
            pos = [row, col]
            if valid_pos(solution, pos):
                solution.append(pos)
                solve_queens(row + 1, n, solution)
                solution.remove(pos)


def main(n):
    """
    Main function
    """
    solution = []
    """ From root(0) down(n) """
    solve_queens(0, n, solution)

if __name__ == '__main__':
    """ Validate the arguments from OS """
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)
    try:
        i = int(sys.argv[1])
    except BaseException:
        print('N must be a number')
        sys.exit(1)
    i = int(sys.argv[1])
    if i < 4:
        print('N must be at least 4')
        sys.exit(1)

    """ Calling the main function """
    main(i)
