#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing N non-attacking queens
on an N×N chessboard.
This is a program that solves the N queens problem.
"""
import sys


def valid_position(solution, pos):
    """ verif if the position is valid """
    for queen in solution:
        if queen[1] == pos[1]:
            return False
        if (queen[0] + queen[1]) == (pos[0] + pos[1]):
            return False
        if (queen[0] - queen[1]) == (pos[0] - pos[1]):
            return False
    return True


def solve_queens(row, n, solution):
    """ find the solution from the root down """
    if (row == n):
        print(solution)
    else:
        for col in range(n):
            pos = [row, col]
            if valid_position(solution, pos):
                solution.append(pos)
                solve_queens(row + 1, n, solution)
                solution.remove(pos)


def main(n):
    """ Main Function """
    solution = []
    solve_queens(0, n, solution)


if __name__ == '__main__':
    """ get input """
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)
    try:
        input = int(sys.argv[1])
    except BaseException:
        print('N must be a number')
        sys.exit(1)
    input = int(sys.argv[1])
    if input < 4:
        print('N must be at least 4')
        sys.exit(1)

    """ Calling the main function """
    main(input)
