#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& other) {
	if (this != &other)
		*this = other;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}