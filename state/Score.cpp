#include "Score.h"


static int mHighScore;

//�X�R�A���擾
int Score::GetScore() const{
	return mScore;
};

//�X�R�A���Z�b�g
void Score::SetScore(int sc) {
	mScore = sc;
};

//�����p�^�[���ɉ����ăX�R�A�����Z
void Score::AddScore(int a) {
	
	switch (a) {
	case 1: mScore += 50; break;
	case 2: mScore += 100; break;
	case 3: mScore += 160; break;
	case 4: mScore += 250; break;
	}
	
	SetScore(mScore);
}

//�@�n�C�X�R�A���Q�b�g
int Score::GetHighScore() const {
	return mHighScore;
}

// �n�C�X�R�A���Z�b�g
void Score::SetHighScore(int hs) {
	mHighScore = hs;
}