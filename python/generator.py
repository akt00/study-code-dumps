coordinate = (0, 0)


def move_left(steps: int):
    for _ in range(steps):
        global coordinate
        yield -1, 0
        print(f'move left: {coordinate}')


def move_up(steps: int):
    for _ in range(steps):
        global coordinate
        yield 0, 1
        print(f'move up: {coordinate}')


def composite():
    global coordinate
    yield from move_left(5)
    yield from move_up(5)


def run_composite():
    global coordinate
    for g in composite():
        coordinate = (coordinate[0] + g[0], coordinate[1] + g[1])


def count(ceil: int):
    counter = 0
    while counter < ceil:
        res = yield counter
        counter = int(res) if res else counter + 1


def run_count():
    gen = count(100)
    while True:
        try:
            res = next(gen)
            if res == 5:
                print(gen.send(97))
            else:
                print(res)
        except StopIteration:
            break
