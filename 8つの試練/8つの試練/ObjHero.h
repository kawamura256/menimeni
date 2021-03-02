#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"

#include"math.h"
//使用するネームスペース
using namespace GameL;

#define HERO_FRONT (0)//正面
#define HERO_BACK  (1)//背面
#define HERO_RIGHT (2)//右
#define HERO_LEFT  (3)//左

#define HERO_XSPEED (5)//主人公の速度X
#define HERO_YSPEED (5)//主人公の速度Y

//オブジェクト : 主人公
class CObjHero : public CObj
{
public:
	CObjHero(float x,float y);
	~CObjHero() {};
	void Init();        //イニシャライズ
	void Action();      //アクション
	void Draw();        //ドロー

	Point pos;//位置
	Vector vec;//移動ベクトル
	Vector acc;//加速度

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	void SetX(float x);
	void SetY(float y);
	void SetX2(float x) { m_x = x; }
	void SetY2(float y) { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	int GetBT() { return m_block_type; }
	void SetBT(int t) { m_block_type = t; }

private:

	float m_x;  //主人公機のx方向移動用変数
	float m_y;  //主人公機のy方向移動用変数
	float m_vx; //移動ベクトル
	float m_vy; //移動ベクトル

	int m_direc; //主人公の向き

	//正面アニメーション
	int m_ani_time1; //アニメーションフレーム動作間隔
	int m_ani_frame1; //描画フレーム

	//背面アニメーション
	int m_ani_time2; //アニメーションフレーム動作間隔
	int m_ani_frame2; //描画フレーム

	//右アニメーション
	int m_ani_time3; //アニメーションフレーム動作間隔
	int m_ani_frame3; //描画フレーム

	//左アニメーション
	int m_ani_time4; //アニメーションフレーム動作間隔
	int m_ani_frame4; //描画フレーム

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int m_block_type;
};