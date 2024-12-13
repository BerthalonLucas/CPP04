#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

int main()
{
	// Create a materia source and teach it some spells
	IMateriaSource* materiaSource = new MateriaSource();
	materiaSource->learnMateria(new Ice());
	materiaSource->learnMateria(new Cure());

	// Create the hero character
	ICharacter* hero = new Character("Hero");

	// Hero equips spells from the materia source
	AMateria* iceSpell = materiaSource->createMateria("ice");
	hero->equip(iceSpell);

	AMateria* cureSpell = materiaSource->createMateria("cure");
	hero->equip(cureSpell);

	// Create the villain character
	ICharacter* villain = new Character("Villain");

	// Hero uses spells against the villain
	hero->use(0, *villain); // Uses ice spell
	hero->use(1, *villain); // Uses cure spell

	// Attempt to use unequipped slots
	hero->use(2, *villain);
	hero->use(10, *villain);
	hero->use(-5, *villain);

	// Hero unequips a spell and tries to use it
	hero->unequip(0);
	hero->use(0, *villain);

	// Clean up
	hero->unequip(1);
	hero->use(1, *villain);

	delete villain;
	delete hero;
	delete materiaSource;
	delete iceSpell;
	delete cureSpell;

	return 0;
}