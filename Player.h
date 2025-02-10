#pragma once
#include "Struct.h"
#include "Bullet.h"

class Player {
public:
    // コンストラクタ
    Player(int posX, int posY, int radius, int speed, int isAlive);

    // デストラクタ
    ~Player();

    /// <summary>
    /// 敵の更新関数の宣言
    /// </summary>
    /// <param name="keys"></param>
    /// <param name="preKeys"></param>
    void Update(char* keys, char* preKeys);

    /// <summary>
    /// 敵の描画関数の宣言
    /// </summary>
    void Draw();

    // ゲッター

    // 敵の位置の取得
    int GetX() const { return player_.x_; }
    int GetY() const { return player_.y_; }

    // 敵の半径の取得
    int GetRadius() const { return player_.radius_; }

    // 敵の生存状態の取得
    int IsAlive() const { return player_.isAlive_; }

    // 弾の位置の取得
    int GetBulletX() const { return bullet_->GetX(); }
    int GetBulletY() const { return bullet_->GetY(); }

    // 弾の半径の取得
    int GetBulletRadius() const { return bullet_->GetRadius(); }

    // セッター

    // 敵の生存状態のセット
    void SetAlive(int alive) { player_.isAlive_ = alive; }

private:
    // メンバ変数
    Transform player_;
    Bullet* bullet_;
};
