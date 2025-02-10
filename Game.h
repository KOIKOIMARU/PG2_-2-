#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"

// ゲームシーンのクラス
class Game : public Scene {
public: 

    // コンストラクタ
    Game();
    // デストラクタ
    ~Game();

    /// <summary>
    /// ゲームシーンの更新関数の宣言
    /// </summary>
    /// <param name="keys">現在のキー</param>
    /// <param name="preKeys">過去のキー</param>
    void Update(char* keys, char* preKeys) override;

    /// <summary>
    /// ゲームシーンの描画関数の宣言
    /// </summary>
    void Draw() override;

public:
    // メンバ変数
    Player* player;
    Enemy* enemy1;
    Enemy* enemy2;
};
