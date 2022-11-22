#pragma once
#include "SceneBase.h"

class SceneExplanation : public SceneBase
{
public:
	SceneExplanation()
	{
		m_isEnd = false;
	}
	virtual ~SceneExplanation() {}


	virtual void init()override;
	virtual void end() override {}

	virtual SceneBase* update()override;
	virtual void draw()override;

	virtual bool isEnd() { return m_isEnd; }

	// マウスと文字が当たった時
	bool HitStringNext();
	bool HitStringBack();
	/*bool HitString2();
	bool HitString3();*/

	// マウスを押した瞬間だけ機能を与える
	void IsPressMouse();
private:
	// 画像番号
	int m_handleNum;
	// 画像ハンドル
	int m_handleCar;
	int m_handle[5];

	// テキストのサイズ
	int m_textSize;

	// カラーの変更
	int m_RandColor;

	bool m_IsPressMouse;		// マウスボタンが押された瞬間だけtrueになるフラグ
	bool m_IsPressedMouse;	// マウスボタンが押されてフラグがtrueになったことがあるか
	bool m_flag;

	bool m_isEnd;
};