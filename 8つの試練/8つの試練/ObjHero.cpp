//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

#include"ObjHero.h"
#include"math.h"


//使用するネームスペース
using namespace GameL;


//コンストラクタ
CObjHero::CObjHero(float x,float y)
{
	//位置情報初期化
	pos.x = x;
	pos.y  = y;
}

//イニシャライズ
void CObjHero::Init()
{
	//移動ベクトル
	vec.x = 0.0f;
	vec.y = 0.0f;

	//加速度
	acc.x = 0;
	acc.y = 0;

	m_x = 0.0f;
	m_y = 0.0f;

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

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0; // 踏んでいるblockの種類を確認用

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, pos.x, pos.y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{

	//移動ベクトル
	vec.x = 0.0f;
	vec.y = 0.0f;
	
	if (Input::GetVKey(VK_UP) == true)
	{
		vec.y -= HERO_YSPEED;
		m_direc = HERO_BACK;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		vec.y += HERO_YSPEED;
		m_direc = HERO_FRONT;
	}
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		vec.x += HERO_XSPEED;
		m_direc = HERO_RIGHT;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		vec.x -= HERO_XSPEED;
		m_direc = HERO_LEFT;
	}



	//移動
	 Move(&pos, &vec, acc);

	 //HitBoxの内容を更新
	 CHitBox* hit = Hits::GetHitBox(this); //作成したHitBox更新用の入り口を取り出す
	 hit->SetPos(pos.x, pos.y);            //入り口から新しい位置(主人公機の位置)情報に置き換える

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
	switch (m_direc)
	{
	case HERO_RIGHT:
		//切り取り位置の設定
		src.m_top = 64.0f;   //y
		src.m_left = 0.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_right = 32.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_bottom = 96.0f; //y
		break;
	case HERO_BACK:
		//切り取り位置の設定
		src.m_top = 32.0f;   //y
		src.m_left = 0.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_right = 32.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_bottom = 64.0f; //y
		break;
	case HERO_FRONT:
		//切り取り位置の設定
		src.m_top = 0.0f;   //y
		src.m_left = 0.0f + AniData1[m_ani_frame1] * 32.0f; //x
		src.m_right = 32.0f + AniData1[m_ani_frame1] * 32.0f; //x
		src.m_bottom = 32.0f; //y
		break;
	case HERO_LEFT:
		//切り取り位置の設定
		src.m_top = 96.0f;   //y
		src.m_left = 0.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_right = 32.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_bottom = 128.0f; //y
		break;
	}

	//表示位置の設定
	dst.m_top = 0.0f + pos.y;
	dst.m_left = 0.0f + pos.x;
	dst.m_right = 32.0f +pos.x;
	dst.m_bottom = 32.0f + pos.y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}