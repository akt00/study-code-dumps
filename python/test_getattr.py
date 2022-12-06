# test default member initialization with getattr
# lazy attr evaluation
# item 47

class LazyRecord:
    def __init__(self):
        self.exists = 5

    def __getattr__(self, item):
        value = f'Value for {item}'
        setattr(self, item, value)
        return value


if __name__ == '__main__':
    data = LazyRecord()
    print('before: ', data.__dict__)
    print('foo: ', data.foo)
    print('After: ', data.__dict__)
