#include"enemy.h"
#include"Dxlib.h"
namespace
{
}

Enemy::Enemy() :
	m_hGraph(-1),
	m_pos()
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
	m_pos.x++;
}

void Enemy::draw()
{
	DrawGraph(m_pos.x,m_pos.y, m_hGraph, true);
}
