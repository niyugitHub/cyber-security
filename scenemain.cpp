#include"scenemain.h"
#include"enemyEasy.h"
#include"enemyNormal.h"
#include"enemyHard.h"
#include "SceneTitle.h"
#include "SceneSelection.h"
#include"game.h"
#include<cassert>
#include<Dxlib.h>

namespace
{
	// 難易度ごとの敵の数を設定
	constexpr int kGraphNum = 30;

	// 画像をnamespaceに入れる
	const char* const kEnemyFilename = "data/enemy.png";
	const char* const kDeadEnemyFilename = "data/deadEnemy.png";

	const char* const kSumahoFilename = "data/sumaho1.png";
	const char* const kDeadsumahoFilename = "data/sumaho3.png";

	// enemyの画像サイズを取得
	constexpr int kEnemyGraphSize = 150;

	// enemyを一定時間ごとに出現させる
	constexpr int  kEnemyFlame = 50;

	// 終了時間
	constexpr int kEndtimeFlame = 18000;
}

SceneMain::SceneMain() :
	m_Graph(kGraphNum, nullptr),
	m_hPlayer(-1),
	m_hDeadPlayer(-1),
	m_pos(),
	m_hEnemy(-1),
	m_hDeadEnemy(-1),
	m_waitFrame(0),
	m_enemyNum(0),
	m_fadeout(kGraphNum, 0),
	m_Endtime(0),
	m_Level(0)
{

	
}
SceneMain::~SceneMain()
{
	for (auto& pGraph : m_Graph)
	{
		if (pGraph != nullptr)
		{
			delete pGraph;
			pGraph = nullptr;
		}
	}
}

void SceneMain::init()
{
	m_hEnemy = LoadGraph(kEnemyFilename);
	m_hDeadEnemy = LoadGraph(kDeadEnemyFilename);
	m_hMouse = LoadGraph(kEnemyFilename);
	m_hPlayer = LoadGraph(kSumahoFilename);
	m_hDeadPlayer = LoadGraph(kDeadsumahoFilename);

	for (auto& pGraph : m_Graph)
	{
		if (m_Level == 1)
		{
			pGraph = new enemyEasy;
		}

		else if (m_Level == 2)
		{
			pGraph = new enemyNormal;
		}

		else if (m_Level == 3)
		{
			pGraph = new enemyHard;
		}

		assert(m_Level != 0);

	}
	
	
	for (auto& pGraph : m_Graph)
	{
		Vec2 pos = setPos();
		pGraph->init();
		pGraph->setPos(pos);
		pGraph->setHandle(m_hEnemy);
		pGraph->setDeadHandle(m_hDeadEnemy);
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
	m_Endtime++;
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if(m_Endtime < kEndtimeFlame)
	{
		if (ColEnemyPlayer())
		{
			DxLib_End();
		}

		if (m_Endtime > kEndtimeFlame)
		{
			DxLib_End();
		}

		for (int i = 0; i < kGraphNum; i++)
		{
			if (m_Graph[i] != nullptr)
			{
				if (m_Graph[i]->isExist())
				{
					m_Graph[i]->update();
				}

				else if (!m_Graph[i]->isExist())
				{
					if (m_fadeout[i] >= 255)
					{
						delete m_Graph[i];
						m_Graph[i] = nullptr;
						m_fadeout[i] = 0;
					}
				}

			}
		}

		for (int i = 0; i < kGraphNum; i++)
		{
			if (m_Level == 1)
			{
				if (m_Graph[i] == nullptr)
				{
					m_Graph[i] = new enemyEasy;

					m_Graph[i]->setHandle(m_hEnemy);
					m_Graph[i]->setExist(true);
					m_Graph[i]->setDeadHandle(m_hDeadEnemy);

					Vec2 pos = setPos();
					m_Graph[i]->setPos(pos);
				}
			}

			if (m_Level == 2)
			{
				if (m_Graph[i] == nullptr)
				{
					m_Graph[i] = new enemyNormal;

					m_Graph[i]->setHandle(m_hEnemy);
					m_Graph[i]->setExist(true);
					m_Graph[i]->setDeadHandle(m_hDeadEnemy);

					Vec2 pos = setPos();
					m_Graph[i]->setPos(pos);
				}
			}

			if (m_Level == 3)
			{
				if (m_Graph[i] == nullptr)
				{
					m_Graph[i] = new enemyHard;

					m_Graph[i]->setHandle(m_hEnemy);
					m_Graph[i]->setExist(true);
					m_Graph[i]->setDeadHandle(m_hDeadEnemy);

					Vec2 pos = setPos();
					m_Graph[i]->setPos(pos);
				}
			}
		}
	}
	

	if (padState & PAD_INPUT_2)
	{
		return (new SceneTitle);
	}
	if (padState & PAD_INPUT_1)
	{
		return (new SceneMain);
	}
	return this;
}

void SceneMain::draw()
{
	for (int i = 0; i < kGraphNum; i++)
	{
		if (!m_Graph[i]->isExist())
			{
			m_Graph[i]->setDead(true);
				m_fadeout[i] += 3;
			}
		if (m_Graph[i]->isExist())
		{
			m_Graph[i]->setDead(false);
		}
		m_Graph[i]->draw();
	}

	DrawGraph(Game::kScreenWidth / 2 - 75, Game::kScreenHeight / 2 - 75, m_hPlayer, true);
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
			RandAppearX = Game::kScreenWidth + kEnemyGraphSize;
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
			RandAppearY = Game::kScreenHeight + kEnemyGraphSize;
		}
	}

	Vec2 RandAppear(RandAppearX, RandAppearY);
	return RandAppear;
}

bool SceneMain::ColEnemyPlayer()
{
	int PlayerLeft = Game::kScreenWidth / 2 - 75;
	int PlayerRight = Game::kScreenWidth / 2 + 75;
	int PlayerTop = Game::kScreenHeight / 2 - 75;
	int PlayerBottom = Game::kScreenHeight / 2 + 75;
	for (auto& pGraph : m_Graph)
	{
		int a = pGraph->GetPos().x;

		if (PlayerLeft > pGraph->GetPos().x + 75) continue;
		if (PlayerRight < pGraph->GetPos().x + 75) continue;
		if (PlayerTop > pGraph->GetPos().y + 75) continue;
		if (PlayerBottom < pGraph->GetPos().y + 75)continue;

		return true;
	}
	return false;
}