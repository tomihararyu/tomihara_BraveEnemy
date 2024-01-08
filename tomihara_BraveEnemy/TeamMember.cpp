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
	cout << _pName << "の行動を選択してください。　>";
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
			cout << "もう一度入力してください。" << endl;
		}
		else if (timp <= skillMAXnum)
		{
			if (state[NP] < skillCharNP[SkillProcess[timp - 1]])
			{
				cout << "NPが足りません。もう一度入力してください。" << endl;
				continue;
			}
			break;
		}
		else
		{
			cout << "もう一度入力してください。" << endl;
		}
	}
	int dm = (this->*Skillpul[SkillProcess[timp - 1]])();//thisってなんだよ//隠し引数らしい
	return dm;
}