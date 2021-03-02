//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

#include"ObjHero.h"
#include"math.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


//�R���X�g���N�^
CObjHero::CObjHero(float x,float y)
{
	//�ʒu��񏉊���
	pos.x = x;
	pos.y  = y;
}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	//�ړ��x�N�g��
	vec.x = 0.0f;
	vec.y = 0.0f;

	//�����x
	acc.x = 0;
	acc.y = 0;

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

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0; // ����ł���block�̎�ނ��m�F�p

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, pos.x, pos.y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{

	//�ړ��x�N�g��
	vec.x = 0.0f;
	vec.y = 0.0f;
	
	if (Input::GetVKey(VK_UP) == true)
	{
		vec.y -= HERO_YSPEED;
		m_direc = HERO_BACK;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		vec.y += HERO_YSPEED;
		m_direc = HERO_FRONT;
	}
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		vec.x += HERO_XSPEED;
		m_direc = HERO_RIGHT;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		vec.x -= HERO_XSPEED;
		m_direc = HERO_LEFT;
	}



	//�ړ�
	 Move(&pos, &vec, acc);

	 //HitBox�̓��e���X�V
	 CHitBox* hit = Hits::GetHitBox(this); //�쐬����HitBox�X�V�p�̓���������o��
	 hit->SetPos(pos.x, pos.y);            //���������V�����ʒu(��l���@�̈ʒu)���ɒu��������

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
	dst.m_top = 0.0f + pos.y;
	dst.m_left = 0.0f + pos.x;
	dst.m_right = 32.0f +pos.x;
	dst.m_bottom = 32.0f + pos.y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}