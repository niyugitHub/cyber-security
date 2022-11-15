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
	// �����̈ړ�
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		// Main�ɐ؂�ւ�
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
	DrawString(Game::kScreenWidth / 2 - 500 / 2, Game::kScreenHeight / 2 - 200, "�E�C���X�o�X�^�[�Y�I", GetColor(0, m_RandColor, 0));
	DrawString(Game::kScreenWidth / 2 - 500 / 2, Game::kScreenHeight / 2 - 100, "�Q�[���X�^�[�g", GetColor(0, m_RandColor, 0));
	DrawString(Game::kScreenWidth / 2 - 500 / 2, Game::kScreenHeight / 2 , "�����т���", GetColor(0, m_RandColor, 0));
#if false
	// randcolor�̒l�̕\��
	DrawFormatString(0 , 0, GetColor(255,255,255),"%d", m_RandColor);
#endif
}
