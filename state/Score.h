#pragma once



//スコア管理クラス
class Score
{
	

 public:
	 
	 int gScore = 0;
	

	int GetScore();
	void SetScore(int sc);
	

	Score() {};
	~Score() {};
};

