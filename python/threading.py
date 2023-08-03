import threading
import time


def system_sleep():
    time.sleep(1.)


# takes about 0.95
def brute_sleep():
    _count = 0
    while _count < 20000000:
        _count += 1


def sequential_run():
    for _ in range(5):
        system_sleep()


def parallel_run():
    """
    time.sleep() invokes a system call. it does not get affected by the GIL limitation
    brute_sleep() does not benefit from multi-threading in Python
    """
    threads = []
    for _ in range(5):
        thread = threading.Thread(target=system_sleep())
        thread.start()
        threads.append(thread)

    for i in threads:
        i.join()


if __name__ == '__main__':
    start = time.monotonic()
    parallel_run()
    dur = time.monotonic() - start
    print(dur)
