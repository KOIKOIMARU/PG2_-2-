#include "GameClear.h"

/// <summary>
/// ゲームクリアシーンの更新関数の宣言
/// </summary>
/// <param name="keys">現在のキー</param>
/// <param name="preKeys">過去のキー</param>
void GameClear::Update(char* keys, char* preKeys) {
    // 特定のキーを押したらシーンを変える
    if (preKeys[DIK_R] == 0 && keys[DIK_R] != 0) {
        SceneManager::GetInstance()->ChangeScene(SCENE_TITLE);
    }
}

/// <summary>
/// ゲームクリアシーンの描画関数の宣言
/// </summary>
void GameClear::Draw() {
    Novice::ScreenPrintf(500, 300, "Congratulations! You Win!");
    Novice::ScreenPrintf(500, 350, "Press R to Return to Title");
}
