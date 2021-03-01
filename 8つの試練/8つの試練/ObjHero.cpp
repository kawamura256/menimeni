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

	m_direc = HERO_FRONT;

	//正面アニメーション
	m_ani_time1 = 0; //アニメーションフレーム動作間隔
	m_ani_frame1 = 0; //静止フレームを初期にする

	//背面アニメーション
	m_ani_time2 = 0; //アニメーションフレーム動作間隔
	m_ani_frame2 = 0; //静止フレームを初期にする

	//右アニメーション
	m_ani_time3 = 0; //アニメーションフレーム動作間隔
	m_ani_frame3 = 0; //静止フレームを初期にする

	//左アニメーション
	m_ani_time4 = 0; //アニメーションフレーム動作間隔
	m_ani_frame4 = 0; //静止フレームを初期にする

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

	int AniData1[3] = //正面向き情報を登録
	{
		0,1,2,
	};
	int AniData2[3] = //背面向き情報を登録
	{
		0,1,2,
	};
	int AniData3[2] = //右向き情報を登録
	{
		0,1,
	};
	int AniData4[2] = //左向き情報を登録
	{
		0,1,
	};

	//主人公
	if (m_direc == HERO_RIGHT) //右
	{

		//切り取り位置の設定
		src.m_top = 64.0f;   //y
		src.m_left = 0.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_right = 32.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_bottom = 96.0f; //y


	}
	if (m_direc ==HERO_BACK) //後ろ
	{
		//切り取り位置の設定
		src.m_top = 32.0f;   //y
		src.m_left = 0.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_right = 32.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_bottom = 64.0f; //y
	}

	if (m_direc == HERO_FRONT) //前
	{
		//切り取り位置の設定
		src.m_top = 0.0f;   //y
		src.m_left = 0.0f + AniData1[m_ani_frame1] * 32.0f; //x
		src.m_right = 32.0f + AniData1[m_ani_frame1] * 32.0f; //x
		src.m_bottom = 32.0f; //y
	}

	if (m_direc == HERO_LEFT)//左
	{
		//切り取り位置の設定
		src.m_top = 96.0f;   //y
		src.m_left = 0.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_right = 32.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_bottom = 128.0f; //y
	}

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}