#include "ScoreManager.h"


static int mHighScore;
int mScore = 0;

//�X�R�A���擾
int ScoreManager::GetScore() const{
	return mScore;
};

//�X�R�A���Z�b�g
void ScoreManager::SetScore(int inScore) {
	mScore = inScore;
};

//�����p�^�[���ɉ����ăX�R�A�����Z
void ScoreManager::AddScore(int inDeletePattern) {
	
	switch (inDeletePattern) {
	case 1: mScore += 50; break;
	case 2: mScore += 100; break;
	case 3: mScore += 160; break;
	case 4: mScore += 250; break;
	}
	
	SetScore(mScore);
}

//�@�n�C�X�R�A���Q�b�g
int ScoreManager::GetHighScore() const {
	return mHighScore;
}

// �n�C�X�R�A���Z�b�g
void ScoreManager::SetHighScore(int inHiScore) {
	mHighScore = inHiScore;
}