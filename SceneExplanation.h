#pragma once
#include "SceneBase.h"

class SceneExplanation : public SceneBase
{
public:
	SceneExplanation()
	{
		m_isEnd = false;
	}
	virtual ~SceneExplanation() {}


	virtual void init()override;
	virtual void end() override {}

	virtual SceneBase* update()override;
	virtual void draw()override;

	virtual bool isEnd() { return m_isEnd; }

	// �}�E�X�ƕ���������������
	bool HitStringNext();
	bool HitStringBack();
	/*bool HitString2();
	bool HitString3();*/

	// �}�E�X���������u�Ԃ����@�\��^����
	void IsPressMouse();
private:
	// �摜�ԍ�
	int m_handleNum;
	// �摜�n���h��
	int m_handleCar;
	int m_handle[5];

	// �e�L�X�g�̃T�C�Y
	int m_textSize;

	// �J���[�̕ύX
	int m_RandColor;

	bool m_IsPressMouse;		// �}�E�X�{�^���������ꂽ�u�Ԃ���true�ɂȂ�t���O
	bool m_IsPressedMouse;	// �}�E�X�{�^����������ăt���O��true�ɂȂ������Ƃ����邩
	bool m_flag;

	bool m_isEnd;
};