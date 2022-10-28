#include"scenemain.h"
#include"Dxlib.h"
namespace
{
	constexpr int kGraphNum = 30;
	const char* const kEnemyFilename = "data/enemy.png";
}

Scenemain::Scenemain() :
	m_Graph(kGraphNum,nullptr),
	m_pos(),
	m_hEnemy(-1)
{
	for (auto& pGraph : m_Graph)
	{
		pGraph = new Enemy;
	}
}
Scenemain::~Scenemain()
{
	for (auto& pGraph : m_Graph)
	{
		delete pGraph;
		pGraph = nullptr;
	}
}

void Scenemain::init()
{
	int index = 0;
	m_hEnemy = LoadGraph(kEnemyFilename);
	
	for (auto& pGraph : m_Graph)
	{
		Vec2 pos{ 256.0f - index * 32.0f, 256.0f - index * 32.0f };
		index++;
		pGraph->init();
		pGraph->setPos(pos);
		pGraph->setHandle(m_hEnemy);
	}
}

void Scenemain::end()
{
	ClearDrawScreen();
}

void Scenemain::update()
{
	for (auto& pGraph : m_Graph)
	{
		pGraph->update();
	}
}

void Scenemain::draw()
{
	for (auto& pGraph : m_Graph)
	{
		pGraph->draw();
	}
}
