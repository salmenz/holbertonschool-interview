#!/usr/bin/python3
"""
UTF-8 validation
"""


def validUTF8(data):
    """
    fn that determines if a given data set represents a valid UTF-8 encoding.
        Prototype: def validUTF8(data)
        Return: True if data is a valid UTF-8 encoding, else return False
        A character in UTF-8 can be 1 to 4 bytes long
        The data set can contain multiple characters
        The data will be represented by a list of integers
        Each integer represents 1 byte of data,
            therefore you only need to handle the 8 least
            significant bits of each integer
    """
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
