//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneHall.h"
#include "GameHead.h"


//�R���X�g���N�^
CSceneHall::CSceneHall()
{

}

//�f�X�g���N�^
CSceneHall::~CSceneHall()
{

}

//���������\�b�h
void CSceneHall::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"��l��.png", 0, TEX_SIZE_512);

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"���̑f��.png", 1, TEX_SIZE_512);
}

//���s�����\�b�h
void CSceneHall::Scene()
{

}