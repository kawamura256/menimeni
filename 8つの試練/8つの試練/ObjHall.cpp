//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/SceneObjManager.h"

#include "GameHead.h"
#include "ObjHall.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHall::Init()
{
	//マップ情報
	int hall_data[HALL_HEIGHT][HALL_WIDTH] =
	{
	    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	//マップデータコピー
	memcpy(m_map, hall_data, sizeof(int) * (HALL_HEIGHT * HALL_WIDTH));
}

//アクション
void CObjHall::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	hero->SetBT(0);

	//主人公の衝突状態確認用フラグの初期化
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//m_mapの全要素にアクセス
	for (int i = 0; i < HALL_HEIGHT; i++)
	{
		for (int j = 0; j < HALL_WIDTH; j++)
		{
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float x = j * 24.0f;
				float y = i * 24.0f;

				//主人公とブロックの当たり判定
				if ((hx + (-mx_scroll)+64.0f > x) && (hx +(-mx_scroll)< x + 64.0f) && (hy + (-my_scroll)+64.0f > y) && (hy + (-my_scroll) < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx+(-mx_scroll)) - x;
					float vy = (hy + (-my_scroll))-y;

					//長さを求める
					float len = sqrt(vx * vx + vy * vy);

					//角度を求める
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 44.4f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							hero->SetRight(true);//主人公から見て、左の部分が衝突している
							hero->SetX2(x + 40.0f+(mx_scroll));//ブロックの位置-主人公の幅
							if (m_map[i][j] == 0)
							hero->SetBT(m_map[i][j]);
							hero->SetVX(0.0f); //-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公から見て、下の部分が衝突している
							hero->SetY2(y - 40.0f+(my_scroll));//ブロックの位置-主人公の幅
							if(m_map[i][j]==0)
							hero->SetBT(m_map[i][j]);
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公から見て、右の部分が衝突している
							hero->SetX2(x - 40.0f + (mx_scroll));//ブロックの位置-主人公の幅
							if (m_map[i][j] == 0)
							hero->SetBT(m_map[i][j]);
							hero->SetVX(0.0f); //-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);//主人公から見て、上の部分が衝突している
							hero->SetY2(y + 40.0f + (my_scroll));//ブロックの位置-主人公の幅
							if (m_map[i][j] == 0)
							hero->SetBT(m_map[i][j]);
							hero->SetVY(0.0f);
						}
						
					}
				}
			}
		}
	}
}

//ドロー
void CObjHall::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	
	//切り取り位置の設定
	src.m_top = 1.0f;   //y
	src.m_left = 1.0f;  //x
	src.m_right = 2.0f; //
	src.m_bottom = 2.0f; //y

	//表示位置の設定
	dst.m_top  =  0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom =600.0f;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
	

	for (int i = 0; i < HALL_HEIGHT; i++)
	{
		for (int j = 0; j < HALL_WIDTH; j++)
		{
			
			if (m_map[i][j] == HALL_WALL)
			{
				//切り取り位置の設定
				src.m_top = 2.0f;   //y
				src.m_left = 68.0f;  //x
				src.m_right = 124.0f; //x
				src.m_bottom = 54.0f; //y
				//表示位置の設定
				dst.m_top = i*24.0f;
				dst.m_left = j*24.0f;
				dst.m_right = j*24.0f+ 24.0f;
				dst.m_bottom = i*24.0f+24.0f;

				//描画
				Draw::Draw(1, &src, &dst, c, 0.0f);

			}
		}
	}
}