# private members
# item 42

class MyObj:
    def __init__(self):
        self.public_field = 5
        self.__private_field = 10

    def get_private_field(self):
        return self.__private_field


if __name__ == '__main__':
    obj = MyObj()
    obj.__private_field = 100
    print(obj.get_private_field())
