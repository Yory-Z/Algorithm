//
// Created by Yory on 2019/2/1.
//

#ifndef ALGORITHM_SUDOKU_H
#define ALGORITHM_SUDOKU_H

#include <vector>
#include <set>
#include <string>
using namespace std;

class Sudoku {
public:
    static void test();

private:
    static bool isValidSudoku(vector<vector<char>>& board);

    static bool checkRow(vector<vector<char>>& board);

    static bool checkColumn(vector<vector<char>>& board);

    static bool checkSubbox(vector<vector<char>>& board);

};

void Sudoku::test() {
/*    char arr{9}{9} = {
    {'5', '3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    };*/

/*    char arr{9}{9} = {
    {'8','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    };*/
    
/*    char arr{}{9} ={
            {'.','.','4','.','.','.','6','3','.'},
            {'.','.','.','.','.','.','.','.','.'},
            {'5','.','.','.','.','.','.','9','.'},
            {'.','.','.','5','6','.','.','.','.'},
            {'4','.','3','.','.','.','.','.','1'},
            {'.','.','.','7','.','.','.','.','.'},
            {'.','.','.','5','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.','.'}
        };*/

    char arr[][9] = {
            {'.','.','.','.','5','.','.','1','.'},
            {'.','4','.','3','.','.','.','.','.'},
            {'.','.','.','.','.','3','.','.','1'},
            {'8','.','.','.','.','.','.','2','.'},
            {'.','.','2','.','7','.','.','.','.'},
            {'.','1','5','.','.','.','.','.','.'},
            {'.','.','.','.','.','2','.','.','.'},
            {'.','2','.','9','.','.','.','.','.'},
            {'.','.','4','.','.','.','.','.','.'}
            };

    vector<vector<char>> vec;
    for (int i = 0; i < 9; ++i) {
        vector<char> temp;
        for (int j = 0; j < 9; ++j) {
            temp.push_back(arr[i][j]);
        }
        vec.push_back(temp);
    }

    bool res = isValidSudoku(vec);

    cout<<"res: "<<res<<endl;
}

bool Sudoku::isValidSudoku(vector<vector<char>>& board) {
    bool res = true;
    res = checkRow(board);
    if(!res) {
        return false;
    }

    res = checkColumn(board);
    if(!res) {
        return false;
    }

    return checkSubbox(board);
}

bool Sudoku::checkRow(vector<vector<char>>& board) {
    for(int i = 0; i < 9; ++i){
        vector<bool> temp(9, false);
        for(int j = 0; j < 9; ++j) {
            char ch = board.at(i).at(j);
            if(ch != '.'){
                int digit = ch - '0' - 1;
                if(temp.at(digit)){
                    return false;
                }
                temp.at(digit) = true;
            }
        }
    }
    return true;
}

bool Sudoku::checkColumn(vector<vector<char>>& board) {
    for(int i = 0; i < 9; ++i){
        vector<bool> temp(9, false);
        for(int j = 0; j < 9; ++j) {
            char ch = board.at(j).at(i);
            if(ch != '.'){
                int digit = ch - '0' - 1;
                if(temp.at(digit)){
                    return false;
                }
                temp.at(digit) = true;
            }
        }
    }
    return true;
}

bool Sudoku::checkSubbox(vector<vector<char>>& board) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {

            vector<bool> temp(9, false);
            for(int m = i * 3; m < i * 3 + 3; ++m) {
                for(int n = j * 3; n < j * 3 + 3; ++n) {
                    char ch = board.at(m).at(n);
                    if(ch != '.'){
                        int digit = ch - '0' - 1;
                        if(temp.at(digit)){
                            return false;
                        }
                        temp.at(digit) = true;
                    }
                }
            }
        }
    }
    return true;
}

#endif //ALGORITHM_SUDOKU_H
