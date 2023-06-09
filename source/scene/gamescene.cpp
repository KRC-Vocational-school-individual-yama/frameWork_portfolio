#include "gamescene.h"

#include<DxLib.h>
#include"../libs/frameWork/scenemanager.h"
#include"../object/gameSceneObject.h"


GameScene::GameScene(){
	SetBackgroundColor(0xe5,0xff,0xff);

	Create<GameSceneObject>("gameSceneObject");

}

GameScene::~GameScene(){
}

//ToDo:後で消す
//------------------------------------------------------------------

namespace { 
	bool keystop = true;

	void BackScene() {
		bool backKey = CheckHitKey(KEY_INPUT_ESCAPE);
		bool keyDown = backKey && !keystop;
		keystop = backKey;

		if (keyDown) {
			SceneManager::SceneChange("Title");
		}

	}
}
void GameScene::Update(){
	Scene::Update();

	BackScene(); 
}
void GameScene::Draw() {
	Scene::Draw();

	
#ifdef _DEBUG 
	DrawFormatString(100,100,0x0,"GameScene\nEscapeで戻る");
#endif

}