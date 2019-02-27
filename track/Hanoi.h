//
// Created by Yory on 2018/12/29.
//

#ifndef ALGORITHM_HANOI_H
#define ALGORITHM_HANOI_H

class Hanoi {
public:
    Hanoi(int distSum);
    ~Hanoi();

private:
    int diskNumber;//总圆盘数
    int movedSum;//总共移动的次数
    void HanoiRecur(int distNumber, char from, char temp, char to);
    void PrintMove(int distNumber, char from, char to);
};

Hanoi::Hanoi(int distSum) {
    movedSum = 0;
    diskNumber = distSum;
    char from = 'A';
    char temp = 'B';
    char to = 'C';
    HanoiRecur(diskNumber, from, temp, to);
}

Hanoi::~Hanoi() {
    cout<<"Moved sum is: "<<movedSum<<endl;
}

//将n个圆盘从from借助temp移动至to
void Hanoi::HanoiRecur(int distNumber, char from, char temp, char to) {
    if (distNumber == 1){
        PrintMove(distNumber, from, to);
    } else {
        //先将n-1个圆盘从from借助to移动至temp暂存
        HanoiRecur(distNumber - 1, from, to, temp);
        //上一步已经将n-1个圆盘移动至temp,此时将第n个圆盘，即最大的圆盘，从from移动至to
        PrintMove(distNumber, from, to);
        //最后一步，将n-1个暂存在temp的圆盘借助from移动至to圆盘
        HanoiRecur(distNumber - 1, temp, from, to);
    }
}

void Hanoi::PrintMove(int distNumber, char from, char to) {
    ++movedSum;
    cout<<"Move "<<distNumber<<" from "<<from<<" to "<<to<<endl;
}

#endif //ALGORITHM_HANOI_H
