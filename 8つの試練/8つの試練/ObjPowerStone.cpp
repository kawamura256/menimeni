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
	if (m_id == RED_STONE)
	{
		m_x = x;
		m_y = y;
	}
}


//イニシャライズ
void CObjPowerStone::Init()
{

	if (m_id == RED_STONE) 
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_POWERSTONE, 1);
	}
}



//アクション
void CObjPowerStone::Action()
{
	CObjHall* hall = (CObjHall*)Objs::GetObj(OBJ_HALL);

	if (m_id == RED_STONE)
	{
		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x+hall->GetScroll(), m_y + hall->GetScroll2());

		//主人公と接触しているかどうか調べる
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
}


//ドロー
void CObjPowerStone::Draw()
{
	CObjHall* hall = (CObjHall*)Objs::GetObj(OBJ_HALL);

	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;   //y
	src.m_left = 5.0f; //x
	src.m_right = 58.0f; //x
	src.m_bottom = 55.0f; //y



	switch (m_id)
	{
	case RED_STONE:

		//表示位置の設定
		dst.m_top = 0.0f + m_y+hall->GetScroll2();
		dst.m_left = 0.0f + m_x + hall->GetScroll();
		dst.m_right = 32.0f + m_x + hall->GetScroll();
		dst.m_bottom = 32.0f + m_y + hall->GetScroll2();
		//描画
		Draw::Draw(3, &src, &dst, c, 0.0f);
		break;
	case ORANGE_STONE:
		break;
	}

}
