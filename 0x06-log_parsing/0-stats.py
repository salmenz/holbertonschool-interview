#!/usr/bin/python3
import sys

status = [200, 301, 400, 401, 403, 404, 405, 500]
nb = [0, 0, 0, 0, 0, 0, 0, 0]
i = 0
tot = 0
try:
    for l in sys.stdin:
        i += 1
        x = l.split(" ")
        tot += int(x[-1])
        if int(x[-2]) in status:
            nb[status.index(int(x[-2]))] += 1
        if i % 10 == 0:
            print("File size:", tot)
            for j in range(len(status)):
                if nb[j] != 0:
                    print("{}: {}".format(status[j], nb[j]))
except Exception:
    pass
finally:
    print("File size:", tot)
    for j in range(len(status)):
        if nb[j] != 0:
            print("{}: {}".format(status[j], nb[j]))
            