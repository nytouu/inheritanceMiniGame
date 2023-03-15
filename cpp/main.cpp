#include <iostream>
#include "Animal.cpp"


const char species[3] = {'c', 'd', 'C'};


inline void pause()
{
    std::string dummy;
    std::cout << "Enter to continue..." << std::endl;
    std::getline(std::cin, dummy);
}

int
main()
{
	std::srand((unsigned) time(NULL));

    int choice;
    char specie;
    Animal *animal;
    std::string newName;

    while (true)
    {
        int choice = rand() % 3;
        char specie = species[choice];

        std::cout << "Choose a name for your new pet ! : " << std::endl;
        std::cin >> newName;

        std::cout << newName << " is a " << specie << "!" << std::endl;

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
        #ifdef _WIN32 || _WIN64
            system("cls");
        #elif __linux__
            system("clear");
        #endif

        while (animal->isAlive())
        {
            animal->prompt();

            std::cin.ignore();
            pause();

            system("clear");
            #ifdef _WIN32 || _WIN64
                system("cls");
            #elif __linux__
                system("clear");
            #endif

        }
    }

    return 0;
}
