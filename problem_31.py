#!/usr/bin/env python3

"""
project euler # 31
how many different ways can £2 be made using any number of coins?
"""

target = 200
coins = [1, 2, 5, 10, 20, 50, 100, 200]
n = [1] + [0] * target

for coin in coins:
    for i in range(coin, target+1):
        n[i] += n[i - coin]

print(n[-1])

