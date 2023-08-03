from concurrent import futures
import time
import asyncio


def sleep1():
    _count = 0
    while _count < 20000000:
        _count += 1
    return 1


def sleep2(msg: str):
    _count = 0
    while _count < 20000000 * 2:
        _count += 1
    return '2 ' + msg


def sleep3():
    _count = 0
    while _count < 20000000 * 3:
        _count += 1
    return 3


if __name__ == '__main__':

    start = time.time()

    tasks = list()
    # with statement waits until all the futures are returned
    with futures.ProcessPoolExecutor() as ex:
        for i in range(50):
            tasks.append(ex.submit(sleep2, 'task ' + str(i)))

        while len(tasks) != 0:
            for idx, i in enumerate(tasks):
                if i.done():
                    print('task done : ', i.result())
                    del tasks[idx]

    dur = time.time() - start
    print('dur', dur)
    try:
        print([i.result(timeout=0) for i in tasks])
    except Exception as e:
        print(e)
