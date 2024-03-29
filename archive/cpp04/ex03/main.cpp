#include <new>

#include "Floor.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void	subject( void );
void	newline( void );

int main( void )
{
	// subject();

	IMateriaSource	*src = new MateriaSource;

	newline();

	src->learnMateria( new Ice );
	src->learnMateria( new Cure );

	newline();

	ICharacter	*pete( new Character( "Pete" ) );
	ICharacter	*pete_cpy( new Character( *(Character *)pete ) );
	ICharacter	*harry( new Character( "Harry" ) );
	ICharacter	*harry_cpy( new Character( *(Character *)harry ));

	newline();

	pete->equip( src->createMateria( "ice" ) );
	pete_cpy->equip( src->createMateria( "cure" ) );

	pete->use( 0, *harry ); // Use Ice
	pete_cpy->use( 0, *harry ); // Use Cure

	pete_cpy->unequip( 0 );
	pete_cpy->use( 0, *harry ); // print nothing

	harry->use( 0, *pete ); // Print nothing 
	harry_cpy->use( 0, *pete ); // print nothing

	newline();

	harry->equip( src->createMateria( "cure" ) );
	harry_cpy->equip( src->createMateria( "ice" ) );

	harry->use( 0, *pete ); // Use Cure
	harry_cpy->use( 0, *pete ); // Use Ice

	newline();

	*(Character *)harry_cpy = *(Character *)harry;
	// harry_cpy has owned the Ice at inventory[0] and this just destroyed by deep copying
	harry_cpy->equip( src->createMateria( "ice" ) );

	harry_cpy->use( 0, *pete ); // Use Cure
	harry_cpy->use( 1, *pete ); // Use Ice

	newline();

	delete src;
	delete pete;
	delete pete_cpy;
	delete harry;
	delete harry_cpy;
}

void subject( void )
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void newline( void )
{
	std::cout << '\n';
}
