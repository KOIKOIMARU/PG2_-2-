#pragma once
#include <Novice.h>

// シーンの基底クラス
class Scene {
public:

    // 仮想コンストラクタ
    virtual ~Scene() {}

    /// <summary>
    /// シーン全体の更新関数の宣言
    /// </summary>
    /// <param name="keys">現在のキー</param>
    /// <param name="preKeys">過去のキー</param>
    virtual void Update(char* keys, char* preKeys) = 0;

    /// <summary>
    /// シーン全体の描画関数の宣言
    /// </summary>
    virtual void Draw() = 0;
};