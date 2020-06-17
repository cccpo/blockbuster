#pragma once


//スコア管理クラス
class Score
{
private:
	


 public:
	 int mScore = 0;
	
	int GetScore() const;////スコアを取得
	void SetScore(int sc);//スコアをセット

	void AddScore(int a);//消去パターンに応じてスコアを加算
	
	int GetHighScore() const;//　ハイスコアをゲット
	void SetHighScore(int a);// ハイスコアをセット


	//Score() {};
	//~Score() {};
};

