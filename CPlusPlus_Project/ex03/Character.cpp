#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character() : _name("default") {
	for (int i = 0; i < 4; i++) {
		_materias[i] = NULL;
	}
}

Character::Character(std::string const& name) : _name(name) {
	for (int i  = 0; i < 4; i++) {
		_materias[i] = NULL;
	}
}

Character::Character(const Character& other) {
	_name = other._name;
	for (int i = 0; i < 4; i++) {
		if (other._materias[i] != NULL) {
			_materias[i] = other._materias[i]->clone();
		} else {
			_materias[i] = NULL;
		}
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] != NULL) {
			delete _materias[i];
		}
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (_materias[i] != NULL) {
				delete _materias[i];
			}
			_materias[i] = NULL;
		}
		for (int i = 0; i < 4; i++) {
			if (other._materias[i] != NULL) {
				_materias[i] = other._materias[i]->clone();
			}
			else
				_materias[i] = NULL;
		}
	}
	return *this;
}

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] == NULL) {
			_materias[i] = m;
			break;
		}
	}
	if (m == NULL) {
		std::cout << "Materia is NULL" << std::endl;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		_materias[idx] = NULL;
	}
	if (idx < 0)
		std::cout << "Index must be greater than 0" << std::endl;
	if (idx >= 4)
		std::cout << "Index must be less than 4" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4) {
		if (_materias[idx] != NULL) {
			_materias[idx]->use(target);
		}
		else
			std::cout << "No materia at this index" << std::endl;
	}
	if (idx < 0)
		std::cout << "Index must be greater than 0" << std::endl;
	if (idx >= 4)
		std::cout << "Index must be less than 4" << std::endl;
}