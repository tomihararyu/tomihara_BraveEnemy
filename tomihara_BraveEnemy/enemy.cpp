#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"enemy.h"
using namespace std;

Enemy::Enemy(const char* name) :Character(name)
{

}
int Enemy::attack()
{
	int move = rand() % skillMAXnum;
	cout << "====================" << endl;
	return (this->*Skillpul[SkillProcess[move]])();;
}