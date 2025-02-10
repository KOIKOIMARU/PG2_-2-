#include "SceneManager.h"
#include "Title.h"
#include "Game.h"
#include "GameOver.h"
#include "GameClear.h"

// コンストラクタの定義
SceneManager::SceneManager() {
    currentScene = new Title();
}

// デストラクタの定義
SceneManager::~SceneManager() {
    delete currentScene;
}

// シーン管理のインスタンスを取得
SceneManager* SceneManager::GetInstance() {
    static SceneManager instance;
    return &instance;
}

/// <summary>
/// シーンを変える関数の定義
/// </summary>
/// <param name="newScene">次のシーン</param>
void SceneManager::ChangeScene(SceneType newScene) {
    delete currentScene;

    // シーン切り替え
    switch (newScene) {
    case SCENE_TITLE:
        currentScene = new Title();
        break;
    case SCENE_GAME:
        currentScene = new Game();
        break;
    case SCENE_GAMEOVER:
        currentScene = new GameOver();
        break;
    case SCENE_GAMECLEAR:
        currentScene = new GameClear();
        break;
    }
}

/// <summary>
/// シーンの更新関数の定義
/// </summary>
/// <param name="keys">現在のキー</param>
/// <param name="preKeys">過去のキー</param>
void SceneManager::Update(char* keys, char* preKeys) {
    currentScene->Update(keys, preKeys);
}

/// <summary>
/// シーンの描画関数の定義
/// </summary>
void SceneManager::Draw() {
    currentScene->Draw();
}
