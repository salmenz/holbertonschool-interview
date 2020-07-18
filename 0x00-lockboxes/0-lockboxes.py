#!/usr/bin/python3
'''Lockboxes'''


def canUnlockAll(boxes):
    """check if you can open all the boxes"""
    l1 = boxes[0]
    for i in range(1, len(boxes)):
        if i in l1:
            l1 += boxes[i]
    for i in range(1, len(boxes)):
        if i in l1:
            l1 += boxes[i]
    list(set(l1))
    b = 1
    for i in range(1, len(boxes)-1):
        if i not in l1:
            b = 0
    if b == 1:
        return True
    else:
        return False
