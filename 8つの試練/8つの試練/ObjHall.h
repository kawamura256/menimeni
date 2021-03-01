#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

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
	int m_map[10][100];//マップ情報(仮)
};
