def my_decorator(func):
    def wrapper():
        print("Something is happening before the function is called.")
        func()
        print("Something is happening after the function is called.")
    return wrapper


@my_decorator
def say_whee():
    print("Whee!")


def base(func):
    def wrapper(x):
        ret = func(x)
        return ret ** 2 + 1
    return wrapper


@base
def calc(x):
    return x ** 2


if __name__ == '__main__':

    say_whee()
    print(calc(2))

