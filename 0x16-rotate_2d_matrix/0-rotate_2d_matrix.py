#!/usr/bin/python3
"""Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    """2D matrix, rotate it 90 degrees clockwise"""
    for col in zip(*matrix):
        matrix.append(list(reversed(col)))
        matrix.pop(0)
