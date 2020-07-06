#pragma once


//スコア管理クラス
class ScoreManager
{
private:
	


 public:
	
	int GetScore() const;////スコアを取得
	void SetScore(int inScore);//スコアをセット

	void AddScore(int inAddScore);//消去パターンに応じてスコアを加算
	
	int GetHighScore() const;//　ハイスコアをゲット
	void SetHighScore(int inHiScore);// ハイスコアをセット


	//Score() {};
	//~Score() {};
};

