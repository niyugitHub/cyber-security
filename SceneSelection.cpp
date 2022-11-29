#include "SceneSelection.h"
#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "Mouse.h"
#include"game.h"

namespace
{
	constexpr int kStringDisplayX = Game::kScreenWidth / 2 - 500 / 2;
	constexpr int kStringDisplayY = Game::kScreenHeight / 2;
}


void SceneSelection::init()
{
	m_textSize = 50;

	m_handleCar = LoadGraph("data/enemy.png");
}

SceneBase* SceneSelection::update()
{
	// 文字の移動

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitStringEasy())
	{
		m_SetLevel = 1;
		// Mainに切り替え
		return (new SceneMain);

	}

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitStringNormal())
	{
		m_SetLevel = 2;
		// Mainに切り替え
		return (new SceneMain);

	}

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitStringHard())
	{
		m_SetLevel = 3;
		// Mainに切り替え
		return (new SceneMain);

	}
	return this;
}

void SceneSelection::draw()
{
	SetFontSize(m_textSize);

	DrawString(500, 100, "難易度選択", GetColor(0, 255, 0));

	DrawString(500, 300, "かんたん", GetColor(0, 255, 0));

	DrawString(500, 400, "ふつう", GetColor(0, 255, 0));

	DrawString(500, 500, "むずかしい", GetColor(0, 255, 0));

	if (HitStringEasy())
	{
		DrawString(500, 300, "かんたん", GetColor(255, 255, 255));
	}

	if (HitStringNormal())
	{
		DrawString(500, 400, "ふつう", GetColor(255, 255, 255));
	}

	if (HitStringHard())
	{
		DrawString(500, 500, "むずかしい", GetColor(255, 255, 255));
	}
	DrawGraph(static_cast<int>(Mouse::getPos().x), static_cast<int>(Mouse::getPos().y), m_handleCar, true);
}

bool SceneSelection::HitStringEasy()
{
	if (Mouse::getPos().x > 500 &&
		Mouse::getPos().x < 700)
	{
		if (Mouse::getPos().y > 300 &&
			Mouse::getPos().y < 350)
		{
			return true;
		}
	}
	return false;
}

bool SceneSelection::HitStringNormal()
{
	if (Mouse::getPos().x > 500 &&
		Mouse::getPos().x < 650)
	{
		if (Mouse::getPos().y > 400 &&
			Mouse::getPos().y < 450)
		{
			return true;
		}
	}
	return false;
}

bool SceneSelection::HitStringHard()
{
	if (Mouse::getPos().x > 500 &&
		Mouse::getPos().x < 750)
	{
		if (Mouse::getPos().y > 500 &&
			Mouse::getPos().y < 550)
		{
			return true;
		}
	}
	return false;
}