#pragma once
#include "SceneBase.h"

class SceneSelection : public SceneBase
{
public:
	SceneSelection() :
		m_handleCar(-1),
		m_textSize(0),
		m_SetLevel(0)
	{
	}
	virtual ~SceneSelection() {}


	virtual void init()override;
	virtual void end() override {}

	virtual SceneBase* update()override;
	virtual void draw()override;

	void getLevel() { m_SetLevel; }

	// �}�E�X�ƕ���������������
	bool HitStringEasy();
	bool HitStringNormal();
	bool HitStringHard();
	/*bool HitString2();
	bool HitString3();*/

private:
	// �摜�n���h��
	int m_handleCar;

	// �e�L�X�g�̃T�C�Y
	int m_textSize;

	// ��Փx�ݒ�
	int m_SetLevel;
};