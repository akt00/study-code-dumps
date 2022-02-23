def smart_divide(func):
    def inner(a, b):
        print("I am going to divide", a, "and", b)
        if b == 0:
            print("Whoops! cannot divide")
            return

        return func(a, b)
    return inner


@smart_divide
def divide(a, b):
    print(a/b)


def test_args(*args):
    print(args)


if __name__ == "__main__":
    test_args("hello", "world", "from")

    divide(10, 0)
