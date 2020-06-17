#pragma once
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Data

{
private:

public:

	int HiScoreLoad();//"HiScore.txt"よりハイスコアを取得
	void HiScoreSave(int sc);//ハイスコアを"HiScore.txt"に保存する
};

