#include "Data.h"


//"HiScore.txt"���n�C�X�R�A���擾
int Data::HiScoreLoad() {
    std::ifstream ifs("HiScore.txt");
    std::string str;
    
    //�擾�ł��Ȃ��ꍇ�ُ͈�I��
    if (ifs.fail()) {
        return -1;
    }
    //��s�擾 #ToDo �����L���O��݂���̂ł���΃n�C�X�R�A�e�[�u����݂��Ď�������
    std::getline(ifs, str);

    HiScore = atoi(str.c_str());

    return (HiScore);
}

//�n�C�X�R�A��"HiScore.txt"�ɕۑ�����
void Data::HiScoreSave(int inHiScore) {
    std::ofstream outputfile("HiScore.txt");
    
    outputfile << inHiScore;
    outputfile.close();
}