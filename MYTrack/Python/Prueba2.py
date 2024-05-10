class Car:
    def __init__(self, max_speed, units):
        self.max_speed = max_speed
        self.units = units

    def __str__(self):
        return f"Car with the maximum speed of {self.max_speed} {self.units}"


class Boat:
    def __init__(self, max_speed):
        self.max_speed = max_speed

    def __str__(self):
        return f"Boat with the maximum speed of {self.max_speed} knots"


# Example usage:
car1 = Car(120, "km/h")
print(car1)  # Output: Car with the maximum speed of 120 km/h

car2 = Car(94, "mph")
print(car2)  # Output: Car with the maximum speed of 94 mph

boat = Boat(82)
print(boat)  # Output: Boat with the maximum speed of 82 knots
