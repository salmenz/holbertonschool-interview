#!/usr/bin/python3
"""determine the fewest number of coins needed to meet a given amount total"""


def makeChange(coins, total):
    """determine the fewest number of coins needed
    to meet a given amount total"""
    if total <= 0:
        return 0
    s_coins = sorted(coins, reverse=True)
    s = 0
    k = 0
    i = 0
    while s < total and i < len(coins):
        if total - s >= s_coins[i]:
            s += s_coins[i]
            k += 1
        else:
            i += 1
    return k if s == total else -1
