#pragma once
#include"Vec2.h"
#include "enemyBase.h"

class enemyNormal : public enemyBase
{
public:
	// 定数定義
	// 敵グラフィックサイズ
	static constexpr int kEnemyGraphicSize = 100;

public:
	enemyNormal();
	virtual ~enemyNormal();

	void init();
	void end();

	virtual void setPos(Vec2 pos) { m_pos = pos; }

	virtual void setHandle(int Graph) { m_hGraph = Graph; }

	virtual void setDeadHandle(int DeadGraph) { m_hdeadGraph = DeadGraph; }

	virtual void getPos(Vec2 pos) { m_pos = pos; }

	virtual void update();
	virtual void draw();

	// 存在確認
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	bool isHitEnable(Vec2 pos);	// 有効かどうか

private:
	int m_hGraph;
	int m_hdeadGraph;

	// 存在するか
	bool m_isExist;

	Vec2 m_pos;
	Vec2 m_vec;

	int m_click;

	// 回転表示
	float m_rot;

	bool m_IsPressMouse;		// マウスボタンが押された瞬間だけtrueになるフラグ
	bool m_IsPressedMouse;	// マウスボタンが押されてフラグがtrueになったことがあるか

	int m_EnemyFlame;	// enemyの出現をランダムに

	float m_ExtRate;
	float m_Expansion;
	int m_StopFlame;

	int m_fadeValue;
};

