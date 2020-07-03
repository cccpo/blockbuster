#include <iostream>

#include "GameBoard.h"

#include "../state/ScoreManager.h"

typedef unsigned char byte;

using std::cout;
using std::endl;

static int sBoard[GameBoard::mGbWidth + 2][GameBoard::mGbHeight + 2];

// �Q�[���{�[�h������
void GameBoard::InitGameBoard() {

    //�Q�[���{�[�h�����̏�����
    for (int x = 1; x < mGbWidth + 1; ++x) {
        for (int y = 1; y < mGbHeight + 1; ++y) {
            sBoard[x][y] = GetmEmpty();    
        }
    }
  
    //�Q�[���{�[�h�O�g�̏�����
    for (int x = 0; x <= mGbWidth + 1; ++x) {
        sBoard[x][0] = sBoard[x][mGbHeight + 1] = mOuterFrame;
    }
    for (int y = 0; y <= mGbHeight + 1; ++y) {
        sBoard[0][y] = sBoard[mGbWidth + 1][y] = mOuterFrame;
    }

};

// �Q�[���{�[�h�̒l���Q�b�g
int GameBoard::GetGameBoardValue(int x, int y) {
    int s = sBoard[x][y];
    return s;
}

// �Q�[���{�[�h�̒l���Z�b�g
void GameBoard::SetTerimonoValue(int x,int y,int val) {
    sBoard[x][y] = val;
}

// ��i���Ƃ�(�������Ƃ��Ɏg�p)
void GameBoard::Down(int y) {

    while (y > 1) {
        for (int x = 1; x <= mGbWidth; ++x)
            sBoard[x][y] = sBoard[x][y - 1];     // �P�s���Ɉړ�
        --y;      //  ��̍s��
    }
    
    for (int x = 1; x <= mGbWidth; ++x)
        sBoard[x][1] = 0;     // �ŏ�s�͋��
}

// �������֐�
int GameBoard::GetmEmpty() const{
    return mEmpty;
}

// �Q�[���{�[�h��x���W��Ԃ�
int GameBoard::GetmGameBoardPosX() const{
    return mGameBoardPosX;
}

// �Q�[���{�[�h��y���W��Ԃ�
int GameBoard::GetmGameBoardPosY() const{
    return mGameBoardPosY;
}

GameBoard::GameBoard() :mGameBoardPosX(1),mGameBoardPosY(2){

}

//�@�Q�[���{�[�h�𐶐�������W�y�т�^����
GameBoard::GameBoard(int x,int y) :mGameBoardPosX(x),mGameBoardPosY(y){
}




