#include "enemyNormal.h"
#include"Dxlib.h"
#include"game.h"
#include"Mouse.h"
#include<math.h>
#include <cassert>
namespace
{
	// �G�̃X�s�[�h��ݒ�
	constexpr float kSpeed = 4.0f;

	// ���S���W��ݒ�
	constexpr int CentorX = static_cast<float>(Game::kScreenWidth / 2) - 50;
	constexpr float CentorY = static_cast<float>(Game::kScreenHeight / 2) - 50;

	// �T�C�Y
	constexpr int kEnemySize = 100;
	Vec2 Centor{ CentorX, CentorY };
	//Vec2 temp{ x + vec.x, y + vec.y };

	// �g��or�k���̂Ƃ�10f�~�߂�
	constexpr int kWaitFlame = 25;
}

enemyNormal::enemyNormal() :
	m_hGraph(-1),
	m_isExist(false),
	m_pos(),
	m_vec(3, 3),
	m_NormalizeX(),
	m_NormalizeY(),
	m_click(),
	m_rot(),
	m_IsPressMouse(false),
	m_IsPressedMouse(false),
	m_EnemyFlame(GetRand(1200) + 50),
	m_ExtRate(1.0f),
	// �g�嗦�̕ω�
	m_Expansion(0.01f),
	// �g��or�k���̂Ƃ�10f�~�߂�
	m_StopFlame(50)
{
}
enemyNormal::~enemyNormal()
{

}

void enemyNormal::init()
{
	//	m_EnemyFlame = GetRand(30) + 500;
}

void enemyNormal::end()
{

}

void enemyNormal::update()
{
	Vec2 dir = Centor - m_pos;
	Vec2 mousePos = Mouse::getPos();

	// �C���v�b�g�����u�Ԃ������Ƃ�
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

	// �}�E�X�J�[�\����enemy�ɓ������Ă��邩���N���b�N������
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

void enemyNormal::draw()
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
	else if (m_isDead)
	{
		DrawGraph(static_cast<int>(m_pos.x) + width / 2, static_cast<int>(m_pos.y) + height / 2,
			m_hdeadGraph, true);
		//	DrawRotaGraph(320, 240, 0.3, 0.0, m_deadGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeValue);
		m_fadeValue--;
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

bool enemyNormal::isHitEnable(Vec2 pos)
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