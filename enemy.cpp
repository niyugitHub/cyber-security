#include"enemy.h"
#include"Dxlib.h"
#include"game.h"
#include"Mouse.h"
#include<math.h>
namespace
{
	// �G�̃X�s�[�h��ݒ�
	constexpr float kSpeed = 3.0f;

	// ���S���W��ݒ�
	constexpr int CentorX = static_cast<float>(Game::kScreenWidth / 2) - 50;
	constexpr float CentorY = static_cast<float>(Game::kScreenHeight / 2) - 50;

	// �T�C�Y
	constexpr int kEnemySize = 100;
	Vec2 Centor{ CentorX, CentorY };
	//Vec2 temp{ x + vec.x, y + vec.y };
}

Enemy::Enemy() :
	m_hGraph(-1),
	m_isExist(true),
	m_pos(),
	m_vec(3,3),
	m_NormalizeX(),
	m_NormalizeY(),
	m_rot()
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
	Vec2 mousePos = Mouse::getPos();

	// �}�E�X�J�[�\����enemy�ɓ������Ă��邩���N���b�N������
	if (GetMouseInput() & MOUSE_INPUT_LEFT && isHitEnable(mousePos))	
	{
		m_isExist = false;
		return;
	}

	dir = dir.normalize();
	dir *= kSpeed;

	m_pos += dir;
	m_rot += 0.1f;
}

void Enemy::draw()
{
//	DrawGraph(static_cast<int>(m_pos.x),static_cast<int>(m_pos.y), m_hGraph, true);
	int width = kEnemyGraphicSize;
	int height = kEnemyGraphicSize;

	GetGraphSize(m_hGraph, &width, &height);

	DrawRotaGraph(static_cast<int>(m_pos.x) + width / 2, static_cast<int>(m_pos.y) + height / 2,
		1.0f, m_rot,
		m_hGraph, true, false);
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

bool Enemy::isHitEnable(Vec2 pos)
{
	// m_pos	�~�̒��S���W
	// pos		�}�E�X�J�[�\���̈ʒu

	// ���S����}�E�X�J�[�\���ʒu�܂ł̋����𒲂ׂ�
	Vec2 toMouse = pos - m_pos;
	if (toMouse.length() < kEnemySize)
	{
		return true;
	}
	return false;
}
