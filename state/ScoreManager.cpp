#include "ScoreManager.h"


static int mHighScore;
int mScore = 0;

//スコアを取得
int ScoreManager::GetScore() const{
	return mScore;
};

//スコアをセット
void ScoreManager::SetScore(int inScore) {
	mScore = inScore;
};

//消去パターンに応じてスコアを加算
void ScoreManager::AddScore(int inDeletePattern) {
	
	switch (inDeletePattern) {
	case 1: mScore += 50; break;
	case 2: mScore += 100; break;
	case 3: mScore += 160; break;
	case 4: mScore += 250; break;
	}
	
	SetScore(mScore);
}

//　ハイスコアをゲット
int ScoreManager::GetHighScore() const {
	return mHighScore;
}

// ハイスコアをセット
void ScoreManager::SetHighScore(int inHiScore) {
	mHighScore = inHiScore;
}