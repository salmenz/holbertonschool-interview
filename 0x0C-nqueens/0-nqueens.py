#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing N non-attacking queens
on an N×N chessboard.
This is a program that solves the N queens problem.
"""
import sys


def zeromat(n):
    board = []
    for x in range(n):
        row = []
        for y in range(n):
            row.append(0)
        board.append(row)
    return(board)


def showmat(board, n):
    a = []
    for i in range(n):
        b = []
        for j in range(n):
            if board[i][j] == 1:
                b.append(i)
                b.append(j)
                a.append(b)
    print(a)


def safepos(board, row, col, n):
    for i in range(col):
        if board[row][i] == 1:
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if (board[i][j]):
            return False
        i -= 1
        j -= 1
    i = row
    j = col
    while j >= 0 and i < n:
        if (board[i][j]):
            return False
        i = i + 1
        j = j - 1
    return True


def nqueen(board, col, n):
    if (col == n):
        showmat(board, n)
        return True
    res = False
    for i in range(n):
        if (safepos(board, i, col, n)):
            board[i][col] = 1
            res = nqueen(board, col + 1, n) or res
            board[i][col] = 0
    return res


def nq(board, n):
    if (nqueen(board, 0, n) is False):
        print("Solution does not exist")
        exit(1)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        if not type(int(sys.argv[1])) is int:
            print("N must be a number")
            exit(1)
    except BaseException:
        print("N must be a number")
        exit(1)
    n = int(sys.argv[1])
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    board = zeromat(n)
    nq(board, n)
