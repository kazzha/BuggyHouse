#pragma once
#include "Actor.h"
class Bug : public Actor
{
	const D2D_POINT_2F UPVECTOR{ 0.0f, -1.0f }; // 길이가 1인 벡터 = 단위벡터 (회전에만 쓸 것이기 때문)
	float mRotation;
	float mSteps;

public:
	bool mIsDead;

public:
	Bug(D2DFramework* pFramework);

	virtual void Draw() override;

	bool IsClicked(POINT& pt);
};

