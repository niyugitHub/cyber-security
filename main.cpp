#include "DxLib.h"
#include "SceneManager.h"
#include"game.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	// windowモード設定
	ChangeWindowMode(Game::kWindouwMode);
	// ウインドウ名設定
	SetMainWindowText(Game::kTitleText);
	// 画面サイズの設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager scene;
	scene.init();

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// 画面のクリア
		ClearDrawScreen();

		SetMouseDispFlag(1);

		scene.update();
		scene.draw();

		// 裏画面と表画面を入れ替える
		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		// fpsを60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	scene.end();

	return 0;				// ソフトの終了 
}
