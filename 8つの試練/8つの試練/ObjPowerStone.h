#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

enum PowerStone
{
	RED_STONE,//赤のパワーストーン

};

//オブジェクト : エターナルパワーストーン
class CObjPowerStone : public CObj
{
public:
	CObjPowerStone(float x, float y, int id);//コンストラクタ位置情報	をもらう
	~CObjPowerStone() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー


private:

	float m_x; //Itemのx方向の位置
	float m_y; //Itemのy方向の位置

	int m_id;//アイテム識別Id
};