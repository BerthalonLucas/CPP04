#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	WrongAnimal::operator=(other);
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow?!" << std::endl;
}

