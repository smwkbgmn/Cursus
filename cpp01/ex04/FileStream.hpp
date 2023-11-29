#ifndef FILESTREAM_HPP
# define FILESTREAM_HPP

# include <string>
# include <fstream>

typedef std::string	str_t;

class FileStream
{
	public:
		FileStream( const str_t & );
		~FileStream( void );

		std::ifstream	is;
		std::ofstream	os;

	private:
};

#endif