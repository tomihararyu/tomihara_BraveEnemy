#pragma once
#include"TeamMember.h"
class Brave :public TeamMember
{
public:
	Brave();
	Brave(const char* name);//コンストラクタでステータスを追加。
	virtual ~Brave();

};