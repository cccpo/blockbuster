#pragma once
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

static int HiScore;

class Data

{
private:

public:

	int HiScoreLoad();//"HiScore.txt"���n�C�X�R�A���擾
	void HiScoreSave(int inHiScore);//�n�C�X�R�A��"HiScore.txt"�ɕۑ�����
};

