#include "Score.h"




int Score::GetScore() {
	return mScore;
};

void Score::SetScore(int sc) {
	mScore = sc;
};

void Score::AddScore(int a) {
	
	switch (a) {
	case 1: mScore += 10; break;
	case 2: mScore += 40; break;
	case 3: mScore += 90; break;
	case 4: mScore += 160; break;
	}
	SetScore(mScore);
}