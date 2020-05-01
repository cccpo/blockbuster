#pragma once


//スコア管理クラス
class Score
{
	

 public:
	 int mScore = 0;

	
	int GetScore();
	
	void SetScore(int sc);

	void AddScore(int a);
	

	Score() {};
	~Score() {};
};

