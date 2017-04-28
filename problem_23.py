# Project euler # 23 - Non-abundant sums
#
# A perfect number is a number for which the sum of its proper divisors is
# exactly equal to the number. For example, the sum of the proper divisors of
# 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect
# number.
#
# A number n is called deficient if the sum of its proper divisors is less
# than n and it is called abundant if this sum exceeds n.
#
# As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
# number that can be written as the sum of two abundant numbers is 24. By
# mathematical analysis, it can be shown that all integers greater than 28123
# can be written as the sum of two abundant numbers. However, this upper limit
# cannot be reduced any further by analysis even though it is known that the
# greatest number that cannot be expressed as the sum of two abundant numbers
# is less than this limit.
#
# Find the sum of all the positive integers which cannot be written as the sum
# of two abundant numbers.

from itertools import product

def sum_proper_divisors(n):
        return sum(i for i in range(1, n) if n % i == 0)


def is_abundant(n):
    return sum_proper_divisors(n) > n


def get_abundant_nums(limit):
    abundant_nums = set()
    for i in range(1, limit // 2 + 1):
        if is_abundant(i):
            abundant_nums.add(i)
    return list(abundant_nums)


def not_sum_of_two_abun(n):
    for pair in all_pairs:
        if sum(pair) == n:
            return False
    return True



if __name__ == "__main__":

    N = 28123
    abundant_nums = get_abundant_nums(N)
    all_pairs = product(abundant_nums, repeat=2)
    all_not_sum_of_two_abun = []
    for i in range(1, N):
        if not_sum_of_two_abun(i):
            all_not_sum_of_two_abun.append(i)
    print(sum(all_not_sum_of_two_abun))

