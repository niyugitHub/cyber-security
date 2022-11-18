#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle() 
	{
		m_textPosY = 0;
		m_textVecY = 0;
		m_isEnd = false;
	}
	virtual ~SceneTitle() {}


	virtual void init()override;
	virtual void end() override {}

	virtual SceneBase* update()override;
	virtual void draw()override;

	virtual bool isEnd() { return m_isEnd; }

	// �}�E�X�ƕ���������������
	bool HitString1();
	bool HitString2();
	bool HitString3();
private:
	// �摜�n���h��
	int m_handle;
	// �e�L�X�g�\���ʒu�ύX
	int m_textPosY;
	int m_textVecY;

	// �e�L�X�g�̃T�C�Y
	int m_textSize;

	// �J���[�̕ύX
	int m_RandColor;

	bool m_isEnd;
};