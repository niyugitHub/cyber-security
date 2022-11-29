#pragma once
#include "SceneBase.h"
#include "Mouse.h"

#include <vector>
#include "enemyBase.h"

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	virtual void init();
	// �I������
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

	// �I���܂ł̎���(�t���[��)
	int m_Endtime;

	//Vec2 Mouse::getPos();
	std::vector<enemyBase*> m_Graph;
};