#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include"game.h"


void SceneTitle::init()
{
	m_textPosY = 0;
	m_textVecY = 4;
	m_RandColor = 0;

	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	// 文字の移動
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		// Mainに切り替え
		return (new SceneMain);
	}
	
	if (m_RandColor < 200)
	{
		m_RandColor++;
	}

	//m_RandColor++;
	return this;
}

void SceneTitle::draw()
{
	SetFontSize(50);
	DrawString(Game::kScreenWidth / 2 - 500 / 2, Game::kScreenHeight / 2 - 200, "ウイルスバスターズ！", GetColor(0, m_RandColor, 0));
	DrawString(Game::kScreenWidth / 2 - 500 / 2, Game::kScreenHeight / 2 - 100, "ゲームスタート", GetColor(0, m_RandColor, 0));
	DrawString(Game::kScreenWidth / 2 - 500 / 2, Game::kScreenHeight / 2 , "あそびかた", GetColor(0, m_RandColor, 0));
#if false
	// randcolorの値の表示
	DrawFormatString(0 , 0, GetColor(255,255,255),"%d", m_RandColor);
#endif
}
