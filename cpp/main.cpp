#include <iostream>
#include "Animal.cpp"

int
main()
{
	std::srand((unsigned) time(NULL));

    int choice;
    char specie;
    Animal *animal;
    std::string newName;
    char species[3] = {'c', 'd', 'C'};

    for(;;)
    {
        int choice = rand() % 3;
        char specie = species[choice];

        std::cout << specie << std::endl;

        switch(specie)
        {
            case 'c':
                animal = new Cat(newName);
                break;
            case 'd':
                animal = new Cat(newName);
                break;
            case 'C':
                animal = new Cat(newName);
                break;

            default:
                std::cout << "Invalid type" << std::endl;
        }

        while (animal->isAlive())
        {
            /* system("clear"); */

            animal->prompt();
        }

        break;
    }

    return 0;
}
