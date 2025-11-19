#include "Player.h"
//#include <input/Input.h>
#include <cassert>
using namespace KamataEngine;
using namespace MathUtility;
Player::Player() 
{

}

Player::~Player() 
{
	delete model_;
}

//初期化
void Player::Initialize() 
{
	//モデル
	model_ = Model::CreateFromOBJ("player", true);
	
	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = startPos; // 初期配置

	//プレイヤーの弾の初期化
	x_ = 300;
	y_ = 400;

}

// 更新
void Player::Update() 
{
	const float speed = 1.0f;

	// 入力取得
	Input* input = Input::GetInstance();

	if (input->PushKey(DIK_W)) {
		worldTransform_.translation_.y += speed;
	}
	if (input->PushKey(DIK_S)) {
		worldTransform_.translation_.y -= speed;
	}
	if (input->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= speed;
	}
	if (input->PushKey(DIK_D)) {
		worldTransform_.translation_.x += speed;
	}

	worldTransform_.scale_ = {5.0f, 5.0f, 5.0f};
	worldTransform_.rotation_ = {0, 90, 0};
	// ワールド変換を更新
	worldTransform_.UpdateMatrix();
}

//描画
void Player::Draw(const Camera& camera) {
	 model_->Draw(worldTransform_, camera);
	for (auto& b : bullets_) {
		b->Draw(camera);
	}
}

//プレイヤーの弾
void Player::Shoot() 
{
	// SPACE キーで弾を撃つ
	if (Input::GetInstance()->TriggerKey(DIK_SPACE))
	{
		PlayerBullet* newBullet = new PlayerBullet;
		newBullet->Initialize(worldTransform_.translation_);
		bullets_.push_back(newBullet);
	}

	// 弾更新
	for (auto& b : bullets_) {
		b->Update();
	}
}
