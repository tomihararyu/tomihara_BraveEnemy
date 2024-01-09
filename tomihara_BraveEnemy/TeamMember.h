#pragma once
#include"Character.h"
class TeamMember :public Character
{
public:
	TeamMember(const char* name);//コンストラクタでステータスを追加。
public:
	int attack()override;//攻撃
	void HPNPfullset(int hp, int mp);//hpとnpを元に戻す
};