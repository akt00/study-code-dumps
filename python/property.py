# getter/setter decorator
# item 44

class Celsius:
    def __init__(self, temp=0):
        self.__temperature = temp  # hide with private member

    def to_fahrenheit(self):
        return (self.__temperature*1.8) + 32

    @property  # custom getter
    def temperature(self):
        return self.__temperature

    @temperature.setter  # custom setter
    def temperature(self, value):
        if value < -273.15:
            raise ValueError("Invalid temperature")
        self.__temperature = value


deg = Celsius()
deg.temperature = 200
print(deg.temperature)
