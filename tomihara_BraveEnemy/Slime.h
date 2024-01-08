#pragma once
#include"enemy.h"

class Slime :public Enemy
{
public:
	Slime();
	Slime(const char* name);
	virtual ~Slime();
};