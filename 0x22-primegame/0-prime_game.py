#!/usr/bin/python3
"""Prime Game"""


def isprime(n):
    """determine if a number is prime"""
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def delete_numbers(n, num):
    """removing that number and its multiples"""
    for i in range(len(num)):
        if num[i] % n == 0:
            num[i] = 0


def isWinner(x, nums):
    """Prime Game"""
    if not nums or x < 1:
        return None

    Maria = 0
    Ben = 0
    for i in range(x):
        turn = 0
        num = list(range(1, nums[i]+1))

        while True:
            change = False

            for k, n in enumerate(num):
                if n > 1 and isprime(n):
                    delete_numbers(n, num)
                    change = True
                    turn += 1
                    break

            if change is False:
                break

        if turn % 2 != 0:
            Maria += 1
        else:
            Ben += 1

    if Maria < Ben:
        return "Ben"

    if Maria > Ben:
        return "Maria"

    return None
