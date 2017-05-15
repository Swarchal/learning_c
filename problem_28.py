#! /usr/bin/env python3
# project euler #28

def make_corner_seq(n):
    """sequence of length n of corner numbers"""
    seq = [1]
    step_size = 2
    while len(seq) < n:
        for i in range(4):
            seq.append(seq[-1] + step_size)
        step_size += 2
    return seq


def main():
    seq  = make_corner_seq(2 * 1001 - 1)
    print(sum(seq))


if __name__ == "__main__":
    main()
