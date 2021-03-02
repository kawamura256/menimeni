//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"

#include"ObjSword.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjSword::CObjSword(float x, float y)//�R���X�g���N�^�Ŏ󂯎��������ϐ��ɑ���
{
	pos.x = x;
	pos.y = y;
}


//�C�j�V�����C�Y
void CObjSword::Init()
{
	vec.x = 0.0f;
	vec.y = 0.0f;

	angle_sword = 0;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, pos.x, pos.y, 25, 22, ELEMENT_PLAYER, OBJ_SWORD, 1);
}

//�A�N�V����
void CObjSword::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//����HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this); //HitBox�̈ʒu�����̈ʒu�ɍX�V
	hit->SetPos(pos.x, pos.y);
}


//�h���[
void CObjSword::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�@
	src.m_top = 0.0f;   //y
	src.m_left = 0.0f;  //x
	src.m_right = 32.0f; //x 
	src.m_bottom = 32.0f; //y

	//�\���ʒu�̐ݒ�
	dst.m_top = (32.0f - 32.0f) + pos.y;//�c�̈ʒu�ύX
	dst.m_left = (32.0f * angle_sword) + pos.x;
	dst.m_right = (32.0f - 32.0f * angle_sword) +pos.x;
	dst.m_bottom = 32.0f + pos.y;

	Draw::Draw(3, &src, &dst, c, 0.0f);
}