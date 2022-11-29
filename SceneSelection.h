#pragma once
#include "SceneBase.h"

class SceneSelection : public SceneBase
{
public:
	SceneSelection() :
		m_handleCar(-1),
		m_textSize(0),
		m_SetLevel(0)
	{
	}
	virtual ~SceneSelection() {}


	virtual void init()override;
	virtual void end() override {}

	virtual SceneBase* update()override;
	virtual void draw()override;

	void getLevel() { m_SetLevel; }

	// マウスと文字が当たった時
	bool HitStringEasy();
	bool HitStringNormal();
	bool HitStringHard();
	/*bool HitString2();
	bool HitString3();*/

private:
	// 画像ハンドル
	int m_handleCar;

	// テキストのサイズ
	int m_textSize;

	// 難易度設定
	int m_SetLevel;
};