#include "SceneExplanation.h"
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


void SceneExplanation::init()
{
	m_RandColor = 0;

	// 画像番号
	m_handleNum = 0;
	
	// 画像のロード
	m_handle[0] = LoadGraph("data/enemy.png");
	m_handle[1] = LoadGraph("data/sumaho1.png");
	m_handle[2] = LoadGraph("data/sumaho3.png");
	m_handle[3] = LoadGraph("data/enemy.png");
	m_handle[4] = LoadGraph("data/enemy.png");

	m_handleCar = LoadGraph("data/enemy.png");
	
	m_IsPressMouse = false;
	m_IsPressedMouse = false;
	m_flag = false;

	m_isEnd = false;
	m_textSize = 50;
}

SceneBase* SceneExplanation::update()
{
	// 文字の移動

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//if (GetMouseInput() && MOUSE_INPUT_LEFT && HitString2())
	//{
	//	// Mainに切り替え
	//	return (new SceneMain);

	//}
	//
	IsPressMouse();

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitStringNext() && m_flag)
	{
		// 次の画像に切り替え
		m_handleNum++;
	}

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitStringBack() && m_flag)
	{
		// 次の画像に切り替え
		m_handleNum--;
	}

	if (m_handleNum < 0 || m_handleNum > 4)
	{
		// Titleに切り替え
		return (new SceneTitle);
	}

	if (m_RandColor < 200)
	{
		m_RandColor++;
	}

	//m_RandColor++;
	return this;
}

void SceneExplanation::draw()
{
	SetFontSize(30);

	DrawGraph(0 + m_handleNum * 100 , 0, m_handle[m_handleNum], true);

	if (m_handleNum < 4)
	{
		DrawString(Game::kScreenWidth - 150, Game::kScreenHeight - 50, "次へ進む", GetColor(0, 200, 0));
	}
	else
	{
		DrawString(Game::kScreenWidth - 150, Game::kScreenHeight - 50, "タイトル", GetColor(0, 200, 0));
	}

	if (HitStringNext() && m_handleNum < 4)
	{
		DrawString(Game::kScreenWidth - 150, Game::kScreenHeight - 50, "次へ進む", GetColor(255,255, 255));
	}
	else if (HitStringNext() && m_handleNum == 4)
	{
		DrawString(Game::kScreenWidth - 150, Game::kScreenHeight - 50, "タイトル", GetColor(255, 255, 255));
	}

	/*DrawString(50, Game::kScreenHeight - 50, "戻る", GetColor(0, 200, 0));*/
	if (m_handleNum > 0)
	{
		DrawString(50, Game::kScreenHeight - 50, "１つ戻る", GetColor(0, 200, 0));
	}
	else
	{
		DrawString(50, Game::kScreenHeight - 50, "タイトル", GetColor(0, 200, 0));
	}

	if (HitStringBack() && m_handleNum > 0)
	{
		DrawString(50, Game::kScreenHeight - 50, "１つ戻る", GetColor(255, 255, 255));
	}

	else if (HitStringBack() && m_handleNum == 0)
	{
		DrawString(50, Game::kScreenHeight - 50, "タイトル", GetColor(255, 255, 255));
	}

	DrawGraph(Mouse::getPos().x, Mouse::getPos().y, m_handleCar, true);
}

bool SceneExplanation::HitStringNext()
{
	if (Mouse::getPos().x > Game::kScreenWidth - 150 &&
		Mouse::getPos().x < Game::kScreenWidth - 30)
	{
		if (Mouse::getPos().y > Game::kScreenHeight - 50 &&
			Mouse::getPos().y < Game::kScreenHeight - 20)
		{
			return true;
		}
	}
	return false;
}

bool SceneExplanation::HitStringBack()
{
	if (Mouse::getPos().x > 50 &&
		Mouse::getPos().x < 170)
	{
		if (Mouse::getPos().y > Game::kScreenHeight - 50 &&
			Mouse::getPos().y < Game::kScreenHeight - 20)
		{
			return true;
		}
	}
	return false;
}

//bool SceneExplanation::HitString2()
//{
//	if (Mouse::getPos().x > kStringDisplayX &&
//		Mouse::getPos().x < kStringDisplayX + m_textSize * 10)
//	{
//		if (Mouse::getPos().y < kStringDisplayY - 50 &&
//			Mouse::getPos().y > kStringDisplayY - 100)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//bool SceneExplanation::HitString3()
//{
//	if (Mouse::getPos().x > kStringDisplayX &&
//		Mouse::getPos().x < kStringDisplayX + m_textSize * 10)
//	{
//		if (Mouse::getPos().y < kStringDisplayY + 50 &&
//			Mouse::getPos().y > kStringDisplayY)
//		{
//			return true;
//		}
//	}
//	return false;
//}

void SceneExplanation::IsPressMouse()
{

	if (GetMouseInput() && MOUSE_INPUT_LEFT)
	{
		m_IsPressMouse = true;
	}
	else {
		m_IsPressMouse = false;
	}

	if (!m_IsPressedMouse && m_IsPressMouse) {

		m_flag = true;

	}
	else {
		m_flag = false;
	}
	
	m_IsPressedMouse = m_IsPressMouse;
}