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

	Point pos;//位置
	Vector vec;//移動ベクトル
	Vector acc;//加速度

private:

	int angle_sword;//剣の角度
};