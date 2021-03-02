#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�G�^�[�i���p���[�X�g�[���̗�
enum PowerStone
{
	RED_STONE,   //�Ԃ̃p���[�X�g�[��
	ORANGE_STONE,//��̃p���[�X�g�[��
	YELLOW_STONE,//���̃p���[�X�g�[��
	PINK_STONE,//���̃p���[�X�g�[��
	WATER_STONE,//���̃p���[�X�g�[��
	BLUE_STONE,//�̃p���[�X�g�[��
	PURPLE_STONE,//���̃p���[�X�g�[��
	GREEN_STONE,//�΂̃p���[�X�g�[��
};

//�I�u�W�F�N�g : �G�^�[�i���p���[�X�g�[��
class CObjPowerStone : public CObj
{
public:
	CObjPowerStone(float x, float y, int id);//�R���X�g���N�^�ʒu���	�����炤
	~CObjPowerStone() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[


private:

	float m_x; //Item��x�����̈ʒu
	float m_y; //Item��y�����̈ʒu

	int m_id;//�A�C�e������Id
};