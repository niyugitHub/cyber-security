#include "enemyHard.h"

#include "enemyNormal.h"
#include"Dxlib.h"
#include"game.h"
#include"Mouse.h"
#include<math.h>
#include <cassert>
namespace
{
	// 敵のスピードを設定
	constexpr float kSpeed = 5.0f;

	// 中心座標を設定
	constexpr int CentorX = static_cast<float>(Game::kScreenWidth / 2) - 50;
	constexpr float CentorY = static_cast<float>(Game::kScreenHeight / 2) - 50;

	// サイズ
	constexpr int kEnemySize = 100;
	Vec2 Centor{ CentorX, CentorY };
	//Vec2 temp{ x + vec.x, y + vec.y };

	// 拡大or縮小のとき10f止める
	constexpr int kWaitFlame = 25;

	constexpr float kMovewave = 0.2f;
	constexpr int kMovetime = 20;
}

enemyHard::enemyHard() :
	m_hGraph(-1),
	m_isExist(false),
	m_pos(),
	m_vec(3, 3),
	m_click(),
	m_rot(),
	m_IsPressMouse(false),
	m_IsPressedMouse(false),
	m_EnemyFlame(GetRand(1200) + 50),
	m_ExtRate(1.0f),
	// 拡大率の変化
	m_Expansion(0.01f),
	// 拡大or縮小のとき10f止める
	m_StopFlame(50),
	m_MoveTime(-kMovetime),
	m_Flame(1),
	m_gravitySpeed(0)

{
}
enemyHard::~enemyHard()
{

}

void enemyHard::init()
{
	//	m_EnemyFlame = GetRand(30) + 500;
}

void enemyHard::end()
{

}

void enemyHard::update()
{
	Vec2 dir = Centor - m_pos;
	Vec2 mousePos = Mouse::getPos();

	// インプットした瞬間だけをとる
	if (GetMouseInput() && MOUSE_INPUT_LEFT)
	{
		if (!m_IsPressedMouse)
		{
			m_IsPressMouse = true;
		}
	}
	else
	{
		m_IsPressMouse = false;
		m_IsPressedMouse = false;
	}

	if (m_IsPressedMouse)
	{
		m_IsPressMouse = false;
	}

	if (m_IsPressMouse)
	{
		m_IsPressedMouse = true;
	}

	// マウスカーソルがenemyに当たっているかつ左クリックしたら
	if (m_IsPressMouse && isHitEnable(mousePos))
	{
		m_isExist = false;

		return;
	}

	//assert(m_EnemyFlame != 0);

	if (m_EnemyFlame != 0)
	{
		m_EnemyFlame--;
	}

	if (m_EnemyFlame == 0)
	{
		dir = dir.normalize();
		dir *= kSpeed;

		m_pos += dir;
		m_rot += 0.1f;
	}
	if (m_EnemyFlame == 0)
	{
		if (m_MoveTime >= kMovetime)
		{
			m_MoveTime = kMovetime;
			m_Flame *= -1;
		}

		if (m_MoveTime <= -kMovetime)
		{
			m_MoveTime = -kMovetime;
			m_Flame *= -1;
		}

		if (m_MoveTime > 0 && m_MoveTime <= kMovetime)
		{
			m_gravitySpeed += kMovewave;
			m_pos.x += m_gravitySpeed;
			m_pos.y += m_gravitySpeed;
		}

		if (m_MoveTime < 0 && m_MoveTime >= -kMovetime)
		{
			m_gravitySpeed -= kMovewave;
			m_pos.x += m_gravitySpeed;
			m_pos.y += m_gravitySpeed;
		}
		m_MoveTime += m_Flame;
	}
}

void enemyHard::draw()
{
	//	DrawGraph(static_cast<int>(m_pos.x),static_cast<int>(m_pos.y), m_hGraph, true);
	int width = kEnemyGraphicSize;
	int height = kEnemyGraphicSize;

	GetGraphSize(m_hGraph, &width, &height);



	DrawRotaGraph(static_cast<int>(m_pos.x) + width / 2, static_cast<int>(m_pos.y) + height / 2,
		m_ExtRate, m_rot,
		m_hGraph, true, false);

	if (m_ExtRate < 0.85f)
	{
		m_ExtRate = 0.85f;
		m_Expansion *= -1;
		m_StopFlame = 0;
	}

	if (m_ExtRate > 1.15f)
	{
		m_ExtRate = 1.15f;
		m_Expansion *= -1;
		m_StopFlame = 0;
	}

	if (m_StopFlame <= kWaitFlame)
	{
		m_StopFlame++;
	}

	if (m_StopFlame >= kWaitFlame)
	{
		m_ExtRate -= m_Expansion;
	}
}

bool enemyHard::isHitEnable(Vec2 pos)
{
	// m_pos	円の中心座標
	// pos		マウスカーソルの位置

	// 中心からマウスカーソル位置までの距離を調べる
	Vec2 toMouse = pos - m_pos;
	if (toMouse.length() < kEnemySize)
	{
		return true;
	}
	return false;
}