#pragma once


//�X�R�A�Ǘ��N���X
class ScoreManager
{
private:
	


 public:
	
	const int GetScore();////�X�R�A���擾
	void SetScore(int inScore);//�X�R�A���Z�b�g

	void AddScore(int inAddScore);//�����p�^�[���ɉ����ăX�R�A�����Z
	int AddScoreWin32(int inDeletePattern);


	const int GetHighScore();//�@�n�C�X�R�A���Q�b�g
	void SetHighScore(int inHiScore);// �n�C�X�R�A���Z�b�g


	//Score() {};
	//~Score() {};
};

