//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjHall.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHall::Init()
{
	//マップ情報
	int hall_data[10][100] =
	{

	};
	//マップデータコピー
	memcpy(m_map, hall_data, sizeof(int) * (10 * 100));
}

//アクション
void CObjHall::Action()
{
	
}

//ドロー
void CObjHall::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 2.0f;   //y
	src.m_left = 68.0f;  //x
	src.m_right = 124.0f; //x
	src.m_bottom = 54.0f; //y
	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 600;
	dst.m_bottom = 600;
	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] == 1)
			{

			}
		}
	}
}