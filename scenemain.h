#pragma once
#include "enemy.h"

#include <vector>

class Scenemain
{
public:
	Scenemain();
	virtual ~Scenemain();

	void init();
	void end();

//	virtual void getPos(Vec2 pos) { m_pos = pos; }

	void update();
	void draw();

private:
	int m_hEnemy;
	Vec2 m_pos;

	std::vector<Enemy*> m_Graph;
};