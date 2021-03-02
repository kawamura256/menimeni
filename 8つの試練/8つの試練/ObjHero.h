#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"

#include"math.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

#define HERO_FRONT (0)//����
#define HERO_BACK  (1)//�w��
#define HERO_RIGHT (2)//�E
#define HERO_LEFT  (3)//��

#define HERO_XSPEED (5)//��l���̑��xX
#define HERO_YSPEED (5)//��l���̑��xY

//�I�u�W�F�N�g : ��l��
class CObjHero : public CObj
{
public:
	CObjHero(float x,float y);
	~CObjHero() {};
	void Init();        //�C�j�V�����C�Y
	void Action();      //�A�N�V����
	void Draw();        //�h���[

	float GetX();     //�ʒu���X�擾�p
	float GetY();     //�ʒu���Y�擾�p

	Point pos;//�ʒu
	Vector vec;//�ړ��x�N�g��
	Vector acc;//�����x

	float GetX() { return m_x; }
	float GetY() { return m_y; }

private:

	float m_x;  //��l���@��x�����ړ��p�ϐ�
	float m_y;  //��l���@��y�����ړ��p�ϐ�
	float m_vx; //�ړ��x�N�g��
	float m_vy; //�ړ��x�N�g��

	int m_direc; //��l���̌���

	//���ʃA�j���[�V����
	int m_ani_time1; //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame1; //�`��t���[��

	//�w�ʃA�j���[�V����
	int m_ani_time2; //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame2; //�`��t���[��

	//�E�A�j���[�V����
	int m_ani_time3; //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame3; //�`��t���[��

	//���A�j���[�V����
	int m_ani_time4; //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame4; //�`��t���[��

};