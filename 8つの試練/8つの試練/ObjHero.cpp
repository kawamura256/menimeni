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
CObjHero::CObjHero()
{
}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_x = 0.0f;
	m_y = 0.0f;

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
	m_vx = 0.0f; //�ړ��x�N�g��
	m_vy = 0.0f; //�ړ��x�N�g��
	
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= HERO_YSPEED;
		m_y -= m_vy;
		m_direc = HERO_BACK;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += HERO_YSPEED;
		m_y += m_vy;
		m_direc = HERO_FRONT;
	}
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += HERO_XSPEED;
		m_x += m_vx;
		m_direc = HERO_RIGHT;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= HERO_XSPEED;
		m_x -= m_vx;
		m_direc = HERO_LEFT;
	}


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
	switch (m_direc)
	{
	case HERO_RIGHT:
		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f;   //y
		src.m_left = 0.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_right = 32.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_bottom = 96.0f; //y
		break;
	case HERO_BACK:
		//�؂���ʒu�̐ݒ�
		src.m_top = 32.0f;   //y
		src.m_left = 0.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_right = 32.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_bottom = 64.0f; //y
		break;
	case HERO_FRONT:
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;   //y
		src.m_left = 0.0f + AniData1[m_ani_frame1] * 32.0f; //x
		src.m_right = 32.0f + AniData1[m_ani_frame1] * 32.0f; //x
		src.m_bottom = 32.0f; //y
		break;
	case HERO_LEFT:
		//�؂���ʒu�̐ݒ�
		src.m_top = 96.0f;   //y
		src.m_left = 0.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_right = 32.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_bottom = 128.0f; //y
		break;
	}

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}