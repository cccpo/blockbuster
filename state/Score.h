#pragma once


//�X�R�A�Ǘ��N���X
class Score
{
private:
	


 public:
	 int mScore = 0;
	
	int GetScore() const;////�X�R�A���擾
	void SetScore(int sc);//�X�R�A���Z�b�g

	void AddScore(int a);//�����p�^�[���ɉ����ăX�R�A�����Z
	
	int GetHighScore() const;//�@�n�C�X�R�A���Q�b�g
	void SetHighScore(int a);// �n�C�X�R�A���Z�b�g


	//Score() {};
	//~Score() {};
};

