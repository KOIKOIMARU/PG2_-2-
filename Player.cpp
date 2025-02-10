#include <Novice.h>
#include "Player.h"

// コンストラクタの定義
Player::Player(int posX, int posY, int radius, int speed,int isAlive) {
	// メンバ変数の初期化
	player_.x_ = posX;
	player_.y_ = posY;
	player_.radius_ = radius;
	player_.speed_ = speed;
	player_.isAlive_ = isAlive;
	// 弾クラスの実体を生成
	bullet_ = new Bullet(0, 0, 10, 5, true);
}

// デストラクタの定義
Player::~Player() {
	// ポインタ削除
	delete bullet_;
}

/// <summary>
/// プレイヤーを更新させる関数
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前のキー</param>
void Player::Update(char* keys, char* preKeys) {
	// 生存してる時だけ処理
	if (player_.isAlive_) {
		// 移動処理
		if (keys[DIK_W]) {
			player_.y_ -= player_.speed_;
		}
		if (keys[DIK_S]) {
			player_.y_ += player_.speed_;
		}
		if (keys[DIK_D]) {
			player_.x_ += player_.speed_;
		}
		if (keys[DIK_A]) {
			player_.x_ -= player_.speed_;
		}

		// 発射処理
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !bullet_->IsShot()) {
			bullet_->SetX(player_.x_);
			bullet_->SetY(player_.y_);
			bullet_->SetShot(true);
		}

		// 弾の更新関数の呼び出し
		bullet_->Update();
	}
}

/// <summary>
/// プレイヤーを描画させる関数
/// </summary>
void Player::Draw() {
	if (player_.isAlive_) {
		Novice::DrawEllipse(
			player_.x_, player_.y_,
			player_.radius_, player_.radius_,
			0.0f, WHITE, kFillModeSolid);

		// 弾の描画関数の呼び出し
		bullet_->Draw();
	}
}