#include "Cat.hpp"
#include <iostream>

Cat::Cat() : _brain(new Brain()){ 
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	AAnimal::operator=(other);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

