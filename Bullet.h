#pragma once
#include "Struct.h"

// 弾のクラス
class Bullet {
public:
    // コンストラクタ
    Bullet(int posX, int posY, int radius, int speed, int isShot);

    // デストラクタ
    ~Bullet() = default;

    /// <summary>
    /// 弾の更新関数の宣言
    /// </summary>
    void Update();

    /// <summary>
    /// 弾の描画関数の宣言
    /// </summary>
    void Draw();

    // ゲッター

    // 弾の位置を取得
    int GetX() const { return bullet_.x_; }
    int GetY() const { return bullet_.y_; }
    // 弾の半径を取得
    int GetRadius() const { return bullet_.radius_; }
    // 弾の発射フラグの取得
    int IsShot() const { return isShot_; }

    // セッター

    // 弾の位置に代入
    void SetX(int x) { bullet_.x_ = x; }
    void SetY(int y) { bullet_.y_ = y; }

    // 発射フラグの処理
    void SetShot(bool shot) { isShot_ = shot; }

private:
    // メンバ変数
    Transform bullet_;
    int isShot_;  
};
