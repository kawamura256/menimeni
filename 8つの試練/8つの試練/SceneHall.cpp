//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneHall.h"
#include "GameHead.h"


//コンストラクタ
CSceneHall::CSceneHall()
{

}

//デストラクタ
CSceneHall::~CSceneHall()
{

}

//初期化メソッド
void CSceneHall::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImageW(L"主人公.png", 0, TEX_SIZE_512);

	//グラフィック読み込み
	Draw::LoadImageW(L"島の素材.png", 1, TEX_SIZE_512);
}

//実行中メソッド
void CSceneHall::Scene()
{

}