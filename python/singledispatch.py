from functools import singledispatch


@singledispatch
def sd_sum(a, b):
    return a + b


@sd_sum.register
def _(a: int, b: int):
    return a + b + 1


@sd_sum.register
def _(a: float, b: float):
    return a + b - 1


print(sd_sum(int(10), int(10)))
print(sd_sum(float(10), float(10)))
print(sd_sum('hello', 'world'))
