#pragma once
#include "Vec2.h"
class enemyBase
{
	enemyBase() {}
	virtual ~enemyBase() {}


	virtual void init() {}
	virtual void end() {}

	void setPos(Vec2 pos) { m_pos = pos; }

	void setHandle(int Graph) { m_hGraph = Graph; }

	// ���݊m�F
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	bool isHitEnable(Vec2 pos);	// �L�����ǂ���

	virtual enemyBase* update() { return this; }
	virtual void draw() {}

protected:
	int m_hGraph;

	// ���݂��邩
	bool m_isExist;

	Vec2 m_pos;
	Vec2 m_vec;

	int m_click;

	// ��]�\��
	float m_rot;

	bool m_IsPressMouse;		// �}�E�X�{�^���������ꂽ�u�Ԃ���true�ɂȂ�t���O
	bool m_IsPressedMouse;	// �}�E�X�{�^����������ăt���O��true�ɂȂ������Ƃ����邩

	int m_EnemyFlame;	// enemy�̏o���������_����

	float m_ExtRate;
	float m_Expansion;
	int m_StopFlame;
};

