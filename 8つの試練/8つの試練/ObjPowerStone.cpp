//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"
#include"GameHead.h"

#include"ObjPowerStone.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^                  �@�@�ʒu�@�@�p���[�X�g�[���̔ԍ�
CObjPowerStone::CObjPowerStone(float x, float y, int id)
{
	m_id = id;
}


//�C�j�V�����C�Y
void CObjPowerStone::Init()
{
	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_POWERSTONE, 1);
}


//�A�N�V����
void CObjPowerStone::Action()
{
}


//�h���[
void CObjPowerStone::Draw()
{
	////�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 24.0f;   //y
	src.m_left = 30.0f; //x
	src.m_right = 226.0f; //x
	src.m_bottom = 222.0f; //y

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x ;
	dst.m_right = 32.0f + m_x ;
	dst.m_bottom = 32.0f + m_y;

	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}
