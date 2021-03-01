//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

#include"ObjHero.h"


//使用するネームスペース
using namespace GameL;


//コンストラクタ
CObjHero::CObjHero(float x, float y)
{
	m_x = x;
	m_y = y;

}

//イニシャライズ
void CObjHero::Init()
{
	m_vx = 0.0f; //移動ベクトル
	m_vy = 0.0f; //移動ベクトル


	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);

}

//アクション
void CObjHero::Action()
{



}


//ドロー
void CObjHero::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;


}