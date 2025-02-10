#include <Novice.h>
#include "Bullet.h"

// コンストラクタの定義
Bullet::Bullet(int posX, int posY, int radius, int speed, int isShot) {
	// メンバ変数の初期化
	bullet_.x_ = posX;
	bullet_.y_ = posY;
	bullet_.radius_ = radius;
	bullet_.speed_ = speed;
	isShot_ = isShot;
}

/// <summary>
/// 弾を更新させる関数
/// </summary>
void Bullet::Update() {
	if (isShot_) {
		bullet_.y_ -= bullet_.speed_;
		if (bullet_.y_ <= 0 - bullet_.radius_) {
			isShot_ = false;
		}
	}
}

/// <summary>
/// 弾を描画させる関数
/// </summary>
void Bullet::Draw() {
	Novice::DrawEllipse(
		bullet_.x_, bullet_.y_,
		bullet_.radius_, bullet_.radius_,
		0.0f, WHITE, kFillModeSolid);
}
