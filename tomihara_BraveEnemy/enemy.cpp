#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"enemy.h"
using namespace std;

Enemy::Enemy(const char* name) :Character(name)
{

}
int Enemy::attack()//�U��
{
	int move = rand() % skillMAXnum;//�����Ă���X�L���̔ԍ����^�������őI�΂���
	cout << "====================" << endl;
	return (this->*Skillpul[SkillProcess[move]])();//�Ԃ�l��Ԃ�l�ɓ����//�����o�֐��|�C���^�Ŋ֐����Ăяo��
}