//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjHall.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHall::Init()
{
	//�}�b�v���
	int hall_data[10][100] =
	{

	};
	//�}�b�v�f�[�^�R�s�[
	memcpy(m_map, hall_data, sizeof(int) * (10 * 100));
}

//�A�N�V����
void CObjHall::Action()
{
	
}

//�h���[
void CObjHall::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 2.0f;   //y
	src.m_left = 68.0f;  //x
	src.m_right = 124.0f; //x
	src.m_bottom = 54.0f; //y
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 600;
	dst.m_bottom = 600;
	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] == 1)
			{

			}
		}
	}
}