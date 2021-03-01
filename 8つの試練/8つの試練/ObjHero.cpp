//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

#include"ObjHero.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


//�R���X�g���N�^
CObjHero::CObjHero(float x, float y)
{
	m_x = x;
	m_y = y;

}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_vx = 0.0f; //�ړ��x�N�g��
	m_vy = 0.0f; //�ړ��x�N�g��

	m_direc = HERO_FRONT;

	//���ʃA�j���[�V����
	m_ani_time1 = 0; //�A�j���[�V�����t���[������Ԋu
	m_ani_frame1 = 0; //�Î~�t���[���������ɂ���

	//�w�ʃA�j���[�V����
	m_ani_time2 = 0; //�A�j���[�V�����t���[������Ԋu
	m_ani_frame2 = 0; //�Î~�t���[���������ɂ���

	//�E�A�j���[�V����
	m_ani_time3 = 0; //�A�j���[�V�����t���[������Ԋu
	m_ani_frame3 = 0; //�Î~�t���[���������ɂ���

	//���A�j���[�V����
	m_ani_time4 = 0; //�A�j���[�V�����t���[������Ԋu
	m_ani_frame4 = 0; //�Î~�t���[���������ɂ���

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{



}


//�h���[
void CObjHero::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	int AniData1[3] = //���ʌ�������o�^
	{
		0,1,2,
	};
	int AniData2[3] = //�w�ʌ�������o�^
	{
		0,1,2,
	};
	int AniData3[2] = //�E��������o�^
	{
		0,1,
	};
	int AniData4[2] = //����������o�^
	{
		0,1,
	};

	//��l��
	if (m_direc == HERO_RIGHT) //�E
	{

		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f;   //y
		src.m_left = 0.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_right = 32.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_bottom = 96.0f; //y


	}
	if (m_direc ==HERO_BACK) //���
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 32.0f;   //y
		src.m_left = 0.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_right = 32.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_bottom = 64.0f; //y
	}

	if (m_direc == HERO_FRONT) //�O
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;   //y
		src.m_left = 0.0f + AniData1[m_ani_frame1] * 32.0f; //x
		src.m_right = 32.0f + AniData1[m_ani_frame1] * 32.0f; //x
		src.m_bottom = 32.0f; //y
	}

	if (m_direc == HERO_LEFT)//��
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 96.0f;   //y
		src.m_left = 0.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_right = 32.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_bottom = 128.0f; //y
	}

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}