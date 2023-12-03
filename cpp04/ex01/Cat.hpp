#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat
: public Animal
{
	public:
		Cat( void );
		Cat( const Cat & );
		~Cat( void );

		Cat &operator=( const Cat & );

		void setIdeas( const std::string & );
		void printIdeas( void );

		void	makeSound( void ) const;

	private:
		Brain	*_brain;

		void copyBrain( const Cat & );
};

#endif