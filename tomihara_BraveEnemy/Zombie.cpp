#include <iostream>
#include"Zombie.h"
using namespace std;

Zombie::Zombie() : Enemy("ƒ]ƒ“ƒr")
{

}

Zombie::Zombie(const char* name) : Enemy(name)
{
	state[HP] = (rand() % 11) + 50;
	state[NP] = (rand() % 6) + 5;
	state[POW] = (rand() % 6) + 10;
	state[INT] = (rand() % 4) + 2;
	state[DF] = (rand() % 3) + 5;
	state[DEX] = (rand() % 8) + 25;

	SkillCheck[TAIATARI] = true;
	SkillCheck[HANER] = true;
	SkillCheck[POIZN] = true;
	SkillConstructorLook();
}
Zombie::~Zombie()
{

}