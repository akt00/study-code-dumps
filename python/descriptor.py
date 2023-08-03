# __set_name__
# item50

class Field:  # descriptor
    def __init__(self, name):
        self.name = name
        self.internal_name = '_' + self.name

    def __get__(self, instance, instance_type):
        if instance is None:
            return self
        return getattr(instance, self.internal_name, '')  # default value ''

    def __set__(self, instance, value):
        setattr(instance, self.internal_name, value)


class Customer:
    first_name = Field('first_name')
    last_name = Field('last_name')
    prefix = Field('prefix')
    suffix = Field('suffix')


class BetterField:  # descriptor
    def __init__(self):
        self.name = None
        self.internal_name = None

    # automatically sets the name for the attribute
    def __set_name__(self, owner, name):
        self.name = name
        self.internal_name = '_' + name

    def __get__(self, instance, instance_type):
        if instance is None:
            return self
        return getattr(instance, self.internal_name, '')  # default value ''

    def __set__(self, instance, value):
        setattr(instance, self.internal_name, value)


class BetterCustomer:  # no need to specify the field
    first_name = BetterField()
    last_name = BetterField()
    prefix = BetterField()
    suffix = BetterField()


if __name__ == '__main__':
    cust = Customer()
    print(cust.__dict__)
    cust.first_name = 'Sophia'
    print(cust.__dict__)

    b_cust = BetterCustomer()
    print(b_cust.__dict__)
    b_cust.first_name = 'lily'
    print(b_cust.__dict__)
