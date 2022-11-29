#pragma once
#include "Vec2.h"

//class SceneMain;

class enemyBase
{
public:
	enemyBase(){}
	virtual ~enemyBase() {}


	virtual void init() {}
	virtual void end() {}

	virtual void setPos(Vec2 pos) { m_pos = pos; }

	virtual void setHandle(int Graph) { m_hGraph = Graph; }

	// 存在確認
	virtual bool isExist() const { return m_isExist; }
	virtual void setExist(bool isExist) { m_isExist = isExist; }

	//bool isHitEnable(Vec2 pos);	// 有効かどうか

	virtual void update() {}
	virtual void draw() {}

protected:
	int m_hGraph;

	// 存在するか
	bool m_isExist;

	Vec2 m_pos;
	Vec2 m_vec;

	//int m_click;

	//// 回転表示
	//float m_rot;

	//bool m_IsPressMouse;		// マウスボタンが押された瞬間だけtrueになるフラグ
	//bool m_IsPressedMouse;	// マウスボタンが押されてフラグがtrueになったことがあるか

	//int m_EnemyFlame;	// enemyの出現をランダムに

	//float m_ExtRate;
	//float m_Expansion;
	//int m_StopFlame;
};

