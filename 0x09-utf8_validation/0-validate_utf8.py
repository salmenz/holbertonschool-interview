#!/usr/bin/python3
"""
UTF-8 validation
"""


def validUTF8(data):
    """UTF-8 validation"""
    s_byts = 0
    for num in data:
        repres = format(num, '#010b')[-8:]
        if s_byts == 0:
            for b in repres:
                if b == '0':
                    break
                s_byts += 1
            if s_byts == 0:
                continue
            if s_byts == 1 or s_byts > 4:
                return False
        else:
            if not (repres[0] == '1' and repres[1] == '0'):
                return False
        s_byts = s_byts - 1
    if s_byts == 0:
        return True
    return False
