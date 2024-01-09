#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"enemy.h"
using namespace std;

Enemy::Enemy(const char* name) :Character(name)
{

}
int Enemy::attack()//攻撃
{
	int move = rand() % skillMAXnum;//持っているスキルの番号を疑似乱数で選ばせる
	cout << "====================" << endl;
	return (this->*Skillpul[SkillProcess[move]])();//返り値を返り値に入れる//メンバ関数ポインタで関数を呼び出す
}