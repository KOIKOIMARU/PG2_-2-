#pragma once
#include "Scene.h"
#include "SceneManager.h"

// ゲームオーバーシーンのクラス
class GameOver : public Scene {
public:
    /// <summary>
    /// ゲームオーバーシーンの更新関数の宣言
    /// </summary>
    /// <param name="keys">現在のキー</param>
    /// <param name="preKeys">過去のキー</param>
    void Update(char* keys, char* preKeys) override;

    /// <summary>
    /// ゲームオーバーシーンの描画関数の宣言
    /// </summary>
    void Draw() override;
};
