#pragma once
#include"common.h"
class Character
{
public:
	Character(const char* pName);
	virtual ~Character();


protected:
	char* _pName;	// ���O
	int state[6];//�X�e�[�^�X�̎���
	const char* stateNam[6]//�X�e�[�^�X�̖��O
		= {
	   "HP",//�̗�
	   "NP",//�}�W�b�N�|�C���g
	   "�ؓ�",//�ؓ�
	   "���]",//���̂悳
	   "�h���",
	   "�s���l" };
	//bool deathbool = { false };
protected:
	int taiatari();//�̓�����
	int hoimi();//�z�C�~
	int haner();//���˂�
	int poison();//��
	int dein();//�f�C��
	int (Character::* Skillpul[SKILLNUM])(); // https://www7b.biglobe.ne.jp/~robe/cpphtml/html03/cpp03057.html //���Q�l�ɍ��܂���
protected:

	const char* skillCharNam[SKILLNUM] = { "�̓�����","�z�C�~","���˂�","�Ŗ�","�f�C�\" };//�X�L���̖��O�\��
	const int skillCharNP[SKILLNUM] = { 0,5,3,2,5 };//�X�L���̎g�p�ɂ�����NP
	bool SkillCheck[SKILLNUM] = { false };//�L�����N�^�[���X�L�����������Ă��邩
	int* SkillProcess;//�����Ă���X�L���̃i���o�[   //������new���Ă��邪�X�L���𑝂₷�Ƃ��ɂǂ����邩�l���Ă�
	int skillMAXnum;//�����Ă���X�L���̐�

protected:
	void SkillConstructorLook();//�������Ă���X�L���̃i���o�[��SkillProcess�ɓ����
	virtual int attack();

public://��ɐ퓬�Ŏg�p����֐�
	void DamageTrade(int Damege);//�_���[�W�̔���
	//bool HPbool(int num);

public://�\���֐� �ʂ�class�ɂ�����
	int GetHP();//HP��Ԃ��֐�
	int NPGet();//NP��Ԃ��֐�
	int SpeedCheck();//�X�s�[�h��Ԃ��֐�
	void AllstateOpen();//�S�ẴX�e�[�^�X��\������֐�
	void SkillOpen();//�X�L����\������֐�(������)
	const char* getName();//���O��Ԃ��֐�
	void ChangeName();//���O��ύX����֐� //�f�o�b�N�ׂ̈�public�ɂ��Ă�


};