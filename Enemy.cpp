#include <Novice.h>
#include "Enemy.h"
#include "Collision.h"

// コンストラクタの定義
Enemy::Enemy(int posX, int posY, int radius, int speed,int isAlive) {
	// メンバ変数の初期化
	enemy_.x_ = posX;
	enemy_.y_ = posY;
	enemy_.radius_ = radius;
	enemy_.speed_ = speed;
	enemy_.isAlive_ = isAlive;
}

// デストラクタの定義
Enemy::~Enemy() {}

/// <summary>
/// 円を移動させ、壁に衝突で反射
/// </summary>
void Enemy::Update(char* keys, int bulletX, int bulletY, int bulletRadius) {
	if (enemy_.isAlive_) {
		enemy_.x_ += enemy_.speed_;

		if (enemy_.x_ < enemy_.radius_ || enemy_.x_ > 1280 - enemy_.radius_) {
			enemy_.speed_ *= -1;
		}

		 // 弾との当たり判定
		if (CheckCircleCollision(enemy_.x_, enemy_.y_, enemy_.radius_, bulletX, bulletY, bulletRadius)) {
			enemy_.isAlive_ = false;
		}

	}else {
		// 特定のキーでリセット
		if (keys[DIK_R]) {
			enemy_.isAlive_ = true;
		}
	}
}

/// <summary>
/// 円を描画する
/// </summary>
void Enemy::Draw() {
	if (enemy_.isAlive_) {
		Novice::DrawEllipse(enemy_.x_, enemy_.y_, enemy_.radius_, enemy_.radius_, 0.0f, RED, kFillModeSolid);
	}
}