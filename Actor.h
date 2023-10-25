#pragma once

#include "D2DFramework.h"
#include "BitmapManager.h"

class Actor
{
protected:
	D2DFramework* mpFramework; // weak ptr처럼 쓰는 것. new나 delete하면 안 됨

	ID2D1Bitmap* mpBitmap;

	float mX;
	float mY;
	float mOpacity;

public:
	Actor() = delete; // 기본생성자가 지워짐
	Actor(D2DFramework* pFramework, LPCWSTR filename);
	Actor(D2DFramework* pFramework, LPCWSTR filename, float x, float y, float opacity = 1.0f);

	virtual ~Actor();

private:
	void Draw(float x, float y, float opacity = 1.0f);

public:
	virtual void Draw(); // 두 개로 나눠 놓는게 유리(?)
	inline D2D_VECTOR_2F GetPosition() const { return { mX, mY }; }
	inline void SetPosition(const D2D_VECTOR_2F& pos ) { mX = pos.x; mY = pos.y; }
	inline void SetPosition(float x, float y) { mX = x; mY = y; }
};

