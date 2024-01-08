#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <windows.h>

#include"Character.h"
using namespace std;


Character::Character(const char* pName) {
	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);

	Skillpul[TAIATARI] = &Character::taiatari;
	Skillpul[HOIM] = &Character::hoimi;
	Skillpul[HANER] = &Character::haner;
	Skillpul[POIZN] = &Character::poison;
	Skillpul[DEIN] = &Character::dein;


}
Character::~Character()
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
void Character::SkillConstructorLook()
{
	int timp = 0;
	for (int i = 0; i < SKILLNUM; i++)
	{
		if (SkillCheck[i] == true)
		{
			timp++;
		}
	}

	skillMAXnum = timp;

	SkillProcess = new int[skillMAXnum];
	int j = 0;
	for (int i = 0; i < 5; i++)
	{
		if (SkillCheck[i] == true)
		{
			SkillProcess[j] = i;
			j++;
		}
	}
}
const char* Character::getName()
{
	return _pName;
}
int Character::attack()
{
	cout << "�e" << endl;
	return 0;
}
void Character::DamageTrade(int Damege)
{
	if (Damege != 0)
	{
		int timp = (Damege - state[DF]) + rand() % 3;
		if (timp <= 0)
		{
			timp = 0;
		}

		if (state[HP] - timp <= 0)
		{
			state[HP] = 0;
		}
		else
		{
			state[HP] -= timp;
		}

		if (state[HP] != 0)
		{
			cout << timp << " �_���[�W!!  " << _pName << "��HP��" << state[HP] << "�ɂȂ���" << endl;
		}
		else
		{

		}

	}

}
int Character::SpeedCheck()
{
	if (state[NP] < 0)
	{
		state[NP] = 0;
	}
	return state[DEX];
}
int Character::taiatari()
{
	cout << _pName << "�̑̓�����!! �Ռ���" << _pName << "��HP��" << 2 << "������\n" << endl;
	state[HP] -= 2;
	return 6 + state[POW];

}
int Character::hoimi()
{
	state[HP] += 2 * state[INT] / 10;
	state[NP] -= skillCharNP[HOIM];
	cout << _pName << "�̉�!!" << endl;
	cout << _pName << "��" << stateNam[HP] << "��" << 2 * state[INT] / 10 << "�񕜂���" << endl;
	return 0;
}
int Character::haner()
{
	cout << _pName << "�̒��˂�!!" << endl;

	cout << _pName << "�͌��C�ɒ��˂Ă���!!!" << endl;
	return 0;
}
int Character::poison()
{
	cout << _pName << "�̓Ŗ�!!\n�Ŗ���f����" << endl;
	state[NP] -= skillCharNP[POIZN];
	return 23;

}
int Character::dein()
{
	cout << _pName << "�̃f�C��!!" << endl;
	state[NP] -= skillCharNP[DEIN];
	return 10 + state[INT];

}
int Character::GetHP()
{
	return state[HP];
}
int Character::NPGet()
{
	return state[NP];
}
void Character::AllstateOpen()
{
	cout << "====================" << endl;
	cout << _pName << ":: ";
	for (int i = 0; i <= 5; i++)
	{
		cout << stateNam[i] << "=" << state[i] << " ";
	}
	cout << "\n====================" << endl;
}
void Character::ChangeName()
{
	char* TimpName;
	TimpName = new char[50];
	cout << "�ύX�O�̖��O >" << _pName << endl << endl;
	cout << "�ύX��̖��O >";
	for (;;)
	{
		cin >> TimpName;
		int timp;
		cout << TimpName << "�ŗǂ��ł����H ����=1 �@������x=1�ȊO" << endl;
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

	cout << "���O���w" << _pName << "�x�ɂȂ�܂����B" << endl;


}
//void Character::deathjud()
//{
//	if (state[HP] <= 0)
//	{
//		deathbool = true;
//	}
//}
//int Character::deathInt()
//{
//	return deathbool;
//}
bool Character::HPbool(int num)
{
	if (num <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}