#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <windows.h>

#include"Character.h"
using namespace std;


Character::Character(const char* pName) {//コンストラクタ
	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);

	Skillpul[TAIATARI] = &Character::taiatari;
	Skillpul[HOIM] = &Character::hoimi;
	Skillpul[HANER] = &Character::haner;
	Skillpul[POIZN] = &Character::poison;
	Skillpul[DEIN] = &Character::dein;

	SkillProcess = new int[1];//スキルを数える際に毎回新しくdeleteする為一時的にnew
}
Character::~Character()//デストラクタ
{
	if (_pName != nullptr)
	{
		delete _pName;
		_pName = nullptr;
	}
	if (SkillProcess != nullptr)
	{
		delete SkillProcess;
		SkillProcess = nullptr;
	}
}
void Character::SkillConstructorLook()//所持しているスキルの番号を配列に入れる
{
	if (SkillProcess != nullptr)//毎回呼び出す度にスキルをdelete
	{
		delete SkillProcess;
		SkillProcess = nullptr;
	}

	int timp = 0;//所持しているスキルの数を数える
	for (int i = 0; i < SKILLNUM; i++)//スキルの数回繰り返す
	{
		if (SkillCheck[i] == true)//コンストラクタでtrueにしたスキルを数える
		{
			timp++;
		}
	}

	skillMAXnum = timp;//結果を代入

	SkillProcess = new int[skillMAXnum];//所持しているスキルの数分動的に確保
	int j = 0;
	for (int i = 0; i < SKILLNUM; i++)//スキルの数回繰り返す
	{
		if (SkillCheck[i] == true)//trueだったら
		{
			SkillProcess[j] = i;//変数に入れる
			j++;
		}
	}
}
const char* Character::getName()//名前を返す関数
{
	return _pName;
}
int Character::attack()//継承先で使う仮想関数
{
	cout << "親" << endl;
	return 0;
}
void Character::DamageTrade(int Damege)//引数でダメージを持ってきてダメージからDF分引いてHPを減らす
{
	if (Damege != 0)//ダメージが0以外だったら
	{
		int timp = (Damege - state[DF]) + rand() % 3;//多少ダメージをランダムに
		if (timp <= 0)//いらなそう
		{
			timp = 0;
		}

		if (state[HP] - timp <= 0)//ダメージがHPを超過しないようにする処理
		{
			state[HP] = 0;
		}
		else//普通にHPから引く
		{
			state[HP] -= timp;
		}

		if (state[HP] != 0)//表示
		{
			cout << timp << " ダメージ!!  " << _pName << "のHPが" << state[HP] << "になった" << endl;
		}
		else
		{

		}

	}

}
int Character::SpeedCheck()
{
	if (state[NP] < 0)//HPがマイナスにならないようにする処理 //後で関数化する
	{
		state[NP] = 0;
	}
	return state[DEX];
}
int Character::taiatari()//体当たり
{
	cout << _pName << "の体当たり!! 衝撃で" << _pName << "のHPが" << 2 << "減った\n" << endl;
	state[HP] -= 2;
	return 6 + state[POW];

}
int Character::hoimi()//ホイミ
{
	state[HP] += 2 * state[INT] / 10;
	state[NP] -= skillCharNP[HOIM];
	cout << _pName << "の回復!!" << endl;
	cout << _pName << "の" << stateNam[HP] << "が" << 2 * state[INT] / 10 << "回復した" << endl;
	return 0;
}
int Character::haner()//跳ねる
{
	cout << _pName << "の跳ねる!!" << endl;

	cout << _pName << "は元気に跳ねている!!!" << endl;
	return 0;
}
int Character::poison()//毒
{
	cout << _pName << "の毒霧!!\n毒霧を吐いた" << endl;
	state[NP] -= skillCharNP[POIZN];
	return 23;
}
int Character::dein()//デイン
{
	cout << _pName << "のデイン!!" << endl;
	state[NP] -= skillCharNP[DEIN];
	return 10 + state[INT];
}
int Character::GetHP()//HPを返す
{
	return state[HP];
}
int Character::NPGet()//NPを返す
{
	return state[NP];
}
void Character::AllstateOpen()//一人のステータスを表示
{
	cout << "====================" << endl;
	cout << _pName << ":: ";
	for (int i = 0; i <= 5; i++)
	{
		cout << stateNam[i] << "=" << state[i] << " ";
	}
	cout << "\n====================" << endl;
}
void Character::ChangeName()//名前の変更
{
	char* TimpName;
	TimpName = new char[50];
	cout << "変更前の名前 >" << _pName << endl << endl;
	cout << "変更後の名前 >";
	for (;;)
	{
		cin >> TimpName;
		int timp;
		cout << TimpName << "で良いですか？ 決定=1 　もう一度=1以外" << endl;
		cout << ">";
		cin >> timp;
		if (timp == 1)
		{
			break;
		}
	}
	delete _pName;

	_pName = new char[strlen(TimpName) + 1];
	_pName = TimpName;

	cout << "名前が『" << _pName << "』になりました。" << endl;


}
//bool Character::HPbool(int num)
//{
//	if (num <= 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}