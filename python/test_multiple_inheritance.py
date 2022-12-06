class X:
    def __init__(self):
        print('X constructed')
        self.x = None

    def __str__(self):
        print('X str')
        if self.x is None:
            return 'None'
        else:
            return self.x + ''


class Y:
    def __init__(self):
        print('Y constructed')
        self.y = None

    def __str__(self):
        print('Y str')
        if self.y is None:
            return 'None'
        else:
            return self.y + ''


# super() call the constructor of the first parent
# the first parents' methods override the duplicate methods
class Z(X, Y):
    def __init__(self):
        print('Z constructed')
        X.__init__(self)
        Y.__init__(self)

    def __str__(self):
        return X.__str__(self) + ' ' + Y.__str__(self)


if __name__ == '__main__':

    z = Z()
    print(z)
