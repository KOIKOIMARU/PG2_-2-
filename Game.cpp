#include "Game.h"
#include "SceneManager.h"
#include "Collision.h" 

// コンストラクタの定義
Game::Game() {
    player = new Player(640, 600, 30, 10,true);
    enemy1 = new Enemy(100, 100, 20, 10, true);
    enemy2 = new Enemy(300, 300, 20, 10, true);
}

// デストラクタの定義
Game::~Game() {
    // メモリの削除
    delete player;
    delete enemy1;
    delete enemy2;
}

/// <summary>
/// ゲームシーンの更新関数の定義
/// </summary>
/// <param name="keys">現在のキー</param>
/// <param name="preKeys">過去のキー</param>
void Game::Update(char* keys, char* preKeys) {

    // プレイヤーの更新処理
    player->Update(keys, preKeys);

    // 敵の更新処理
    enemy1->Update(keys, player->GetBulletX(), player->GetBulletY(), player->GetBulletRadius());
    enemy2->Update(keys, player->GetBulletX(), player->GetBulletY(), player->GetBulletRadius());

    // 敵が生きている場合のみ当たり判定を行う
    if ((enemy1->IsAlive() &&
        CheckCircleCollision(player->GetX(), player->GetY(), player->GetRadius(),
            enemy1->GetX(), enemy1->GetY(), enemy1->GetRadius())) ||
        (enemy2->IsAlive() &&
            CheckCircleCollision(player->GetX(), player->GetY(), player->GetRadius(),
                enemy2->GetX(), enemy2->GetY(), enemy2->GetRadius()))) {
        player->SetAlive(false);
    }

    // 敵が全滅したらゲームクリア
    if (!enemy1->IsAlive() && !enemy2->IsAlive()) {
        SceneManager::GetInstance()->ChangeScene(SCENE_GAMECLEAR);
    }else if(!player->IsAlive()) {
        // 当たったらゲームオーバー画面へ遷移
        SceneManager::GetInstance()->ChangeScene(SCENE_GAMEOVER);
    }
}

/// <summary>
/// ゲームシーンの描画関数の定義
/// </summary>
void Game::Draw() {
    player->Draw();
    enemy1->Draw();
    enemy2->Draw();
}
