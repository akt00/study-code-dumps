import cProfile
print('imported!')

counter = 1000000


def inc1():
    x = 0
    while x != counter:
        x += 1


def inc2():
    def _inc(_x):
        return -~_x

    x = 0
    while x != counter:
        x = _inc(x)


def run():
    pr = cProfile.Profile()
    pr.enable()
    inc1()
    pr.disable()
    pr.enable()
    inc2()
    pr.disable()
    pr.print_stats(sort='calls')
