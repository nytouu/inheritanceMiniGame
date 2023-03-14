from random import randint, choice
from os import system

class Animal:

    def __init__(self, name) -> None:
        self.name = name
        self.age = 0

        self.ageMax = -1
        self.cri = None
        self.attack = None

        self.aggr = 0
        self.cute = 0

        self.alive = True

        print(f"You adopted {self.name} !")

    def setAggr(self, newAggr):
        diff = newAggr - self.aggr
        prefix = "+" if diff > 0 else ""

        self.aggr = newAggr
        print(f"{prefix}{diff} aggressivity points ({self.aggr})")

    def setCute(self, newCute):
        diff = newCute - self.cute
        prefix = "+" if diff > 0 else ""

        self.cute = newCute
        print(f"{prefix}{diff} cuteness points ({self.cute})")

    def setAge(self, newAge):
        self.age = newAge
        if self.age > self.ageMax:
            self.alive = False

        if self.alive:
            print(f"{self.name} is {self.age} years old !")
        else:
            print(f"{self.name} died :(")

    def isAlive(self):
        return self.alive

    def getAge(self):
        return self.age

    def getName(self):
        return self.name

    def pet(self):
        rand = randint(1,5)
        if rand >= 3:
            print(f"{self.name} {self.cri}!")
            self.setCute(self.cute + 1)
        else:
            print(f"{self.name} {self.attack} you !")
            self.setAggr(self.aggr + 1)

    def giveTreat(self):
        rand = randint(1,5)
        if rand >= 2:
            print(f"{self.name} {self.cri}!")
            self.setCute(self.cute + 1)
        else:
            print(f"{self.name} {self.attack} you !")
            self.setAggr(self.aggr + 1)

    def prompt(self):
        print(f"{self.name} wants you to do something !")
        choice = input("What will you do ? : (p)et, give (t)reat")

        if choice.lower() == "p":
            self.setAge(self.age + 1)
            self.pet()
        if choice.lower() == "t":
            self.setAge(self.age + 1)
            self.giveTreat()


class Cat(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)

        self.cri = "meows"
        self.attack = "scratches"

        self.ageMax = 12


class Dog(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)

        self.cri = "barks"
        self.attack = "bites"

        self.ageMax = 15


class Capybara(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)

        self.cri = "growls"
        self.attack = "bites"

        self.ageMax = 11


def main():
    while True:
        newName = input("Insert name for pet : ")
        specie = choice(["cat", "dog", "capybara"])

        match specie:
            case "cat":
                animal = Cat(newName)
            case "dog":
                animal = Dog(newName)
            case "capybara":
                animal = Capybara(newName)
            case _:
                animal = Cat(newName)

        while animal.isAlive():
            system("clear")

            animal.prompt()
            input()


if __name__ == "__main__":
    main()
