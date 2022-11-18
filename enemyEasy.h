#pragma once
#include"Vec2.h"
//a
class enemyEasy
{
public:
	// 定数定義
	// 敵グラフィックサイズ
	static constexpr int kEnemyGraphicSize = 100;
	
public:
	enemyEasy();
	virtual ~enemyEasy();

	void init();
	void end();

	virtual void setPos(Vec2 pos) { m_pos = pos; }

	virtual void setHandle(int Graph) { m_hGraph = Graph; }

//	virtual void getPos(Vec2 pos) { m_pos = pos; }

	void update();
	void draw();

	void EnemyMove();

	// 存在確認
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	bool isHitEnable(Vec2 pos);	// 有効かどうか

private:
	int m_hGraph;

	// 存在するか
	bool m_isExist;

	Vec2 m_pos;
	Vec2 m_vec;

	// 正規化
	float m_NormalizeX;
	float m_NormalizeY;
	
	int m_click;

	// 回転表示
	float m_rot;

	bool m_IsPressMouse;		// マウスボタンが押された瞬間だけtrueになるフラグ
	bool m_IsPressedMouse;	// マウスボタンが押されてフラグがtrueになったことがあるか

};
