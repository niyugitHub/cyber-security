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

	// �摜�ԍ�
	m_handleNum = 0;
	
	// �摜�̃��[�h
	m_handle[0] = LoadGraph("data/enemy.png");
	m_handle[1] = LoadGraph("data/enemy.png");
	m_handle[2] = LoadGraph("data/enemy.png");
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
	// �����̈ړ�

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitString2())
	{
		// Main�ɐ؂�ւ�
		return (new SceneMain);

	}
	
	IsPressMouse();

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitStringNext() && m_flag)
	{
		// ���̉摜�ɐ؂�ւ�
		m_handleNum++;
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

	DrawString(Game::kScreenWidth - 150, Game::kScreenHeight - 50, "���֐i��", GetColor(0, 200, 0));

	if (HitStringNext())
	{
		DrawString(Game::kScreenWidth - 150, Game::kScreenHeight - 50, "���֐i��", GetColor(255,255, 255));
	}
	DrawGraph(Mouse::getPos().x, Mouse::getPos().y, m_handleCar, true);
}

bool SceneExplanation::HitStringNext()
{
	if (Mouse::getPos().x > Game::kScreenWidth - 150 &&
		Mouse::getPos().x < Game::kScreenWidth - 60)
	{
		if (Mouse::getPos().y > Game::kScreenHeight - 50 &&
			Mouse::getPos().y < Game::kScreenHeight - 20)
		{
			return true;
		}
	}
	return false;
}
bool SceneExplanation::HitString2()
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
bool SceneExplanation::HitString3()
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