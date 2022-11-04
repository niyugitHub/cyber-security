#pragma once
#include"Vec2.h"
//a
class Enemy
{
public:
	// �萔��`
	// �G�O���t�B�b�N�T�C�Y
	static constexpr int kEnemyGraphicSize = 100;
	
public:
	Enemy();
	virtual ~Enemy();

	void init();
	void end();

	virtual void setPos(Vec2 pos) { m_pos = pos; }

	virtual void setHandle(int Graph) { m_hGraph = Graph; }

//	virtual void getPos(Vec2 pos) { m_pos = pos; }

	void update();
	void draw();

	void EnemyMove();

private:
	int m_hGraph;

	Vec2 m_pos;
	Vec2 m_vec;

	// ���K��
	float m_NormalizeX;
	float m_NormalizeY;
};
