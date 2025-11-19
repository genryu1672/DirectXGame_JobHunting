#include "PlayerBullet.h"
using namespace MathUtility;
void PlayerBullet::Initialize(Vector3 pos) {
	
	//弾のモデル描画
	model_ = std::unique_ptr<Model>(Model::CreateFromOBJ("cube"));
	worldtransform_.Initialize();
	worldtransform_.translation_ = pos;

	move_ = Vector3(0.2f, 0.0f, 0.0f);
}

void PlayerBullet::Update() { 
	worldtransform_.translation_ += move_; 
	worldtransform_.UpdateMatrix();
}

void PlayerBullet::Draw(const KamataEngine::Camera& camera) {
	model_->Draw(worldtransform_, camera); 
}