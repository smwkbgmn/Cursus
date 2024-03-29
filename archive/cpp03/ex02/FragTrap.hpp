#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( const str_t & );
		FragTrap( const FragTrap & );
		~FragTrap( void );

		FragTrap	&operator=( const FragTrap & );

		void	highFivesGuys( void );

	private:
		void	initAttr( void );
		void	printName( void );
};

#endif