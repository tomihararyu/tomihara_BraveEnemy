#include <iostream>
#include"brave.h"
using namespace std;

Brave::Brave() : TeamMember("—EŽÒ")
{

}
Brave::Brave(const char* name) : TeamMember(name)
{
	state[HP] = 60 + rand() % 5;
	state[NP] = 19;
	state[POW] = 15;
	state[INT] = 12;
	state[DF] = 11;
	state[DEX] = 32 + rand() % 2;

	SkillCheck[TAIATARI] = true;
	SkillCheck[HOIM] = true;
	SkillCheck[DEIN] = true;

	SkillConstructorLook();
}
Brave::~Brave()
{

}