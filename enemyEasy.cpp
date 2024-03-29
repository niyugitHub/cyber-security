#include"enemyEasy.h"
#include"Dxlib.h"
#include"game.h"
#include"Mouse.h"
#include<math.h>
#include <cassert>
namespace
{
	// 敵のスピードを設定
	constexpr float kSpeed = 2.5f;

	// 中心座標を設定
	constexpr int CentorX = static_cast<float>(Game::kScreenWidth / 2) - 50;
	constexpr float CentorY = static_cast<float>(Game::kScreenHeight / 2) - 50;

	// サイズ
	constexpr int kEnemySize = 100;
	Vec2 Centor{ CentorX, CentorY };
	//Vec2 temp{ x + vec.x, y + vec.y };

	// 拡大or縮小のとき10f止める
	constexpr int kWaitFlame = 25;
}

enemyEasy::enemyEasy() :
	m_hGraph(-1),
	m_hdeadGraph(-1),
	m_isExist(true),
	m_pos(),
	m_vec(3, 3),
	m_click(),
	m_rot(),
	m_IsPressMouse(false),
	m_IsPressedMouse(false),
	m_EnemyFlame(GetRand(2000) + 50),
	m_ExtRate(1.0f),
	// 拡大率の変化
	m_Expansion(0.01f),
	// 拡大or縮小のとき10f止める
	m_StopFlame(50),
	m_fadeValue(255)
{
}
enemyEasy::~enemyEasy()
{

}

void enemyEasy::init()
{
//	m_EnemyFlame = GetRand(30) + 500;
}

void enemyEasy::end()
{
	
}

void enemyEasy::update()
{
	Vec2 dir = Centor - m_pos;
	Vec2 mousePos = Mouse::getPos();

	// インプットした瞬間だけをとる
	if(GetMouseInput() && MOUSE_INPUT_LEFT)
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

}

void enemyEasy::draw()
{
//	DrawGraph(static_cast<int>(m_pos.x),static_cast<int>(m_pos.y), m_hGraph, true);
	int width = kEnemyGraphicSize;
	int height = kEnemyGraphicSize;

	GetGraphSize(m_hGraph, &width, &height);
	
	if (!m_isDead)
	{
		DrawRotaGraph(static_cast<int>(m_pos.x) + width / 2, static_cast<int>(m_pos.y) + height / 2,
			m_ExtRate, m_rot,
			m_hGraph, true, false);
	}
	else if(m_isDead)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeValue);
		DrawRotaGraph(static_cast<int>(m_pos.x) + width / 2, static_cast<int>(m_pos.y) + height / 2,
			1.0f, m_rot,
			m_hdeadGraph, true, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		m_fadeValue -= 3;
	}

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

	//assert(m_hGraph < -1);
}

bool enemyEasy::isHitEnable(Vec2 pos)
{
	// m_pos	円の中心座標
	// pos		マウスカーソルの位置

	// 中心からマウスカーソル位置までの距離を調べる
	Vec2 toMouse = pos - m_pos;
	toMouse.x = toMouse.x - 50;
	toMouse.y = toMouse.y - 50;
	if (toMouse.length() < kEnemySize)
	{
		return true;
	}
	return false;
}
