#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"TeamMember.h"
using namespace std;

TeamMember::TeamMember(const char* name) :Character(name)
{

}
int TeamMember::attack()//�U��
{
	cout << endl;
	cout << _pName << "�̍s����I�����Ă��������B�@>";
	for (int i = 0; i < skillMAXnum; i++)//���O��NP���������Ă���X�L���Ƌ��ɕ\������
	{
		cout << i + 1 << "=" << skillCharNam[SkillProcess[i]] << ":NP=" << skillCharNP[SkillProcess[i]] << "   ";
	}
	for (;;)
	{
		int timp;//�ꎞ�I�Ƀv���C���[�ɓ��͂�����ϐ�
		cout << endl << "cin>>";
		cin >> timp;
		if (timp <= 0)
		{
			cout << "������x���͂��Ă��������B" << endl;
		}
		else if (timp <= skillMAXnum)
		{
			if (state[NP] < skillCharNP[SkillProcess[timp - 1]])//���g�̎����Ă���NP�Ǝg�p�ɂ�����NP���r����
			{
				cout << "NP������܂���B������x���͂��Ă��������B" << endl;
				continue;
			}
			int dm = (this->*Skillpul[SkillProcess[timp - 1]])();//���͂����ԍ��̊֐����Ăяo��//this���ĂȂ񂾂�//�B�������炵��
			return dm;
			break;
		}
		else
		{
			cout << "������x���͂��Ă��������B" << endl;
		}
		cout << "�o�O���N���܂���" << endl;
	}

}
void TeamMember::HPNPfullset(int hp, int np)
{
	state[HP] = hp;
	state[NP] = np;
}