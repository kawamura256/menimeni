#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

#define HERO_FRONT (0)//����
#define HERO_BACK  (1)//�w��
#define HERO_RIGHT (2)//�E
#define HERO_LEFT  (3)//��


//�I�u�W�F�N�g : ��l��
class CObjHero : public CObj
{
public:
	CObjHero(float x, float y);
	~CObjHero() {};
	void Init();        //�C�j�V�����C�Y
	void Action();      //�A�N�V����
	void Draw();        //�h���[

	float GetX();     //�ʒu���X�擾�p
	float GetY();     //�ʒu���Y�擾�p

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