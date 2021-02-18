#!/usr/bin/python3
"""
UTF-8 Validator Module
"""


def validUTF8(data):
    num_bytes = 0
    for integer in data:
        bin = format(integer, '#010b')[-8:]
        print (bin)
        if num_bytes == 0:
            for bit in bin:
                if bit == "0":
                    break
                num_bytes += 1

            if num_bytes == 0:
                continue

            if num_bytes > 4 or num_bytes == 1:
                return False
        else:
            if bin[0] != "1" or bin[1] != "0":
                return False

        num_bytes -= 1

    return num_bytes == 0
