#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define HALL_WIDTH (35)
#define HALL_HEIGHT (35)

#define HALL_WALL (1)
#define HALL_WALL2 (2)

#define WIDTH_32 (32)
#define WIDTH_64 (64)

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjHall :public CObj
{
public:
	CObjHall() {};
	~CObjHall() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void SetScroll(float s) { mx_scroll = s; }
	float GetScroll() { return mx_scroll; }

	void SetScroll2(float s) { my_scroll = s; }
	float GetScroll2() { return my_scroll; }

private:
	
	int m_map[HALL_HEIGHT][HALL_WIDTH];//�}�b�v���

	float mx_scroll;
	float my_scroll;
};
