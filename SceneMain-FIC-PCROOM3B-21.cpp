#include"SceneMain.h"
#include "SceneTitle.h"
#include"game.h"
#include"Dxlib.h"
namespace
{
	constexpr int kGraphNum = 30;
	const char* const kEnemyFilename = "data/enemy.png";

	// enemyの画像サイズを取得
	constexpr int kEnemyGraphSize = 100;

	// enemyを一定時間ごとに出現させる
	constexpr int  kEnemyFlame = 50;
}

SceneMain::SceneMain() :
	m_Graph(kGraphNum,nullptr),
	m_pos(),
	m_hEnemy(-1),
	m_waitFrame(0),
	m_enemyNum(0)
{
	for (auto& pGraph : m_Graph)
	{
		pGraph = new Enemy;
	}
}
SceneMain::~SceneMain()
{
	for (auto& pGraph : m_Graph)
	{
		delete pGraph;
		pGraph = nullptr;
	}
}

void SceneMain::init()
{
	m_hEnemy = LoadGraph(kEnemyFilename);
	
	for (auto& pGraph : m_Graph)
	{
		//// enemyの出現場所をランダムに
		//float RandAppearX = GetRand(Game::kScreenWidth);
		//float RandAppearY = GetRand(Game::kScreenHeight);

		//int a = GetRand(1);
		//int b = GetRand(1);

		//if (a == 1)
		//{
		//	if (b == 1)
		//	{
		//		RandAppearX = -kEnemyGraphSize;
		//	}
		//	else if (b == 0)
		//	{
		//		RandAppearX = Game::kScreenWidth;
		//	}
		//}

		//if (a == 0)
		//{
		//	if (b == 1)
		//	{
		//		RandAppearY = -kEnemyGraphSize;
		//	}
		//	else if (b == 0)
		//	{
		//		RandAppearY = Game::kScreenHeight;
		//	}
		//}

		Vec2 pos = setPos();
		pGraph->init();
		pGraph->setPos(pos);
		pGraph->setHandle(m_hEnemy);
	}
}

void SceneMain::end()
{
	ClearDrawScreen();
}

SceneBase* SceneMain::update()
{
	/*if (m_waitFrame < kEnemyFlame)
		{
			m_waitFrame++;
			return;
		}*/
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	for (int i = 0; i < kGraphNum; i++)
	{
		if (i <= m_enemyNum)
		{
			m_Graph[i]->update();
		}
	}
	if (m_waitFrame < kEnemyFlame)
	{
		m_waitFrame++;
		//return;
	}
	if (m_waitFrame == kEnemyFlame)
	{
		m_waitFrame = 0;
		m_enemyNum++;
	}

	if (padState & PAD_INPUT_2)
	{
		return (new SceneTitle);
	}
	if (padState & PAD_INPUT_1)
	{
		return (new SceneMain);
	}
}

void SceneMain::draw()
{
	for (auto& pGraph : m_Graph)
	{
		pGraph->draw();
	}
}

Vec2 SceneMain::setPos()
{
	// enemyの出現場所をランダムに
	float RandAppearX = GetRand(Game::kScreenWidth);
	float RandAppearY = GetRand(Game::kScreenHeight);

	int IndexRandX = GetRand(1);
	int IndexRandY = GetRand(1);

	if (IndexRandX == 1)
	{
		if (IndexRandY == 1)
		{
			RandAppearX = -kEnemyGraphSize;
		}
		else if (IndexRandY == 0)
		{
			RandAppearX = Game::kScreenWidth;
		}
	}

	if (IndexRandX == 0)
	{
		if (IndexRandY == 1)
		{
			RandAppearY = -kEnemyGraphSize;
		}
		else if (IndexRandY == 0)
		{
			RandAppearY = Game::kScreenHeight;
		}
	}

	Vec2 RandAppear(RandAppearX, RandAppearY);
	return RandAppear;
}