#include "GameOver.h"

/// <summary>
/// ゲームオーバーシーンの描画関数の定義
/// </summary>
/// <param name="keys">現在のキー</param>
/// <param name="preKeys">過去のキー</param>
void GameOver::Update(char* keys, char* preKeys) {
    if (preKeys[DIK_R] == 0 && keys[DIK_R] != 0) {
        SceneManager::GetInstance()->ChangeScene(SCENE_TITLE);
    }
}

/// <summary>
/// ゲームオーバーシーンの描画関数の定義
/// </summary>
void GameOver::Draw() {
    Novice::ScreenPrintf(500, 300, "Game Over! Press R to Return to Title");
}
