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

	Point pos;//�ʒu
	Vector vec;//�ړ��x�N�g��
	Vector acc;//�����x

	float GetX() { return pos.x; }
	float GetY() { return pos.y; }
	float GetVX() { return vec.x; }
	float GetVY() { return vec.y; }

	void SetX(float x) { pos.x = x; }
	void SetY(float y) { pos.y = y; }
	void SetVX(float vx) { vec.x = vx; }
	void SetVY(float vy) { vec.y = vy; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	bool GetUp() { return m_hit_up; }
	bool GetDown() { return m_hit_down; }
	bool GetLeft() { return m_hit_left; }
	bool GetRight() { return m_hit_right; }

	int GetBT() { return m_block_type; }
	void SetBT(int t) { m_block_type = t; }

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

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int m_block_type;
};