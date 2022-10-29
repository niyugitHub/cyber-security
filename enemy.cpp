#include"enemy.h"
#include"Dxlib.h"
#include"game.h"
namespace
{
	// 敵のスピードを設定
	constexpr float kSpeed = 2.0f;
}

Enemy::Enemy() :
	m_hGraph(-1),
	m_pos(),
	m_vec(kSpeed,kSpeed)
{
}
Enemy::~Enemy()
{

}

void Enemy::init()
{

}

void Enemy::end()
{
	
}

void Enemy::update()
{
	if (m_pos.x < Game::kScreenWidth / 2 - kEnemyGraphicSize / 2)
	{
		m_pos.x += m_vec.x;
	}
	if (m_pos.x > Game::kScreenWidth / 2 - kEnemyGraphicSize / 2)
	{
		m_pos.x -= m_vec.x;
	}
	if (m_pos.y < Game::kScreenHeight / 2 - kEnemyGraphicSize / 2)
	{
		m_pos.y += m_vec.y;
	}
	if (m_pos.y > Game::kScreenHeight / 2 - kEnemyGraphicSize / 2)
	{
		m_pos.y -= m_vec.y;
	}
}

void Enemy::draw()
{
	DrawGraph(m_pos.x,m_pos.y, m_hGraph, true);
}
