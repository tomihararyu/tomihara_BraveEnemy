#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"TeamMember.h"
using namespace std;

TeamMember::TeamMember(const char* name) :Character(name)
{

}
int TeamMember::attack()
{
	cout << endl;
	cout << _pName << "�̍s����I�����Ă��������B�@>";
	for (int i = 0; i < skillMAXnum; i++)
	{
		cout << i + 1 << "=" << skillCharNam[SkillProcess[i]] << ":NP=" << skillCharNP[SkillProcess[i]] << "   ";
	}
	int timp;
	for (;;)
	{
		cout << endl << "cin>>";
		cin >> timp;
		if (timp <= 0)
		{
			cout << "������x���͂��Ă��������B" << endl;
		}
		else if (timp <= skillMAXnum)
		{
			if (state[NP] < skillCharNP[SkillProcess[timp - 1]])
			{
				cout << "NP������܂���B������x���͂��Ă��������B" << endl;
				continue;
			}
			break;
		}
		else
		{
			cout << "������x���͂��Ă��������B" << endl;
		}
	}
	int dm = (this->*Skillpul[SkillProcess[timp - 1]])();//this���ĂȂ񂾂�//�B�������炵��
	return dm;
}