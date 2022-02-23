class Base:
    def __init__(self):
        print('base called')


class Child(Base):
    def __init__(self):
        super(Child, self).__init__()
        print('child called')


class Child2(Child):
    def __init__(self):
        super(Child2, self).__init__() # calls the constructor of super(class, self).__init__()
        print('child2 called')


if __name__ == '__main__':
    node = Child2()
    print(type(node))
