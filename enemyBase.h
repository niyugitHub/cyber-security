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

	// ���݊m�F
	virtual bool isExist() const { return m_isExist; }
	virtual void setExist(bool isExist) { m_isExist = isExist; }

	// ���S�m�F
	virtual bool isDead() const { return m_isDead; }
	virtual void setDead(bool isDead) { m_isDead = isDead; }

	//bool isHitEnable(Vec2 pos);	// �L�����ǂ���

	virtual void update() {}
	virtual void draw() {}

protected:
	int m_hGraph;
	int m_hdeadGraph;

	// �t�F�[�h�C��
	int m_fadeValue;

	// ���݂��邩
	bool m_isExist;

	//�����m�F
	bool m_isDead;

	Vec2 m_pos;
	Vec2 m_vec;
};

