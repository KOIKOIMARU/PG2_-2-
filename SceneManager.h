#pragma once
#include "Scene.h"

// シーンの列挙
enum SceneType {
    SCENE_TITLE,
    SCENE_GAME,
    SCENE_GAMEOVER,
    SCENE_GAMECLEAR
};

// シーン管理のクラス
class SceneManager {
public:
    // コンストラクタ
    SceneManager();
    // デストラクタ
    ~SceneManager();

    // シーン管理のインスタンス取得
    static SceneManager* GetInstance();

    /// <summary>
    /// シーンを変える関数の宣言
    /// </summary>
    /// <param name="newScene">次のシーン</param>
    void ChangeScene(SceneType newScene);

    /// <summary>
    /// シーン全体の更新関数の宣言
    /// </summary>
    /// <param name="keys">現在のキー</param>
    /// <param name="preKeys">過去のキー</param>
    void Update(char* keys, char* preKeys);

    /// <summary>
    /// シーン全体の描画関数の宣言
    /// </summary>
    void Draw();
private:
    // メンバ変数
    Scene* currentScene;
};
