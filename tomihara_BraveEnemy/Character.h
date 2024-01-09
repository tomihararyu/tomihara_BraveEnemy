#pragma once
#include"common.h"
class Character
{
public:
	Character(const char* pName);
	virtual ~Character();


protected:
	char* _pName;	// 名前
	int state[6];//ステータスの実数
	const char* stateNam[6]//ステータスの名前
		= {
	   "HP",//体力
	   "NP",//マジックポイント
	   "筋肉",//筋肉
	   "頭脳",//頭のよさ
	   "防御力",
	   "行動値" };
	//bool deathbool = { false };
protected:
	int taiatari();//体当たり
	int hoimi();//ホイミ
	int haner();//跳ねる
	int poison();//毒
	int dein();//デイン
	int (Character::* Skillpul[SKILLNUM])(); // https://www7b.biglobe.ne.jp/~robe/cpphtml/html03/cpp03057.html //を参考に作りました
protected:

	const char* skillCharNam[SKILLNUM] = { "体当たり","ホイミ","跳ねる","毒霧","デイソ" };//スキルの名前表示
	const int skillCharNP[SKILLNUM] = { 0,5,3,2,5 };//スキルの使用にかかるNP
	bool SkillCheck[SKILLNUM] = { false };//キャラクターがスキルを所持しているか
	int* SkillProcess;//持っているスキルのナンバー   //ここはnewしているがスキルを増やすときにどうするか考えてる
	int skillMAXnum;//持っているスキルの数

protected:
	void SkillConstructorLook();//所持しているスキルのナンバーをSkillProcessに入れる
	virtual int attack();

public://主に戦闘で使用する関数
	void DamageTrade(int Damege);//ダメージの判定
	//bool HPbool(int num);

public://表示関数 別のclassにしたい
	int GetHP();//HPを返す関数
	int NPGet();//NPを返す関数
	int SpeedCheck();//スピードを返す関数
	void AllstateOpen();//全てのステータスを表示する関数
	void SkillOpen();//スキルを表示する関数(未実装)
	const char* getName();//名前を返す関数
	void ChangeName();//名前を変更する関数 //デバックの為にpublicにしてる


};