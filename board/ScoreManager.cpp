#include "ScoreManager.h"


static int gHighScore;
int gScore = 0;

//�X�R�A���擾
const int ScoreManager::GetScore(){
	return gScore;
};

//�X�R�A���Z�b�g
void ScoreManager::SetScore(int inScore) {
	gScore = inScore;
};

//�����p�^�[���ɉ����ăX�R�A�����Z
void ScoreManager::AddScore(int inDeletePattern) {
	
	switch (inDeletePattern) {
	case 1: gScore += 50; break;
	case 2: gScore += 100; break;
	case 3: gScore += 160; break;
	case 4: gScore += 250; break;
	}
	
	SetScore(gScore);
}

//Win32�ŃX�R�A���Z�֐�
int ScoreManager::AddScoreWin32(int inDeletePattern) {

	int score_win32 = 0;

	switch (inDeletePattern) {
	case 1: score_win32 += 50; break;
	case 2: score_win32 += 100; break;
	case 3: score_win32 += 160; break;
	case 4: score_win32 += 250; break;
	}

	return score_win32;
}

//�@�n�C�X�R�A���Q�b�g
const int ScoreManager::GetHighScore(){
	return gHighScore;
}

// �n�C�X�R�A���Z�b�g
void ScoreManager::SetHighScore(int inHiScore) {
	gHighScore = inHiScore;
}