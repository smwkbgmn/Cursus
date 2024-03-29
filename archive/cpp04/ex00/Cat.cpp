#include <iostream>

#include "Cat.hpp"

Cat::Cat( void )
{
	_type = "Cat";

	std::cout << "[CON_DEF] Cat created" << std::endl;
}

Cat::Cat( const Cat &target )
: Animal()
{
	*this = target;

	std::cout << "[CON_CPY] Cat created" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "[DES] Cat destroyed" << std::endl;
}

Cat &Cat::operator=( const Cat &target )
{
	std::cout << "[Cat's copy assignment called]" << std::endl;

	if (this != &target )
		_type = target.getType();
	
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "Nyaong............." << std::endl;
}
