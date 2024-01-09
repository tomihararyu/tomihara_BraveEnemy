#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //入出力
#include <iomanip>
#include <windows.h>
#include"Battle.h"
#include"Character.h"
using namespace std;//usingを使用しているのにcoutが曖昧とか言われたからしょうがなくstd::つけてます

static void next()
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
static void BraveStraightOpen(TeamMember** brave, int num, int speed[]/*ステータスの表示用*/)
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
static int SpeedCount(int Pspeed[], int Espeed[], int Pnum, int Enum)//敵と味方で一番DEXが早い奴を探す
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
static int enemyNameOpen(Enemy** enemy, int num)//名前を表示してターゲットを決定する
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
	
	int* B_hp;//変更が面倒だから初期値を保持しとく
	int* B_mp;

	B_hp = new int[Pnum];
	B_mp = new int[Pnum];

	for (int i = 0; i < Pnum; i++)
	{
		B_hp[i] = brave[i]->GetHP();
		B_mp[i] = brave[i]->NPGet();
	}

	
	const int EPnum = Enum + Pnum;//勇者+モンスターの合計
	bool speedBool[10];//行動したか否かを判定する変数//定数として扱えないからしょうがなく大きく用意している//後で治す

	for (int i = 0; i < EPnum; i++)//全てを行動していない状態にする
	{
		speedBool[i] = false;
	}

	int* Pspeed;//プレイヤーの変動するスピード
	Pspeed = new int[Pnum];//人数分配列を確保
	for (int i = 0; i < Pnum; i++)
	{
		Pspeed[i] = brave[i]->SpeedCheck();//スピードの初期値を代入
	}

	int* Espeed;//エネミーの変動するスピード
	Espeed = new int[Enum];//Enum分配列を確保
	for (int i = 0; i < Enum; i++)
	{
		Espeed[i] = enemy[i]->SpeedCheck();//スピードの初期値を代入
	}

	std::cout << "バトル開始" << endl;
	std::cout << endl;
	for (;;)
	{
		EnemyStraightOpen(enemy, Enum, Espeed);//エネミーのステータスの表示
		cout << endl;
		BraveStraightOpen(brave, Pnum, Pspeed);//勇者のステータスの表示


		int ActionValu = SpeedCount(Pspeed, Espeed, Pnum, Enum);//最速のキャラを探す//定数にしないのはspeedを上げるスキルを使うため
		if (speedBool[ActionValu] != true)//行動してなかったら
		{
			speedBool[ActionValu] = true;//行動したことにする
		}
		if (Pnum <= ActionValu)//エネミーの攻撃
		{
			ActionValu -= Pnum;
			if (ActionValu > Enum)//debug用
			{
				cout << "エラー" << endl;
				cout << "ActionValuが" << ActionValu << "でした" << endl;
				cout << "debugを終了してください。" << endl;
				int i;
				cin >> i;
			}
			else//エネミーの攻撃
			{
				brave[rand() % Pnum]->DamageTrade(enemy[ActionValu]->attack());//勇者の誰かが確率でenemyの攻撃を受ける
				Espeed[ActionValu] -= 5;//行動したら速度を-5
				next();//次へとワンクッション
			}

		}
		else//プレイヤーの攻撃
		{
			int timp = brave[ActionValu]->attack();//勇者のattackのダメージを一時的に保存
			if (timp != 0)//回復など攻撃を伴わない攻撃は0を返す様にしてある
			{
				cout << "誰に攻撃しますか?" << endl;
				enemy[enemyNameOpen(enemy, Enum)]->DamageTrade(timp);//攻撃対象を選択させる
			}
			Pspeed[ActionValu] -= 5;//攻撃したらスピードを-5
			next();//次へとワンクッション
		}


		int	booltimp = 0;//trueの数だけ増える
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
				Pspeed[i] = brave[i]->SpeedCheck();//speedを初期化
			}
			for (int i = 0; i < Enum; i++)
			{
				Espeed[i] = enemy[i]->SpeedCheck();//speedを初期化
			}
		}


		int EHPMAX = 0;//敵の体力の合計
		for (int i = 0; i < Enum; i++)//敵の全員の体力を計算// 撃破されたモンスターはswapして生きているモンスターの一番右に持っていく
		{
			int timp = enemy[i]->GetHP();//一時的にHPを保存
			if (timp <= 0)//もしHPが0以下なら
			{
				cout << enemy[i]->getName() << "を撃破した" << endl;
				for (int j = i; j < Enum; j++)//一番生きている中で右に到達するまで繰り返す
				{
					if (j != Enum - 1)//右に到達しているか判定
					{
						swap(enemy[j], enemy[j + 1]);//スワップ
					}
				}
				Enum -= 1;//モンスターの数を一人減らす //ここで経験値とgoldを数える予定だった
				cout << "残りの敵は" << Enum << "体" << endl;
				next();//次へでワンクッション
			}
			EHPMAX += timp;//最大HPを追加
		}

		int BHPMAX = 0;//勇者チーム全員のHPを合計した数を入れる変数
		for (int i = 0; i < Pnum; i++)//プレイヤーの体力カウント
		{
			int timp = brave[i]->GetHP();//一時的にHPを格納
			if (timp <= 0)//HPが0以下なら
			{
				for (int j = i; j < Pnum; j++)//一番生きている中で右に到達するまで繰り返す
				{
					if (j != Pnum - 1)//右に到達しているか判定
					{
						swap(brave[j], brave[j + 1]); //スワップ
					}
				}
				Pnum -= 1;//勇者の数を一人減らす
			}
			BHPMAX += timp;//最大のHPを数える
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

	for (int i = 0; i < Pnum; i++)//HPとMPの初期化
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
	std::cout << "戦闘終了" << endl;//減ったHPとNPを初期値に戻す

}