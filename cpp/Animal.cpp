#ifndef ANIMAL_CPP
#define ANIMAL_CPP

#include "Animal.h"
#include <stdlib.h>
#include <iostream>
#include <string>

Animal::Animal(std::string newName) {
	name = newName;
}

Cat::Cat(std::string newName) : Animal(newName) {};

void
Animal::setAggr(int newAggr)
{
	int diff;
	char prefix;

	diff = newAggr - aggr;
	diff < 0 ? prefix = ' ' : prefix = '+';

	aggr = newAggr;
	std::cout << prefix << diff << " aggressivity points (" << aggr << ")" << std::endl;
}

void
Animal::setCute(int newCute)
{
	int diff;
	char prefix;

	diff = newCute - cute;
	diff < 0 ? prefix = ' ' : prefix = '+';

	cute = newCute;
	std::cout << prefix << diff << " cuteness points (" << cute << ")" << std::endl;
}

void
Animal::setAge(int newAge)
{
	age = newAge;

	if (age > ageMax)
		alive = false;

	if (alive)
		std::cout << name << " is " << age << " years old !" << std::endl;
	else
		std::cout << name << " died ! :(" << std::endl;

}

bool
Animal::isAlive()
{
	return alive;
}

int
Animal::getAge()
{
	return age;
}

std::string
Animal::getName()
{
	return name;
}

void
Animal::pet()
{
	int random = rand() % 5 + 1;

	if (random >= 3)
	{
		std::cout << name << " " << scream << " !" << std::endl;
		setCute(cute + 1);
	}
	else
	{
		std::cout << name << " " << attack << " you !" << std::endl;
		setAggr(aggr + 1);
	}
}

void
Animal::giveTreat()
{
	int random = rand() % 5 + 1;

	if (random >= 2)
	{
		std::cout << name << " " << scream << " !" << std::endl;
		setCute(cute + 1);
	}
	else
	{
		std::cout << name << " " << attack << " you !" << std::endl;
		setAggr(aggr + 1);
	}
}

void
Animal::prompt()
{
	char choice;

	std::cout << name << " wants you to do somehting !" << std::endl;
	std::cout << "What will you do ? : (p)et, give (t)reat - " << std::endl;

	std::cin >> choice;

	switch(choice)
	{
		case 'p':
			setAge(age + 1);
			pet();
			break;
		case 't':
			setAge(age + 1);
			giveTreat();
			break;
		default:
			std::cout << "Invalid input" << std::endl;
			break;
	}
}

#endif
