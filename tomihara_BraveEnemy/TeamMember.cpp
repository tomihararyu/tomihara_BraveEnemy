#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"TeamMember.h"
using namespace std;

TeamMember::TeamMember(const char* name) :Character(name)
{

}
int TeamMember::attack()//攻撃
{
	cout << endl;
	cout << _pName << "の行動を選択してください。　>";
	for (int i = 0; i < skillMAXnum; i++)//名前とNPを所持しているスキルと共に表示する
	{
		cout << i + 1 << "=" << skillCharNam[SkillProcess[i]] << ":NP=" << skillCharNP[SkillProcess[i]] << "   ";
	}
	for (;;)
	{
		int timp;//一時的にプレイヤーに入力させる変数
		cout << endl << "cin>>";
		cin >> timp;
		if (timp <= 0)
		{
			cout << "もう一度入力してください。" << endl;
		}
		else if (timp <= skillMAXnum)
		{
			if (state[NP] < skillCharNP[SkillProcess[timp - 1]])//自身の持っているNPと使用にかかるNPを比較する
			{
				cout << "NPが足りません。もう一度入力してください。" << endl;
				continue;
			}
			int dm = (this->*Skillpul[SkillProcess[timp - 1]])();//入力した番号の関数を呼び出す//thisってなんだよ//隠し引数らしい
			return dm;
			break;
		}
		else
		{
			cout << "もう一度入力してください。" << endl;
		}
		cout << "バグが起きました" << endl;
	}

}
void TeamMember::HPNPfullset(int hp, int np)
{
	state[HP] = hp;
	state[NP] = np;
}