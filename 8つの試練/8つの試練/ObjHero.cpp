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


}