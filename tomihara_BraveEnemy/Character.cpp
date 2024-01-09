#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <windows.h>

#include"Character.h"
using namespace std;


Character::Character(const char* pName) {//�R���X�g���N�^
	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);

	Skillpul[TAIATARI] = &Character::taiatari;
	Skillpul[HOIM] = &Character::hoimi;
	Skillpul[HANER] = &Character::haner;
	Skillpul[POIZN] = &Character::poison;
	Skillpul[DEIN] = &Character::dein;

	SkillProcess = new int[1];//�X�L���𐔂���ۂɖ���V����delete����׈ꎞ�I��new
}
Character::~Character()//�f�X�g���N�^
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
void Character::SkillConstructorLook()//�������Ă���X�L���̔ԍ���z��ɓ����
{
	if (SkillProcess != nullptr)//����Ăяo���x�ɃX�L����delete
	{
		delete SkillProcess;
		SkillProcess = nullptr;
	}

	int timp = 0;//�������Ă���X�L���̐��𐔂���
	for (int i = 0; i < SKILLNUM; i++)//�X�L���̐���J��Ԃ�
	{
		if (SkillCheck[i] == true)//�R���X�g���N�^��true�ɂ����X�L���𐔂���
		{
			timp++;
		}
	}

	skillMAXnum = timp;//���ʂ���

	SkillProcess = new int[skillMAXnum];//�������Ă���X�L���̐������I�Ɋm��
	int j = 0;
	for (int i = 0; i < SKILLNUM; i++)//�X�L���̐���J��Ԃ�
	{
		if (SkillCheck[i] == true)//true��������
		{
			SkillProcess[j] = i;//�ϐ��ɓ����
			j++;
		}
	}
}
const char* Character::getName()//���O��Ԃ��֐�
{
	return _pName;
}
int Character::attack()//�p����Ŏg�����z�֐�
{
	cout << "�e" << endl;
	return 0;
}
void Character::DamageTrade(int Damege)//�����Ń_���[�W�������Ă��ă_���[�W����DF��������HP�����炷
{
	if (Damege != 0)//�_���[�W��0�ȊO��������
	{
		int timp = (Damege - state[DF]) + rand() % 3;//�����_���[�W�������_����
		if (timp <= 0)//����Ȃ���
		{
			timp = 0;
		}

		if (state[HP] - timp <= 0)//�_���[�W��HP�𒴉߂��Ȃ��悤�ɂ��鏈��
		{
			state[HP] = 0;
		}
		else//���ʂ�HP�������
		{
			state[HP] -= timp;
		}

		if (state[HP] != 0)//�\��
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
	if (state[NP] < 0)//HP���}�C�i�X�ɂȂ�Ȃ��悤�ɂ��鏈�� //��Ŋ֐�������
	{
		state[NP] = 0;
	}
	return state[DEX];
}
int Character::taiatari()//�̓�����
{
	cout << _pName << "�̑̓�����!! �Ռ���" << _pName << "��HP��" << 2 << "������\n" << endl;
	state[HP] -= 2;
	return 6 + state[POW];

}
int Character::hoimi()//�z�C�~
{
	state[HP] += 2 * state[INT] / 10;
	state[NP] -= skillCharNP[HOIM];
	cout << _pName << "�̉�!!" << endl;
	cout << _pName << "��" << stateNam[HP] << "��" << 2 * state[INT] / 10 << "�񕜂���" << endl;
	return 0;
}
int Character::haner()//���˂�
{
	cout << _pName << "�̒��˂�!!" << endl;

	cout << _pName << "�͌��C�ɒ��˂Ă���!!!" << endl;
	return 0;
}
int Character::poison()//��
{
	cout << _pName << "�̓Ŗ�!!\n�Ŗ���f����" << endl;
	state[NP] -= skillCharNP[POIZN];
	return 23;
}
int Character::dein()//�f�C��
{
	cout << _pName << "�̃f�C��!!" << endl;
	state[NP] -= skillCharNP[DEIN];
	return 10 + state[INT];
}
int Character::GetHP()//HP��Ԃ�
{
	return state[HP];
}
int Character::NPGet()//NP��Ԃ�
{
	return state[NP];
}
void Character::AllstateOpen()//��l�̃X�e�[�^�X��\��
{
	cout << "====================" << endl;
	cout << _pName << ":: ";
	for (int i = 0; i <= 5; i++)
	{
		cout << stateNam[i] << "=" << state[i] << " ";
	}
	cout << "\n====================" << endl;
}
void Character::ChangeName()//���O�̕ύX
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