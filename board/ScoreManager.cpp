#include "ScoreManager.h"


static int gHighScore;
int gScore = 0;

//スコアを取得
const int ScoreManager::GetScore(){
	return gScore;
};

//スコアをセット
void ScoreManager::SetScore(int inScore) {
	gScore = inScore;
};

//消去パターンに応じてスコアを加算
void ScoreManager::AddScore(int inDeletePattern) {
	
	switch (inDeletePattern) {
	case 1: gScore += 50; break;
	case 2: gScore += 100; break;
	case 3: gScore += 160; break;
	case 4: gScore += 250; break;
	}
	
	SetScore(gScore);
}

//　ハイスコアをゲット
const int ScoreManager::GetHighScore(){
	return gHighScore;
}

// ハイスコアをセット
void ScoreManager::SetHighScore(int inHiScore) {
	gHighScore = inHiScore;
}