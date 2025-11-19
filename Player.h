#pragma once
#include"KamataEngine.h"
#include <math/Vector3.h>
#include <3d/WorldTransform.h>
#include "PlayerBullet.h"

using namespace KamataEngine;

class Player 
{
public:
	//コンストラクタ
	Player();

	//デストラクタ
	~Player();

	//初期化
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const Vector3& position);
	// 更新
	void Update();
	// 描画
	void Draw();

private:
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::Camera* camera_ = nullptr;

	float x_, y_;
	std::vector<PlayerBullet*> bullets_;
	void Shoot();
};
