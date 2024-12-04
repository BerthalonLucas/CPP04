#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AAnimal {
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(const AAnimal& other);
	virtual ~AAnimal();
	AAnimal& operator=(const AAnimal& other);
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif

