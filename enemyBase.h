#pragma once
#include "Vec2.h"

//class SceneMain;

class enemyBase
{
public:
	enemyBase() : 
	m_hGraph(-1),
	m_hdeadGraph(-1),
	m_isExist(false),
	m_isDead(false)
	{}
	virtual ~enemyBase() {}


	virtual void init() {}
	virtual void end() {}

	virtual void setPos(Vec2 pos) { m_pos = pos; }

	virtual void setHandle(int Graph) { m_hGraph = Graph; }

	virtual void setDeadHandle(int DeadGraph) { m_hdeadGraph = DeadGraph; }

	// 存在確認
	virtual bool isExist() const { return m_isExist; }
	virtual void setExist(bool isExist) { m_isExist = isExist; }

	// 死亡確認
	virtual bool isDead() const { return m_isDead; }
	virtual void setDead(bool isDead) { m_isDead = isDead; }

	//bool isHitEnable(Vec2 pos);	// 有効かどうか

	virtual void update() {}
	virtual void draw() {}

protected:
	int m_hGraph;
	int m_hdeadGraph;

	// フェードイン
	int m_fadeValue;

	// 存在するか
	bool m_isExist;

	//生存確認
	bool m_isDead;

	Vec2 m_pos;
	Vec2 m_vec;
};

