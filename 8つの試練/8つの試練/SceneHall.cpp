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

#define HERO_GRAPHIC (0) //主人公のグラフィック番号


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
	Draw::LoadImageW(L"主人公.png", HERO_GRAPHIC, TEX_SIZE_512);
	Draw::LoadImageW(L"広間の素材.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"広間の素材.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"エターナルパワーストーン.png", 3, TEX_SIZE_512);

	////主人公オブジェクト作成
	CObjHero* obj = new CObjHero(32,32);
	Objs::InsertObj(obj, OBJ_HERO, 2);
	//広間オブジェクト作成
	CObjHall* objh = new CObjHall();
	Objs::InsertObj(objh, OBJ_HALL,1);
	

}

//実行中メソッド
void CSceneHall::Scene()
{

}