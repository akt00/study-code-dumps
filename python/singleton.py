from inspect import signature
from functools import reduce
from typing import Generator, Any, Callable
import random


def singleton_generator(method: Callable[[Any, Any], Generator]):
    instances = {}

    def wrapper(*args, **kwargs):
        sig = signature(method)
        bound_args = sig.bind(*args, **kwargs)
        bound_args.apply_defaults()

        self = bound_args.arguments.get('self')
        if self is None:
            raise AttributeError('singleton_generator decorator should only be applied to a class method')

        if self not in instances:
            instances[self] = method(*args, **kwargs)
        return instances[self]

    return wrapper


class HalfLife:
    def __init__(self, half_life: float, amount: float, logging: str = 'log.csv'):
        self._residues = [amount]
        self._half_life = half_life * 10
        self._amount = amount
        self._logging = logging
        self._step_count: int = 0
        with open(self._logging, 'w') as f:
            f.writelines(['timelapse,residue\n', f'0,{self._amount}\n'])

    @singleton_generator
    def get_generator(self) -> Generator:
        while True:
            self._step_count += 1
            residue = reduce(lambda x, y: x + y, self._residues)
            res = yield residue
            if res:
                self._residues.append(float(res))
            if self._step_count % self._half_life == 0:
                self._residues = [_i for _i in map(lambda x: x/2, self._residues)]
            with open(self._logging, 'a') as f:
                f.write(f'{float(self._step_count/10)},{residue}\n')


if __name__ == '__main__':
    hl = HalfLife(22, .5)
    gen = hl.get_generator()
    night = True
    for i in range(1, 30000):
        print(next(gen))
        if i % 120 == 0:
            if night:
                gen.send(.5)
            else:
                if random.randint(0, 1) == 0:
                    gen.send(.5)
