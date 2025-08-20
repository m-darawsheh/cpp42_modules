#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* ZOMBIES = new Zombie[N];
	for (int i = 0; i < N; i++)
		ZOMBIES [i].setName(name);
	return ZOMBIES ;
}
