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
	Draw::LoadImageW(L"�L�Ԃ̑f��.png", 1, TEX_SIZE_512);

	////��l���I�u�W�F�N�g�쐬
	//CObjHero* obj = new CObjHero();
	//Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjHall* objh = new CObjHall();
	Objs::InsertObj(objh, OBJ_HALL, 9);

}

//���s�����\�b�h
void CSceneHall::Scene()
{

}