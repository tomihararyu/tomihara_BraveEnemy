#pragma once
#include"Character.h"
class TeamMember :public Character
{
public:
	TeamMember(const char* name);//�R���X�g���N�^�ŃX�e�[�^�X��ǉ��B
public:
	int attack()override;//�U��
	void HPNPfullset(int hp, int mp);//hp��np�����ɖ߂�
};