#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define HALL_WIDTH (35)
#define HALL_HEIGHT (35)

#define HALL_WALL (1)
#define HALL_WALL2 (2)

#define WIDTH_32 (32)
#define WIDTH_64 (64)

//オブジェクト：ブロック＆背景
class CObjHall :public CObj
{
public:
	CObjHall() {};
	~CObjHall() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void SetScroll(float s) { mx_scroll = s; }
	float GetScroll() { return mx_scroll; }

	void SetScroll2(float s) { my_scroll = s; }
	float GetScroll2() { return my_scroll; }

private:
	
	int m_map[HALL_HEIGHT][HALL_WIDTH];//マップ情報

	float mx_scroll;
	float my_scroll;
};
