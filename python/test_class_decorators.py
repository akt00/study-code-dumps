#  inheritance
#  classmethod
#  item 39

class Worker:
    def __init__(self, input_data):
        self.input_data = input_data
        self.result = None

    def map(self):
        raise NotImplementedError

    def reduce(self, other):
        raise NotImplementedError


class LineCountWorker(Worker):
    def map(self):
        data = self.input_data.read()
        self.result = data.count('\n')

    def reduce(self, other):
        self.result += other.result


class Person:
    def __init__(self, name: str, age: int):
        self.name = name
        self.age = age

    @classmethod
    def create_person(cls, name, age):
        raise NotImplementedError


class Worker(Person):
    def __init__(self, name, age, profession):
        super().__init__(name, age)
        self.profession = profession

    #  creates a Worker class instance
    @classmethod
    def create_person(cls, name, age):
        return cls(name, age, None)

    #  static method
    @staticmethod
    def create_worker(name, age, profession):
        return Worker(name, age, profession)


if __name__ == '__main__':
    worker1 = Worker('john', 22, 'programmer')
    if isinstance(worker1, Worker):
        print('worker1 is Worker object', worker1)
    worker2 = Worker.create_person('Alice', 24)
    if isinstance(worker2, Worker):
        print('worker2 is Worker object', worker2)
    worker3 = Worker.create_worker('Sophia', 26, 'Model')
    if isinstance(worker3, Worker):
        print('worker3 is Worker object', worker3)
