#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog() {
	_type = "Dog";
	try {
		_brain = new Brain();
	}
	catch (std::bad_alloc& e) {
		std::cerr << "Failed to allocate memory for Dog's brain: " << e.what() << std::endl;
	}
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return _brain;
}
