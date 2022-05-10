#generator performs lazy evaluation and returns an lazy iterator

def csv_reader(filepath):
    for row in open(filepath, 'r'):
        yield row


def infinite_sequence():
    num = 0
    while True:
        yield num
        num += 1


if __name__ == '__main__':

    ret3 = infinite_sequence()
    for i in ret3:  # performs lazy evaluation when called
        print(i, end=" ")
