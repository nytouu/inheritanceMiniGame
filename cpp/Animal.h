#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
	protected:
		std::string name;
		int age = 0;

		int ageMax = 10;
		std::string scream;
		std::string attack;

		int aggr = 1;
		int cute = 1;

		bool alive = true;

	public:
		Animal(std::string name);
		/* Animal(); */
		void setAggr(int newAggr);
		void setCute(int newCute);
		void setAge(int newAge);
		bool isAlive();
		int getAge();
		std::string getName();
		void pet();
		void giveTreat();
		void prompt();

};

class Cat : public Animal {
	private:
		std::string scream = "meows";
		std::string attack = "scratches";

		int ageMax = 12;
	public:
          Cat(std::string name);
};

class Dog : public Animal {
	private:
		std::string scream = "barks";
		std::string attack = "bites";

		int ageMax = 15;
	public:
          Dog(std::string name);
};

class Capybara : public Animal {
	private:
		std::string scream = "growls";
		std::string attack = "bites";

		int ageMax = 11;
	public:
          Capybara(std::string name);
};

#endif
