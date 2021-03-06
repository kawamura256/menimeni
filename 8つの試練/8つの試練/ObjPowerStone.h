#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//エターナルパワーストーンの列挙
enum PowerStone
{
	STONE_NONE,
	RED_STONE,   //赤のパワーストーン
	ORANGE_STONE,//橙のパワーストーン
	YELLOW_STONE,//黄のパワーストーン
	PINK_STONE,//桃のパワーストーン
	WATER_STONE,//水のパワーストーン
	BLUE_STONE,//青のパワーストーン
	PURPLE_STONE,//紫のパワーストーン
	GREEN_STONE,//緑のパワーストーン
	POWERSTONE_MAX
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
	static int stone_hold[POWERSTONE_MAX];//パワーストーンを保持する配列
};