class Base:
    def __init__(self):
        print('base called')


class Child(Base):
    def __init__(self):
        super(Child, self).__init__()
        print('child called')

# super(instance, self) is equal to just calling super().__init__()
# super(child, self) calls the constructor of the base class of child, which is base
class Child2(Child):
    def __init__(self):
        super(Child2, self).__init__() # calls the constructor of super(class, self).__init__()
        print('child2 called')


if __name__ == '__main__':
    node = Child2()
    print(type(node))
