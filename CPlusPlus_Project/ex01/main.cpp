#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Basic Animal Tests ===" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		
		std::cout << dog->getType() << " says: ";
		dog->makeSound();
		std::cout << cat->getType() << " says: ";
		cat->makeSound();
		std::cout << meta->getType() << " says: ";
		meta->makeSound();
		
		delete meta;
		delete dog;
		delete cat;
	}
	
	std::cout << "\n=== Wrong Animal Tests ===" << std::endl;
	{
		const WrongAnimal* wrong = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		
		std::cout << wrong->getType() << " says: ";
		wrong->makeSound();
		std::cout << wrongCat->getType() << " says: ";
		wrongCat->makeSound();
		
		delete wrong;
		delete wrongCat;
	}
	
	std::cout << "\n=== Brain Tests ===" << std::endl;
	{
		Dog* dog1 = new Dog();
		dog1->getBrain()->setIdea(0, "I want to play!");
		dog1->getBrain()->setIdea(1, "I love bones!");
		
		Dog* dog2 = new Dog(*dog1);
		delete dog1;
		
		std::cout << "Dog2's first idea: " << dog2->getBrain()->getIdea(0) << std::endl;
		std::cout << "Dog2's second idea: " << dog2->getBrain()->getIdea(1) << std::endl;
		
		delete dog2;
	}
	
	std::cout << "\n=== Array of Animals ===" << std::endl;
	{
		const int numAnimals = 4;
		Animal* animals[numAnimals];
		
		for(int i = 0; i < numAnimals/2; i++) {
			animals[i] = new Dog();
		}
		for(int i = numAnimals/2; i < numAnimals; i++) {
			animals[i] = new Cat();
		}
		
		// Make them all sound off
		for(int i = 0; i < numAnimals; i++) {
			std::cout << animals[i]->getType() << " says: ";
			animals[i]->makeSound();
		}
		
		for(int i = 0; i < numAnimals; i++) {
			delete animals[i];
		}
	}
	
	return 0;
}