#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

#define SWORD_FLONT (0)
#define SWORD_BACK (1)
#define SWORD_RIGHT (2)
#define SWORD_LEFT (3)

//�I�u�W�F�N�g�F��
class CObjSword : public CObj
{
public:
	CObjSword(float x, float y);
	~CObjSword() {};
	void Init();     //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();   //�h���[

	Point pos;//�ʒu
	Vector vec;//�ړ��x�N�g��
	Vector acc;//�����x

private:

	int angle_sword;//���̊p�x
};