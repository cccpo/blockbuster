#include <iostream>

#include "GameBoard.h"

#include "../state/Score.h"

typedef unsigned char byte;

using std::cout;
using std::endl;

int gBoard[GameBoard::mGbWidth + 2][GameBoard::mGbHeight + 2];

// �Q�[���{�[�h������
void GameBoard::InitGameBoard() {

    //�Q�[���{�[�h�����̏�����
    for (int x = 1; x < mGbWidth + 1; ++x) {
        for (int y = 1; y < mGbHeight + 1; ++y) {
            gBoard[x][y] = GetmEmpty();    
        }
    }
  
    //�Q�[���{�[�h�O�g�̏�����
    for (int x = 0; x <= mGbWidth + 1; ++x) {
        gBoard[x][0] = gBoard[x][mGbHeight + 1] = mOuterFrame;
    }
    for (int y = 0; y <= mGbHeight + 1; ++y) {
        gBoard[0][y] = gBoard[mGbWidth + 1][y] = mOuterFrame;
    }

};

int GameBoard::GetGameBoardValue(int x, int y) {
    int s = gBoard[x][y];
    return s;
}

void GameBoard::SetTerimonoValue(int x,int y,int val) {
    gBoard[x][y] = val;
}

void GameBoard::Down(int y) {

    while (y > 1) {
        for (int x = 1; x <= mGbWidth; ++x)
            gBoard[x][y] = gBoard[x][y - 1];     // �P�s���Ɉړ�
        --y;      //  ��̍s��
    }
    for (int x = 1; x <= mGbWidth; ++x)
        gBoard[x][1] = 0;     // �ŏ�s�͋��
}



int GameBoard::GetmEmpty() const{
    return mEmpty;
}



int GameBoard::GetmGameBoardPosX() const{
    return mGameBoardPosX;
}

int GameBoard::GetmGameBoardPosY() const{
    return mGameBoardPosY;
}

GameBoard::GameBoard() :mGameBoardPosX(1),mGameBoardPosY(2){

}

//�@�Q�[���{�[�h�𐶐�������W�y�т�^����
GameBoard::GameBoard(int x,int y) :mGameBoardPosX(x),mGameBoardPosY(y){
}




