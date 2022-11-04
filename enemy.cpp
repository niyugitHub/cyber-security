#include"enemy.h"
#include"Dxlib.h"
#include"game.h"
#include<math.h>
namespace
{
	// 敵のスピードを設定
	constexpr float kSpeed = 3.0f;

	// 中心座標を設定
	constexpr int CentorX = static_cast<float>(Game::kScreenWidth / 2) - 50;
	constexpr float CentorY = static_cast<float>(Game::kScreenHeight / 2) - 50;
	Vec2 Centor{ CentorX, CentorY };
	//Vec2 temp{ x + vec.x, y + vec.y };
}

Enemy::Enemy() :
	m_hGraph(-1),
	m_pos(),
	m_vec(3,3),
	m_NormalizeX(),
	m_NormalizeY()
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
	Vec2 dir = Centor - m_pos;

	dir = dir.normalize();
	dir *= kSpeed;

	m_pos += dir;
	/*if (m_pos.x < Game::kScreenWidth / 2 - kEnemyGraphicSize / 2)
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
	}*/

	//m_pos.x += (m_pos.x - Game::kScreenWidth / 2) / (m_pos.y - Game::kScreenHeight / 2);
	//m_pos.y += (m_pos.y - Game::kScreenHeight / 2) / (m_pos.x - Game::kScreenWidth / 2);
}

void Enemy::draw()
{
	DrawGraph(static_cast<int>(m_pos.x),static_cast<int>(m_pos.y), m_hGraph, true);
}

void Enemy::EnemyMove()
{
	float Centor_LengthX = (static_cast<float>(Game::kScreenWidth) / 2 - m_pos.x);
	float Centor_LengthY = (static_cast<float>(Game::kScreenHeight) / 2 - m_pos.y);

	float Centor_Length = Centor_LengthX * Centor_LengthX + Centor_LengthY * Centor_LengthY;

	float NormalizeX = Centor_LengthX / (Centor_Length);
	float NormalizeY = Centor_LengthY / (Centor_Length);

	m_NormalizeX = NormalizeX;
	m_NormalizeY = NormalizeY;
}
