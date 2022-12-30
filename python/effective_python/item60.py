from concurrent.futures import ThreadPoolExecutor
import time
import asyncio


async def do_some_io():
    time.sleep(1)
    return "input received"


async def async_logic():
    return await do_some_io()


async def simulate():
    tasks = []
    for i in range(5):
        task = do_some_io()
        print('task run')
        tasks.append(task)

    await asyncio.gather(*tasks)


if __name__ == '__main__':
    start = time.time()
    asyncio.run(simulate())
    dur = time.time() - start
    print(dur)

