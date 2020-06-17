#include "Score.h"


static int mHighScore;

//スコアを取得
int Score::GetScore() const{
	return mScore;
};

//スコアをセット
void Score::SetScore(int sc) {
	mScore = sc;
};

//消去パターンに応じてスコアを加算
void Score::AddScore(int a) {
	
	switch (a) {
	case 1: mScore += 50; break;
	case 2: mScore += 100; break;
	case 3: mScore += 160; break;
	case 4: mScore += 250; break;
	}
	
	SetScore(mScore);
}

//　ハイスコアをゲット
int Score::GetHighScore() const {
	return mHighScore;
}

// ハイスコアをセット
void Score::SetHighScore(int hs) {
	mHighScore = hs;
}