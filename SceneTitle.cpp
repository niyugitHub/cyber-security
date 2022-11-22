#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneExplanation.h"
#include"game.h"

namespace
{
	constexpr int kStringDisplayX = Game::kScreenWidth / 2 - 500 / 2;
	constexpr int kStringDisplayY = Game::kScreenHeight / 2;
}


void SceneTitle::init()
{
//	m_RandColor = 0;
	m_handle = LoadGraph("data/enemy.png");
	m_isEnd = false;
	m_textSize = 50;
}

SceneBase* SceneTitle::update()
{
	// �����̈ړ�
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitString2())
	{
		// Main�ɐ؂�ւ�
		return (new SceneMain);
	
	}

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitString3())
	{
		// Main�ɐ؂�ւ�
		return (new SceneExplanation);
	}
	//if (padState & PAD_INPUT_1)
	//{
	//	// Main�ɐ؂�ւ�
	//	return (new SceneMain);
	//}
	
	//if (m_RandColor < 200)
	//{
	//	m_RandColor++;
	//}

	//m_RandColor++;
	return this;
}

void SceneTitle::draw()
{
	SetFontSize(50);
	DrawString(kStringDisplayX, kStringDisplayY - 200, "�E�C���X�o�X�^�[�Y�I", GetColor(0, 255, 0));
	DrawString(kStringDisplayX, kStringDisplayY - 100, "�Q�[���X�^�[�g", GetColor(0, 255, 0));
	DrawString(kStringDisplayX, kStringDisplayY , "�����т���", GetColor(0, 255, 0));

	/*if (Mouse::getPos().x > kStringDisplayX &&
		Mouse::getPos().x < kStringDisplayX + m_textSize * 10)
	{
		if (Mouse::getPos().y < kStringDisplayY -150 &&
			Mouse::getPos().y > kStringDisplayY - 200)
		{
			DrawString(kStringDisplayX, kStringDisplayY - 200, "�E�C���X�o�X�^�[�Y�I", GetColor(255, 255, 255));
		}
	}*/

	/*if (Mouse::getPos().x > kStringDisplayX &&
		Mouse::getPos().x < kStringDisplayX + m_textSize * 10)
	{
		if (Mouse::getPos().y < kStringDisplayY - 50 &&
			Mouse::getPos().y > kStringDisplayY - 100)
		{
			DrawString(kStringDisplayX, kStringDisplayY - 100, "�Q�[���X�^�[�g", GetColor(255, 255, 255));
		}
	}*/

	/*if (Mouse::getPos().x > kStringDisplayX &&
		Mouse::getPos().x < kStringDisplayX + m_textSize * 10)
	{
		if (Mouse::getPos().y < kStringDisplayY + 50 &&
			Mouse::getPos().y > kStringDisplayY)
		{
			DrawString(kStringDisplayX, kStringDisplayY, "�����т���", GetColor(255, 255, 255));
		}
	}*/
	if (HitString2())
	{
		DrawString(kStringDisplayX, kStringDisplayY - 100, "�Q�[���X�^�[�g", GetColor(255, 255, 255));
	}
	if (HitString3())
	{
		DrawString(kStringDisplayX, kStringDisplayY, "�����т���", GetColor(255, 255, 255));
	}


	DrawGraph(Mouse::getPos().x, Mouse::getPos().y, m_handle, true);

#if false
	// randcolor�̒l�̕\��
	DrawFormatString(0 , 0, GetColor(255,255,255),"%d", m_RandColor);
#endif
}

bool SceneTitle::HitString1()
{
	if (Mouse::getPos().x > kStringDisplayX &&
		Mouse::getPos().x < kStringDisplayX + m_textSize * 10)
	{
		if (Mouse::getPos().y < kStringDisplayY - 150 &&
			Mouse::getPos().y > kStringDisplayY - 200)
		{
			return true;		
		}
	}
	return false;
}
bool SceneTitle::HitString2()
{
	if (Mouse::getPos().x > kStringDisplayX &&
		Mouse::getPos().x < kStringDisplayX + m_textSize * 10)
	{
		if (Mouse::getPos().y < kStringDisplayY - 50 &&
			Mouse::getPos().y > kStringDisplayY - 100)
		{
			return true;
		}
	}
	return false;
}
bool SceneTitle::HitString3()
{
	if (Mouse::getPos().x > kStringDisplayX &&
		Mouse::getPos().x < kStringDisplayX + m_textSize * 10)
	{
		if (Mouse::getPos().y < kStringDisplayY + 50 &&
			Mouse::getPos().y > kStringDisplayY)
		{
			return true;
		}
	}
	return false;
}
