#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] != NULL) {
			delete _materias[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] == NULL) {
			_materias[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] != NULL && _materias[i]->getType() == type) {
			return _materias[i]->clone();
		}
	}
	return NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._materias[i] != NULL) {
			_materias[i] = other._materias[i]->clone();
		} else {
			_materias[i] = NULL;
		}
	}
}
