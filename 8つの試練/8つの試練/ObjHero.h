#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

#define HERO_FRONT (0)//正面
#define HERO_BACK  (1)//背面
#define HERO_RIGHT (2)//右
#define HERO_LEFT  (3)//左


//オブジェクト : 主人公
class CObjHero : public CObj
{
public:
	CObjHero(float x, float y);
	~CObjHero() {};
	void Init();        //イニシャライズ
	void Action();      //アクション
	void Draw();        //ドロー

	float GetX();     //位置情報X取得用
	float GetY();     //位置情報Y取得用

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

};