#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

std::string AAnimal::getType() const {
	return _type;
}