#pragma warning(disable:4996)
#include "Data.h"

static int HiScore;



int Data::HiScoreLoad() {
    std::ifstream ifs("HiScore.txt");
    std::string str;
    

    if (ifs.fail()) {
        return -1;
    }
    std::getline(ifs, str);

    HiScore = atoi(str.c_str());

    return (HiScore);
}

void Data::HiScoreSave(int sc) {
    std::ofstream outputfile("HiScore.txt");
    outputfile << sc;
    outputfile.close();
}