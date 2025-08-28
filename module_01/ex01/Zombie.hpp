#ifndef ZOMBIE_HBB
 #define ZOMBIE_HBB

#include <string>
#include <iostream>

class Zombie
{
	private:
	std::string name;
	public:
	void announce( void );
	Zombie();
	void setName(std::string name);
	~Zombie();
};




Zombie* zombieHorde( int N, std::string name );

#endif
