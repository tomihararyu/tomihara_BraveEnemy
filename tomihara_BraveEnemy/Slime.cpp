#include <iostream>
#include"Slime.h"
using namespace std;

Slime::Slime() : Enemy("ƒXƒ‰ƒCƒ€")
{

}

Slime::Slime(const char* name) : Enemy(name)
{
	state[HP] = (rand() % 11) + 20;
	state[NP] = (rand() % 6) + 5;
	state[POW] = (rand() % 6) + 10;
	state[INT] = (rand() % 4) + 2;
	state[DF] = (rand() % 3) + 5;
	state[DEX] = (rand() % 5) + 31;

	SkillCheck[TAIATARI] = true;
	SkillCheck[HANER] = true;
	SkillCheck[POIZN] = true;
	SkillConstructorLook();
}
Slime::~Slime()
{

}