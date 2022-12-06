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
}

SceneBase* SceneSelection::update()
{
	// •¶Žš‚ÌˆÚ“®

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	/*if (m_SetLevel > 0 && m_SetLevel < 4)
	{
		return (new SceneMain);
	}*/

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitStringEasy())
	{
		m_SetLevel = 1;
		// Main‚ÉØ‚è‘Ö‚¦
		SceneMain* a = (new SceneMain);
		a->setLevel(m_SetLevel);

		return a;
	}

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitStringNormal())
	{
		m_SetLevel = 2;
		// Main‚ÉØ‚è‘Ö‚¦
		SceneMain* a = (new SceneMain);
		a->setLevel(m_SetLevel);

		return a;

	}

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitStringHard())
	{
		m_SetLevel = 3;
		// Main‚ÉØ‚è‘Ö‚¦
		SceneMain* a = (new SceneMain);
		a->setLevel(m_SetLevel);

		return a;

	}
	return this;
}

void SceneSelection::draw()
{
	SetFontSize(m_textSize);

	Game::kScreenWidth / 2 - 500 / 2;
	Game::kScreenHeight / 2;


	DrawString(Game::kScreenWidth / 2 - 250 / 2, 100, "“ïˆÕ“x‘I‘ð", GetColor(0, 255, 0));

	DrawString(Game::kScreenWidth / 2 - 200 / 2, 300, "‚©‚ñ‚½‚ñ", GetColor(0, 255, 0));

	DrawString(Game::kScreenWidth / 2 - 150 / 2, 400, "‚Ó‚Â‚¤", GetColor(0, 255, 0));

	DrawString(Game::kScreenWidth / 2 - 250 / 2, 500, "‚Þ‚¸‚©‚µ‚¢", GetColor(0, 255, 0));

	if (HitStringEasy())
	{	
		DrawString(Game::kScreenWidth / 2 - 200 / 2, 300, "‚©‚ñ‚½‚ñ", GetColor(255, 255, 255));
	}

	if (HitStringNormal())
	{
		DrawString(Game::kScreenWidth / 2 - 150 / 2, 400, "‚Ó‚Â‚¤", GetColor(255, 255, 255));
	}

	if (HitStringHard())
	{
		DrawString(Game::kScreenWidth / 2 - 250 / 2, 500, "‚Þ‚¸‚©‚µ‚¢", GetColor(255, 255, 255));
	}
	DrawGraph(static_cast<int>(Mouse::getPos().x), static_cast<int>(Mouse::getPos().y), m_handleCar, true);
}

bool SceneSelection::HitStringEasy()
{
	if (Mouse::getPos().x > Game::kScreenWidth / 2 - 200 &&
		Mouse::getPos().x < Game::kScreenWidth / 2 + 200)
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
	if (Mouse::getPos().x > Game::kScreenWidth / 2 - 150 &&
		Mouse::getPos().x < Game::kScreenWidth / 2 + 150)
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
	if (Mouse::getPos().x > Game::kScreenWidth / 2 - 250 &&
		Mouse::getPos().x < Game::kScreenWidth / 2 + 250)
	{
		if (Mouse::getPos().y > 500 &&
			Mouse::getPos().y < 550)
		{
			return true;
		}
	}
	return false;
}