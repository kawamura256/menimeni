#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
//使用するネームスペース
using namespace GameL;

#define SWORD_FLONT (0)
#define SWORD_BACK (1)
#define SWORD_RIGHT (2)
#define SWORD_LEFT (3)

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