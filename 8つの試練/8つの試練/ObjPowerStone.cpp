//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"
#include"GameHead.h"

#include"ObjPowerStone.h"


//使用するネームスペース
using namespace GameL;

//コンストラクタ                  　　位置　　パワーストーンの番号
CObjPowerStone::CObjPowerStone(float x, float y, int id)
{
	m_id = id;
}


//イニシャライズ
void CObjPowerStone::Init()
{
	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_POWERSTONE, 1);
}


//アクション
void CObjPowerStone::Action()
{
}


//ドロー
void CObjPowerStone::Draw()
{
	////描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 24.0f;   //y
	src.m_left = 30.0f; //x
	src.m_right = 226.0f; //x
	src.m_bottom = 222.0f; //y

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x ;
	dst.m_right = 32.0f + m_x ;
	dst.m_bottom = 32.0f + m_y;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
}
