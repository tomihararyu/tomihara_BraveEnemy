#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //���o��
#include <iomanip>
#include <windows.h>
#include"Battle.h"
#include"Character.h"
using namespace std;//using���g�p���Ă���̂�cout���B���Ƃ�����ꂽ���炵�傤���Ȃ�std::���Ă܂�

void next()
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
static void BraveStraightOpen(TeamMember** brave, int num, int speed[])
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
static int SpeedCount(int Pspeed[], int Espeed[], int Pnum, int Enum)
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
static int enemyNameOpen(Enemy** enemy, int num)
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
	const int EPnum = Enum + Pnum;
	bool speedBool[10];//�萔�Ƃ��Ĉ����Ȃ����炵�傤���Ȃ��傫���p�ӂ��Ă���//��Ŏ���

	for (int i = 0; i < EPnum; i++)
	{
		speedBool[i] = false;
	}

	int* Pspeed;
	Pspeed = new int[Pnum];
	for (int i = 0; i < Pnum; i++)
	{
		Pspeed[i] = brave[i]->SpeedCheck();
	}

	int* Espeed;
	Espeed = new int[Enum];
	for (int i = 0; i < Enum; i++)
	{
		Espeed[i] = enemy[i]->SpeedCheck();
	}

	std::cout << "�o�g���J�n" << endl;
	std::cout << endl;
	const int MAXMember = Pnum + Enum;
	for (;;)
	{
		EnemyStraightOpen(enemy, Enum, Espeed);
		cout << endl;
		BraveStraightOpen(brave, Pnum, Pspeed);


		int ActionValu = SpeedCount(Pspeed, Espeed, Pnum, Enum);
		if (speedBool[ActionValu] != true)
		{
			speedBool[ActionValu] = true;
		}
		if (Pnum <= ActionValu)//�G�l�~�[�̍U��
		{
			ActionValu -= Pnum;
			if (ActionValu > Enum)
			{
				cout << "�G���[" << endl;
				cout << "ActionValu��" << ActionValu << "�ł���" << endl;
				cout << "debug���I�����Ă��������B" << endl;
				int i;
				cin >> i;
			}
			else//�G�l�~�[�̍U��
			{
				brave[rand() % Pnum]->DamageTrade(enemy[ActionValu]->attack());
				Espeed[ActionValu] -= 5;
				next();
			}

		}
		else//�v���C���[�̍U��
		{
			int timp = brave[ActionValu]->attack();
			cout << "�N�ɍU�����܂���?" << endl;
			enemy[enemyNameOpen(enemy, Enum)]->DamageTrade(timp);
			Pspeed[ActionValu] -= 5;
			next();
		}


		int	booltimp = 0;
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
				Pspeed[i] = brave[i]->SpeedCheck();//����speed��Ԃ��֐�
			}
			for (int i = 0; i < Enum; i++)
			{
				Espeed[i] = enemy[i]->SpeedCheck();
			}
		}


		int EHPMAX = 0;
		for (int i = 0; i < Enum; i++)//�G�̑S���̗̑͂ƌ��j���ꂽ�����X�^�[��\�������Ȃ�����
		{
			int timp = enemy[i]->GetHP();
			if (timp <= 0)
			{
				cout << enemy[i]->getName() << "�����j����" << endl;
				for (int j = i; j < Enum; j++)
				{
					if (j != Enum - 1)
					{
						swap(enemy[j], enemy[j + 1]);
					}
				}
				Enum -= 1;
				cout << "�c��̓G��" << Enum << "��" << endl;
				next();
			}
			EHPMAX += timp;
		}

		int BHPMAX = 0;
		for (int i = 0; i < Pnum; i++)//�v���C���[�̗̑�count
		{
			int timp = brave[i]->GetHP();
			if (timp <= 0)
			{
				for (int j = i; j < Pnum; j++)
				{
					if (j != Pnum - 1)
					{
						swap(brave[j], brave[j + 1]);
					}
				}
				Pnum -= 1;
			}
			BHPMAX += timp;
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

	if (Pspeed != nullptr)
	{
		delete Pspeed;
	}
	if (Espeed != nullptr)
	{
		delete Espeed;
	}
	std::cout << "�퓬�I��" << endl;

}