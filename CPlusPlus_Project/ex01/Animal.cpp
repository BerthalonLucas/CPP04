#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Some generic animal sound" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}