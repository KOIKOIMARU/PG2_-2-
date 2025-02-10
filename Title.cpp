#include "Title.h"

/// <summary>
/// タイトルシーンの更新関数の定義
/// </summary>
/// <param name="keys">現在のキー</param>
/// <param name="preKeys">過去のキー</param>
void Title::Update(char* keys, char* preKeys) {
    if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
        SceneManager::GetInstance()->ChangeScene(SCENE_GAME);
    }
}


/// <summary>
/// タイトルシーンの描画関数の定義
/// </summary>
void Title::Draw() {
    Novice::ScreenPrintf(500, 300, "Press SPACE to Start");
}