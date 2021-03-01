#pragma once
//使用するヘッダーファイル
#include "GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：広間
class CSceneHall :public CScene
{
public:
	CSceneHall();
	~CSceneHall();
	void InitScene();//初期化メソッド
	void Scene();//実行中メソッド
private:
};