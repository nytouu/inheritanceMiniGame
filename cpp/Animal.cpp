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
	std::cout << prefix << diff << " aggressivity points" << std::endl;
}

void
Animal::setCute(int newCute)
{
	int diff;
	char prefix;

	diff = newCute - cute;
	diff < 0 ? prefix = ' ' : prefix = '+';

	cute = newCute;
	std::cout << prefix << diff << " cuteness points" << std::endl;
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
		std::cout << name << "died ! :(" << std::endl;

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
	std::cout << random << std::endl;

	if (random >= 3)
	{
		std::cout << name << scream << std::endl;
		setCute(cute++);
	}
	else
	{
		std::cout << name << attack << " you !" << std::endl;
		setAggr(aggr++);
	}
}

void
Animal::giveTreat()
{
	int random = rand() % 5 + 1;

	if (random >= 2)
	{
		std::cout << name << scream << std::endl;
		setCute(cute++);
	}
	else
	{
		std::cout << name << attack << " you !" << std::endl;
		setAggr(aggr++);
	}
}

void
Animal::prompt()
{
	char choice;

	std::cout << name << " wants you to do somehting !" << std::endl;
	std::cout << "What will you do ? : (p)et, give (t)reat - ";
	std::cin >> choice;

	switch(choice)
	{
		case 'p':
			setAge(age++);
			pet();
		case 't':
			setAge(age++);
			giveTreat();
		default:
			std::cout << "Invalid input" << std::endl;
	}
}

#endif
