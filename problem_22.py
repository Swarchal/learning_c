# project euler # 22

def get_names(url):
    """return sorted list of names"""
    raw = open(url).read()
    names_list = raw.split(",")
    return sorted([i[1:-1] for i in names_list])


def char_to_int(letter):
    return ord(letter.lower()) - 96 # don't ask


def score_name(name):
    score = 0
    for char in name:
        score += char_to_int(char)
    return score


total = 0
names = get_names("names.txt")
for index, name in enumerate(names, 1):
    total += index * score_name(name)

print(total)

