#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //入出力
#include <iomanip>
#include <windows.h>
#include"Battle.h"
#include"Character.h"
using namespace std;//usingを使用しているのにcoutが曖昧とか言われたからしょうがなくstd::つけてます

void next()
{
	int timp;
	std::cout << "『次へ』 >";
	cin >> timp;
}
static void EnemyStraightOpen(Enemy** enemy, int num, int speed[]/*ここ一つにしたい*/)
{
	std::cout << std::left;
	for (int i = 0; i < num; i++)
	{
		std::cout << setw(15) << "==============";
		std::cout << " ";
	}
	std::cout << endl;

	std::cout << "モンスターズ" << endl;
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
		std::cout << "行動値: " << setw(7) << speed[i];
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

	std::cout << "勇者チーム" << endl;
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
		std::cout << "行動値: " << setw(7) << speed[i];
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
	bool speedBool[10];//定数として扱えないからしょうがなく大きく用意している//後で治す

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

	std::cout << "バトル開始" << endl;
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
		if (Pnum <= ActionValu)//エネミーの攻撃
		{
			ActionValu -= Pnum;
			if (ActionValu > Enum)
			{
				cout << "エラー" << endl;
				cout << "ActionValuが" << ActionValu << "でした" << endl;
				cout << "debugを終了してください。" << endl;
				int i;
				cin >> i;
			}
			else//エネミーの攻撃
			{
				brave[rand() % Pnum]->DamageTrade(enemy[ActionValu]->attack());
				Espeed[ActionValu] -= 5;
				next();
			}

		}
		else//プレイヤーの攻撃
		{
			int timp = brave[ActionValu]->attack();
			cout << "誰に攻撃しますか?" << endl;
			enemy[enemyNameOpen(enemy, Enum)]->DamageTrade(timp);
			Pspeed[ActionValu] -= 5;
			next();
		}


		int	booltimp = 0;
		for (int i = 0; i < EPnum; i++)//行動しているか数える
		{
			if (speedBool[i] == true)
			{
				++booltimp;
			}
		}

		if (booltimp >= EPnum)//全員が行動したらspeedを初期化する
		{
			for (int i = 0; i < Pnum; i++)
			{
				Pspeed[i] = brave[i]->SpeedCheck();//元のspeedを返す関数
			}
			for (int i = 0; i < Enum; i++)
			{
				Espeed[i] = enemy[i]->SpeedCheck();
			}
		}


		int EHPMAX = 0;
		for (int i = 0; i < Enum; i++)//敵の全員の体力と撃破されたモンスターを表示させない処理
		{
			int timp = enemy[i]->GetHP();
			if (timp <= 0)
			{
				cout << enemy[i]->getName() << "を撃破した" << endl;
				for (int j = i; j < Enum; j++)
				{
					if (j != Enum - 1)
					{
						swap(enemy[j], enemy[j + 1]);
					}
				}
				Enum -= 1;
				cout << "残りの敵は" << Enum << "体" << endl;
				next();
			}
			EHPMAX += timp;
		}

		int BHPMAX = 0;
		for (int i = 0; i < Pnum; i++)//プレイヤーの体力count
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

		if (BHPMAX <= 0)//勝敗判定
		{
			std::cout << brave[0]->getName() << "たちの敗北" << endl;
			break;
		}
		else if (EHPMAX <= 0)
		{
			std::cout << brave[0]->getName() << "たちの勝利" << endl;
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
	std::cout << "戦闘終了" << endl;

}