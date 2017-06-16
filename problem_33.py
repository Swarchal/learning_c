#!/usr/bin/env python3
""" project euler problem 33 """

def split_num(num):
    return [int(i) for i in str(num)]


def is_trivial(a, b):
    return a % 10 == 0 or b % 10 == 0


def rm_digit(l, digit):
    """remove digit from list"""
    out = [i for i in l if i is not digit]
    # don't want to remove both digits e.g removing 2 from [2, 2]
    if len(out) == 0:
        return digit
    else:
        return out[0]


def remove_common_digit(a, b):
    """
    remove common digit between two numbers, otherwise return nothing
    e.g
        >>>  remove_common_digit(12, 25)
        out: (1, 5)
    """
    a_split, b_split = split_num(a), split_num(b)
    if is_trivial(a, b) or a >= b:
        return None
    for i in a_split:
        if i in b_split:
            return rm_digit(a_split, i), rm_digit(b_split, i)


def main():
    fractions = []
    for numer in range(10, 99):
        for denom in range(11, 100):
            try:
                numer_rm, denum_rm = remove_common_digit(numer, denom)
                if numer_rm / denum_rm == numer / denom:
                    print(numer_rm, "/", denum_rm, "\t", numer, "/", denom)
            except TypeError:
                pass # trying to unpack a None return value


if __name__ == "__main__":
    main()

"""
output:

    1 / 4    16 / 64
    1 / 5    19 / 95
    2 / 5    26 / 65
    4 / 8    49 / 98
"""

