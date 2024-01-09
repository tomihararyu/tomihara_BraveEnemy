#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //���o��
#include <iomanip>
#include <windows.h>
#include"Battle.h"
#include"Character.h"
using namespace std;//using���g�p���Ă���̂�cout���B���Ƃ�����ꂽ���炵�傤���Ȃ�std::���Ă܂�

static void next()
{
	int timp;
	std::cout << "�w���ցx >";
	cin >> timp;
}
static void EnemyStraightOpen(Enemy** enemy, int num, int speed[]/*������ɂ�����*/)
{
	std::cout << std::left;
	for (int i = 0; i < num; i++)
	{
		std::cout << setw(15) << "==============";
		std::cout << " ";
	}
	std::cout << endl;

	std::cout << "�����X�^�[�Y" << endl;
	for (int i = 0; i < num; i++)
	{
		std::cout << setw(15) << enemy[i]->getName();
		std::cout << " ";
	}
	std::cout << endl;

	for (int i = 0; i < num; i++)
	{
		std::cout << "    HP: " << setw(7) << enemy[i]->GetHP();
		std::cout << " ";
	}
	std::cout << endl;
	for (int i = 0; i < num; i++)
	{
		std::cout << "    NP: " << setw(7) << enemy[i]->NPGet();
		std::cout << " ";
	}
	std::cout << endl;
	for (int i = 0; i < num; i++)
	{
		std::cout << "�s���l: " << setw(7) << speed[i];
		std::cout << " ";
	}
	std::cout << endl;
}
static void BraveStraightOpen(TeamMember** brave, int num, int speed[]/*�X�e�[�^�X�̕\���p*/)
{
	std::cout << std::left;
	for (int i = 0; i < num; i++)
	{
		std::cout << setw(15) << "==============";

		std::cout << " ";
	}
	std::cout << endl;

	std::cout << "�E�҃`�[��" << endl;
	for (int i = 0; i < num; i++)
	{
		std::cout << setw(15) << brave[i]->getName();
		std::cout << " ";
	}
	for (int i = 0; i < num; i++)
	{
		if (brave[i]->GetHP() <= 0)
		{
			std::cout << setw(15) << brave[i]->getName();
			std::cout << " ";
		}

	}
	std::cout << endl;

	for (int i = 0; i < num; i++)
	{
		std::cout << "    HP: " << setw(7) << brave[i]->GetHP();
		std::cout << " ";
	}
	std::cout << endl;
	for (int i = 0; i < num; i++)
	{
		std::cout << "    NP: " << setw(7) << brave[i]->NPGet();
		std::cout << " ";
	}
	std::cout << endl;
	for (int i = 0; i < num; i++)
	{
		std::cout << "�s���l: " << setw(7) << speed[i];
		std::cout << " ";
	}
	std::cout << endl;
}
static int SpeedCount(int Pspeed[], int Espeed[], int Pnum, int Enum)//�G�Ɩ����ň��DEX�������z��T��
{
	int	Ptimp1 = Pspeed[0];
	int Ptimp2 = 0;

	int Etimp1 = Espeed[0];
	int Etimp2 = 0;
	for (int i = 0; i < Pnum; i++)
	{
		if (Pspeed[i] <= Pspeed[i + 1])
		{
			Ptimp1 = Pspeed[i + 1];
			Ptimp2 = i + 1;
		}
	}
	for (int i = 0; i < Enum; i++)
	{
		if (Espeed[i] < Espeed[i + 1])
		{
			Etimp1 = Espeed[i + 1];
			Etimp2 = i + 1;
		}
	}
	if (Ptimp1 < Etimp1)//aaaaaaa
	{
		return 	Etimp2 + Pnum;
	}
	else
	{
		return Ptimp2;
	}
}
static int enemyNameOpen(Enemy** enemy, int num)//���O��\�����ă^�[�Q�b�g�����肷��
{
	for (int i = 0; i < num; i++)
	{
		cout << i << "=";
		std::cout << setw(15) << enemy[i]->getName();
		std::cout << " ";
	}
	for (;;)
	{
		int CIN;
		std::cout << ">";
		cin >> CIN;
		if (CIN >= 0 && CIN < num)
		{
			return CIN;
		}
	}
}
void Battle::battleStart(TeamMember* brave[], Enemy* enemy[], int Enum, int Pnum)
{
	
	int* B_hp;//�ύX���ʓ|�����珉���l��ێ����Ƃ�
	int* B_mp;

	B_hp = new int[Pnum];
	B_mp = new int[Pnum];

	for (int i = 0; i < Pnum; i++)
	{
		B_hp[i] = brave[i]->GetHP();
		B_mp[i] = brave[i]->NPGet();
	}

	
	const int EPnum = Enum + Pnum;//�E��+�����X�^�[�̍��v
	bool speedBool[10];//�s���������ۂ��𔻒肷��ϐ�//�萔�Ƃ��Ĉ����Ȃ����炵�傤���Ȃ��傫���p�ӂ��Ă���//��Ŏ���

	for (int i = 0; i < EPnum; i++)//�S�Ă��s�����Ă��Ȃ���Ԃɂ���
	{
		speedBool[i] = false;
	}

	int* Pspeed;//�v���C���[�̕ϓ�����X�s�[�h
	Pspeed = new int[Pnum];//�l�����z����m��
	for (int i = 0; i < Pnum; i++)
	{
		Pspeed[i] = brave[i]->SpeedCheck();//�X�s�[�h�̏����l����
	}

	int* Espeed;//�G�l�~�[�̕ϓ�����X�s�[�h
	Espeed = new int[Enum];//Enum���z����m��
	for (int i = 0; i < Enum; i++)
	{
		Espeed[i] = enemy[i]->SpeedCheck();//�X�s�[�h�̏����l����
	}

	std::cout << "�o�g���J�n" << endl;
	std::cout << endl;
	for (;;)
	{
		EnemyStraightOpen(enemy, Enum, Espeed);//�G�l�~�[�̃X�e�[�^�X�̕\��
		cout << endl;
		BraveStraightOpen(brave, Pnum, Pspeed);//�E�҂̃X�e�[�^�X�̕\��


		int ActionValu = SpeedCount(Pspeed, Espeed, Pnum, Enum);//�ő��̃L������T��//�萔�ɂ��Ȃ��̂�speed���グ��X�L�����g������
		if (speedBool[ActionValu] != true)//�s�����ĂȂ�������
		{
			speedBool[ActionValu] = true;//�s���������Ƃɂ���
		}
		if (Pnum <= ActionValu)//�G�l�~�[�̍U��
		{
			ActionValu -= Pnum;
			if (ActionValu > Enum)//debug�p
			{
				cout << "�G���[" << endl;
				cout << "ActionValu��" << ActionValu << "�ł���" << endl;
				cout << "debug���I�����Ă��������B" << endl;
				int i;
				cin >> i;
			}
			else//�G�l�~�[�̍U��
			{
				brave[rand() % Pnum]->DamageTrade(enemy[ActionValu]->attack());//�E�҂̒N�����m����enemy�̍U�����󂯂�
				Espeed[ActionValu] -= 5;//�s�������瑬�x��-5
				next();//���ւƃ����N�b�V����
			}

		}
		else//�v���C���[�̍U��
		{
			int timp = brave[ActionValu]->attack();//�E�҂�attack�̃_���[�W���ꎞ�I�ɕۑ�
			if (timp != 0)//�񕜂ȂǍU���𔺂�Ȃ��U����0��Ԃ��l�ɂ��Ă���
			{
				cout << "�N�ɍU�����܂���?" << endl;
				enemy[enemyNameOpen(enemy, Enum)]->DamageTrade(timp);//�U���Ώۂ�I��������
			}
			Pspeed[ActionValu] -= 5;//�U��������X�s�[�h��-5
			next();//���ւƃ����N�b�V����
		}


		int	booltimp = 0;//true�̐�����������
		for (int i = 0; i < EPnum; i++)//�s�����Ă��邩������
		{
			if (speedBool[i] == true)
			{
				++booltimp;
			}
		}

		if (booltimp >= EPnum)//�S�����s��������speed������������
		{
			for (int i = 0; i < Pnum; i++)
			{
				Pspeed[i] = brave[i]->SpeedCheck();//speed��������
			}
			for (int i = 0; i < Enum; i++)
			{
				Espeed[i] = enemy[i]->SpeedCheck();//speed��������
			}
		}


		int EHPMAX = 0;//�G�̗̑͂̍��v
		for (int i = 0; i < Enum; i++)//�G�̑S���̗̑͂��v�Z// ���j���ꂽ�����X�^�[��swap���Đ����Ă��郂���X�^�[�̈�ԉE�Ɏ����Ă���
		{
			int timp = enemy[i]->GetHP();//�ꎞ�I��HP��ۑ�
			if (timp <= 0)//����HP��0�ȉ��Ȃ�
			{
				cout << enemy[i]->getName() << "�����j����" << endl;
				for (int j = i; j < Enum; j++)//��Ԑ����Ă��钆�ŉE�ɓ��B����܂ŌJ��Ԃ�
				{
					if (j != Enum - 1)//�E�ɓ��B���Ă��邩����
					{
						swap(enemy[j], enemy[j + 1]);//�X���b�v
					}
				}
				Enum -= 1;//�����X�^�[�̐�����l���炷 //�����Ōo���l��gold�𐔂���\�肾����
				cout << "�c��̓G��" << Enum << "��" << endl;
				next();//���ւŃ����N�b�V����
			}
			EHPMAX += timp;//�ő�HP��ǉ�
		}

		int BHPMAX = 0;//�E�҃`�[���S����HP�����v������������ϐ�
		for (int i = 0; i < Pnum; i++)//�v���C���[�̗̑̓J�E���g
		{
			int timp = brave[i]->GetHP();//�ꎞ�I��HP���i�[
			if (timp <= 0)//HP��0�ȉ��Ȃ�
			{
				for (int j = i; j < Pnum; j++)//��Ԑ����Ă��钆�ŉE�ɓ��B����܂ŌJ��Ԃ�
				{
					if (j != Pnum - 1)//�E�ɓ��B���Ă��邩����
					{
						swap(brave[j], brave[j + 1]); //�X���b�v
					}
				}
				Pnum -= 1;//�E�҂̐�����l���炷
			}
			BHPMAX += timp;//�ő��HP�𐔂���
		}

		if (BHPMAX <= 0)//���s����
		{
			std::cout << brave[0]->getName() << "�����̔s�k" << endl;
			break;
		}
		else if (EHPMAX <= 0)
		{
			std::cout << brave[0]->getName() << "�����̏���" << endl;
			break;
		}
		system("cls");

	}

	for (int i = 0; i < Pnum; i++)//HP��MP�̏�����
	{
		brave[i]->HPNPfullset(B_hp[i], B_mp[i]);
	}

	if (Pspeed != nullptr)
	{
		delete B_hp;
		delete B_mp;
		delete Pspeed;
	}
	if (Espeed != nullptr)
	{
		delete Espeed;
	}
	std::cout << "�퓬�I��" << endl;//������HP��NP�������l�ɖ߂�

}