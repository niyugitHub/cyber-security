#include"scenemain.h"
#include"enemyEasy.h"
#include "SceneTitle.h"
#include"game.h"
#include"Dxlib.h"
namespace
{
	// ��Փx���Ƃ̓G�̐���ݒ�
	constexpr int kGraphNumEasy = 30;
	constexpr int kGraphNumNormal = 50;
	//constexpr int kGraphNumEasy = 30;
	//constexpr int kGraphNumEasy = 30;

	const char* const kEnemyFilename = "data/enemy.png";

	// enemy�̉摜�T�C�Y���擾
	constexpr int kEnemyGraphSize = 100;

	// enemy����莞�Ԃ��Ƃɏo��������
	constexpr int  kEnemyFlame = 50;

	// �I������
	constexpr int kEndtimeFlame = 1800;
}

SceneMain::SceneMain() :
	m_Graph(kGraphNumEasy, nullptr),
	m_pos(),
	m_hEnemy(-1),
	m_hMouse(-1),
	m_waitFrame(0),
	m_enemyNum(0),
	m_Endtime(0)
{
	for (auto& pGraph : m_Graph)
	{
		pGraph = new enemyEasy;
	}
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
	m_hMouse = LoadGraph(kEnemyFilename);
	
	for (auto& pGraph : m_Graph)
	{
		//// enemy�̏o���ꏊ�������_����
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
	m_Endtime++;
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if(m_Endtime < kEndtimeFlame)
	{

		for (int i = 0; i < kGraphNumEasy; i++)
		{
			if (m_Graph[i] != nullptr)
			{
				if (m_Graph[i]->isExist())
				{
					m_Graph[i]->update();
				}

				else if (!m_Graph[i]->isExist())
				{
					delete m_Graph[i];
					m_Graph[i] = nullptr;
				}

			}
		}

		for (int i = 0; i < kGraphNumEasy; i++)
		{
			if (m_Graph[i] == nullptr)
			{
				m_Graph[i] = new enemyEasy;

				m_Graph[i]->setHandle(m_hEnemy);
				m_Graph[i]->setExist(true);

				Vec2 pos = setPos();
				m_Graph[i]->setPos(pos);
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
	for (auto& pGraph : m_Graph)
	{
		if (pGraph->isExist())
		{
			pGraph->draw();
		}
	}

	DrawGraph(Mouse::getPos().x, Mouse::getPos().y, m_hMouse, true);

	if (m_Endtime > kEndtimeFlame)
	{
		DxLib_End();
	}
}

Vec2 SceneMain::setPos()
{
	// enemy�̏o���ꏊ�������_����
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