#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define HALL_WIDTH (35)
#define HALL_HEIGHT (35)

#define HALL_WALL (1)

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjHall :public CObj
{
public:
	CObjHall() {};
	~CObjHall() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

private:
	
	int m_map[HALL_HEIGHT][HALL_WIDTH];//�}�b�v���
};
