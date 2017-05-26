# project euler #30

def main():
    total = 0
    limit = 1000000 # ???
    for i in range(2, limit):
        tmp_total = 0
        for digit in str(i):
            tmp_total += int(digit)**5
        if tmp_total == i:
            total += tmp_total
    print(total)


if __name__ == "__main__":
    main()
