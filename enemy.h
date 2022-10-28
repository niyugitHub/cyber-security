#pragma once
#include"Vec2.h"

class Enemy
{
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


private:
	int m_hGraph;
	Vec2 m_pos;
};
