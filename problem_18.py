# project euler # 18
#
# By starting at the top of the triangle below and moving to adjacent numbers on
# the row below, the maximum total from top to bottom is 23.
#
#    3
#   7 4
#  2 4 6
# 8 5 9 3
#
# That is, 3 + 7 + 4 + 9 = 23.
# Find the maximum total from top to bottom of the triangle given.

# code golf!
print reduce(lambda n, m: [max(n[i:i+2]) + m[i] for i in range(len(n) - 1)],
             [map(int, line.split(" ")) for line in open("data_18.txt")][::-1])
