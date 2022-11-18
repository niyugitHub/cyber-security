#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle() 
	{
		m_textPosY = 0;
		m_textVecY = 0;
		m_isEnd = false;
	}
	virtual ~SceneTitle() {}


	virtual void init()override;
	virtual void end() override {}

	virtual SceneBase* update()override;
	virtual void draw()override;

	virtual bool isEnd() { return m_isEnd; }

	// マウスと文字が当たった時
	bool HitString1();
	bool HitString2();
	bool HitString3();
private:
	// 画像ハンドル
	int m_handle;
	// テキスト表示位置変更
	int m_textPosY;
	int m_textVecY;

	// テキストのサイズ
	int m_textSize;

	// カラーの変更
	int m_RandColor;

	bool m_isEnd;
};