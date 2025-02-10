#pragma once
#include "Struct.h"
#include "Bullet.h"

// 敵のクラス
class Enemy {
public:
    // コンストラクタ
    Enemy(int posX, int posY, int radius, int speed, int isAlive);

    // デストラクタ
    ~Enemy();

    /// <summary>
    /// 敵の更新関数の宣言
    /// </summary>
    /// <param name="keys">現在のキー</param>
    /// <param name="bulletX">弾の位置X</param>
    /// <param name="bulletY">弾の位置Y</param>
    /// <param name="bulletRadius">弾の半径</param>
    void Update(char* keys, int bulletX, int bulletY, int bulletRadius);

    /// <summary>
    /// 弾の描画関数の宣言
    /// </summary>
    void Draw();

    // ゲッター

    // 敵の位置の取得
    int GetX() const { return enemy_.x_; }
    int GetY() const { return enemy_.y_; }

    // 敵の半径の取得
    int GetRadius() const { return enemy_.radius_; }

    // 敵の生存状態の取得
    int IsAlive() const { return enemy_.isAlive_; }

    // セッター

    // 敵の生存状態のセット
    void SetAlive(int alive) { enemy_.isAlive_ = alive; }

private:
    // メンバ変数
    Transform enemy_;
    Bullet* bullet_;
};
