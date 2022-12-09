#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneSelection.h"
#include "SceneExplanation.h"
#include"game.h"

namespace
{
	// �g��or�k���̂Ƃ�10f�~�߂�
	constexpr int kWaitFlame = 25;
}

void SceneTitle::init()
{
//	m_RandColor = 0;
	m_handle = LoadGraph("data/enemy.png");
	m_isEnd = false;
	m_textSize = 50;
	m_speed = 5.0f;
	m_Gravity = 0.3f;
	m_ExtRate = 2.0f;
	m_Expansion = 0.01f;
	m_StopFlame = 50;
}

SceneBase* SceneTitle::update()
{
	// �����̈ړ�
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitString2())
	{
		// Main�ɐ؂�ւ�
		return (new SceneSelection);
	
	}

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitString3())
	{
		// Main�ɐ؂�ւ�
		return (new SceneExplanation);
	}
	
	if (m_pos.x < Game::kScreenWidth / 2)
	{
		m_Gravity = 0.3f;
	}

	if (m_pos.x > Game::kScreenWidth - 350)
	{
		m_Gravity = -0.3f;
	}

	if (m_speed < -5.0f)
	{
		m_speed = -5.0f;
	}

	if (m_speed > 5.0f)
	{
		m_speed = 5.0f;
	}

	m_speed += m_Gravity;
	m_pos.x += m_speed;
	m_rot += 0.05f;

	if (m_ExtRate < 1.55f)
	{
		m_ExtRate = 1.55f;
		m_Expansion *= -1;
		m_StopFlame = 0;
	}

	if (m_ExtRate > 2.15f)
	{
		m_ExtRate = 2.15f;
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

	return this;
}

void SceneTitle::draw()
{
	SetFontSize(50);
	DrawString(150, 200, "�E�C���X�o�X�^�[�Y�I", GetColor(0, 255, 0));
	DrawString(150, 450, "�Q�[���X�^�[�g", GetColor(0, 255, 0));
	DrawString(150, 550, "�����т���", GetColor(0, 255, 0));

	if (HitString2())
	{
		DrawString(150, 450, "�Q�[���X�^�[�g", GetColor(255, 255, 255));
	}
	if (HitString3())
	{
		DrawString(150, 550, "�����т���", GetColor(255, 255, 255));
	}


	DrawRotaGraph(m_pos.x, m_pos.y, m_ExtRate, m_rot,
		m_handle, true, false);
	//DrawBox(static_cast<int>(Mouse::getPos().x), static_cast<int>(Mouse::getPos().y),
	//	Mause::kMouseSize, int y2,
	//	unsigned int Color, int FillFlag);



#if false
	// randcolor�̒l�̕\��
	DrawFormatString(0 , 0, GetColor(255,255,255),"%d", m_RandColor);
#endif
}

bool SceneTitle::HitString2()
{
	if (Mouse::getPos().x > 150 &&
		Mouse::getPos().x < 150 + m_textSize * 7)
	{
		if (Mouse::getPos().y > 450 &&
			Mouse::getPos().y < 500)
		{
			return true;
		}
	}
	return false;
}
bool SceneTitle::HitString3()
{
	if (Mouse::getPos().x > 150 &&
		Mouse::getPos().x < 150 + m_textSize * 5)
	{
		if (Mouse::getPos().y > 550 &&
			Mouse::getPos().y < 600)
		{
			return true;
		}
	}
	return false;
}
