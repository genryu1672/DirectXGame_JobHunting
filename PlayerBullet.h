#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

class PlayerBullet 
{
public:
	void Initialize(Vector3 pos);

	void Update();
	
	void Draw(const KamataEngine::Camera& camera);

private:
	std::unique_ptr<Model> model_;//ユニークポインターやシャードポインタにすると、デリートしなくて良い
	WorldTransform worldtransform_;

	Vector3 move_;
};
