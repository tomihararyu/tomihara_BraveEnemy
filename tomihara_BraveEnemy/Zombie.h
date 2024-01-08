#pragma once
#include"enemy.h"
class Zombie : public Enemy
{
public:
	Zombie();
	Zombie(const char* name);
	virtual ~Zombie();
};
