#pragma once


//スコア管理クラス
class Score
{
private:
	int mScore = 0;


 public:


	
	int GetScore() const;//score取得
	
	void SetScore(int sc);

	void AddScore(int a);
	

	Score() {};
	~Score() {};
};

