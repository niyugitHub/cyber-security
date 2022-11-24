#pragma once
#include"Vec2.h"

class enemyNormal
{
public:
	// �萔��`
	// �G�O���t�B�b�N�T�C�Y
	static constexpr int kEnemyGraphicSize = 100;

public:
	enemyNormal();
	virtual ~enemyNormal();

	void init();
	void end();

	virtual void setPos(Vec2 pos) { m_pos = pos; }

	virtual void setHandle(int Graph) { m_hGraph = Graph; }

	//	virtual void getPos(Vec2 pos) { m_pos = pos; }

	void update();
	void draw();

	// ���݊m�F
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	bool isHitEnable(Vec2 pos);	// �L�����ǂ���

private:
	int m_hGraph;

	// ���݂��邩
	bool m_isExist;

	Vec2 m_pos;
	Vec2 m_vec;

	// ���K��
	float m_NormalizeX;
	float m_NormalizeY;

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

