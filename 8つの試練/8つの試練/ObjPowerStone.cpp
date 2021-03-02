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
	if (m_id == RED_STONE)
	{
		m_x = x;
		m_y = y;
	}
}


//�C�j�V�����C�Y
void CObjPowerStone::Init()
{

	if (m_id == RED_STONE) 
	{
		//�����蔻��pHitBox���쐬
		Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_POWERSTONE, 1);
	}
}



//�A�N�V����
void CObjPowerStone::Action()
{
	CObjHall* hall = (CObjHall*)Objs::GetObj(OBJ_HALL);

	if (m_id == RED_STONE)
	{
		//HitBox�̓��e���X�V
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x+hall->GetScroll(), m_y + hall->GetScroll2());

		//��l���ƐڐG���Ă��邩�ǂ������ׂ�
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
}


//�h���[
void CObjPowerStone::Draw()
{
	CObjHall* hall = (CObjHall*)Objs::GetObj(OBJ_HALL);

	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;   //y
	src.m_left = 5.0f; //x
	src.m_right = 58.0f; //x
	src.m_bottom = 55.0f; //y



	switch (m_id)
	{
	case RED_STONE:

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y+hall->GetScroll2();
		dst.m_left = 0.0f + m_x + hall->GetScroll();
		dst.m_right = 32.0f + m_x + hall->GetScroll();
		dst.m_bottom = 32.0f + m_y + hall->GetScroll2();
		//�`��
		Draw::Draw(3, &src, &dst, c, 0.0f);
		break;
	case ORANGE_STONE:
		break;
	}

}
