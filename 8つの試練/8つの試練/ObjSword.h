#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：剣
class CObjSword : public CObj
{
public:
	CObjSword(float x, float y);
	~CObjSword() {};
	void Init();     //イニシャライズ
	void Action();  //アクション
	void Draw();   //ドロー

private:

};