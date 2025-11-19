#pragma once
#include"KamataEngine.h"
#include "PlayerBullet.h"

//Vector3とかMatrix4x4でエラーが出たらkamataEngineの#includeとusing namespaceが必要。
using namespace KamataEngine;

class Player 
{
public:
	//コンストラクタ
	Player();

	//デストラクタ
	~Player();

	//初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw(const Camera& camera);
	void Shoot();

private:
	
	WorldTransform worldTransform_;
	Model* model_ = nullptr;

	//プレイヤーの弾
	float x_, y_;
	std::vector<PlayerBullet*> bullets_;
	
	Vector3 startPos = {0.0f, 0.0f, 0.0f};
};
