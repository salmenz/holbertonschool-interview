#!/usr/binary/python3
"""
UTF-8 Validator Module
"""


def validUTF8(data):
    nb_bytes = 0
    for i in data:
        binary = format(i, '#010b')[-8:]
        if nb_bytes == 0:
            for bit in binary:
                if bit == "0":
                    break
                nb_bytes += 1

            if nb_bytes == 0:
                continue

            if nb_bytes > 4 or nb_bytes == 1:
                return False
        else:
            if binary[0] != "1" or binary[1] != "0":
                return False

        nb_bytes -= 1

    return nb_bytes == 0
