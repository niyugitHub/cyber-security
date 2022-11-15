#pragma once
#include "enemy.h"
#include "SceneBase.h"
#include "Mouse.h"

#include <vector>

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ‰Šú‰»
	virtual void init();
	// I—¹ˆ—
	virtual void end();

//	virtual void getPos(Vec2 pos) { m_pos = pos; }

	virtual SceneBase* update();
	virtual void draw();

	Vec2 setPos();

private:
	int m_hEnemy;
	int m_hMouse;
	int m_waitFrame;
	int m_enemyNum;
	Vec2 m_pos;

	//Vec2 Mouse::getPos();
	std::vector<Enemy*> m_Graph;
};