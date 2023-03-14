#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
	protected:
		std::string name;
		int age = 0;

		int ageMax;
		std::string scream;
		std::string attack;

		int aggr;
		int cute;

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

#endif
