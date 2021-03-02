//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"

#include"ObjSword.h"


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjSword::CObjSword(float x, float y)//コンストラクタで受け取った情報を変数に送る
{
	pos.x = x;
	pos.y = y;
}


//イニシャライズ
void CObjSword::Init()
{
	vec.x = 0.0f;
	vec.y = 0.0f;

	angle_sword = 0;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, pos.x, pos.y, 25, 22, ELEMENT_PLAYER, OBJ_SWORD, 1);
}

//アクション
void CObjSword::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//剣のHitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を剣の位置に更新
	hit->SetPos(pos.x, pos.y);
}


//ドロー
void CObjSword::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定　
	src.m_top = 0.0f;   //y
	src.m_left = 0.0f;  //x
	src.m_right = 32.0f; //x 
	src.m_bottom = 32.0f; //y

	//表示位置の設定
	dst.m_top = (32.0f - 32.0f) + pos.y;//縦の位置変更
	dst.m_left = (32.0f * angle_sword) + pos.x;
	dst.m_right = (32.0f - 32.0f * angle_sword) +pos.x;
	dst.m_bottom = 32.0f + pos.y;

	Draw::Draw(3, &src, &dst, c, 0.0f);
}