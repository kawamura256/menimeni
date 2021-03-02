#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define HALL_WIDTH (35)
#define HALL_HEIGHT (35)

#define HALL_WALL (1)

//オブジェクト：ブロック＆背景
class CObjHall :public CObj
{
public:
	CObjHall() {};
	~CObjHall() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	
	int m_map[HALL_HEIGHT][HALL_WIDTH];//マップ情報
};
