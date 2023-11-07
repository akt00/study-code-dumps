class Meta(type):
    def __new__(cls, name, bases, class_dict):
        print(cls.__name__)
        print(name)
        print(bases)
        print(class_dict)

        return type.__new__(cls, name, bases, class_dict)


class Dummy:
    pass


class MyClass(Dummy, metaclass=Meta):
    stuff = 111

    def foo(self):
        print('foo' + str(self.stuff))


mc = MyClass()
