//
// Created by Yory on 2019/2/5.
//

#ifndef ALGORITHM_WORDSEARCH_H
#define ALGORITHM_WORDSEARCH_H

#include <vector>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

class WordSearch{
public:
    void test();

private:
    vector<vector<bool>> visit;
    int dire[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int row, col;

    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        assert(board.size() > 0);
        col = board.at(0).size();
        visit = vector<vector<bool>>(row, vector<bool>(col, false));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (search(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, string& word, int index, int startX, int startY) {
        if (index == word.size() - 1) {
            return word.at(index) == board.at(startX).at(startY);
        }

        if (word.at(index) == board.at(startX).at(startY)) {
            visit[startX][startY] = true;

            for (int i = 0; i < 4; ++i) {
                int newX = startX + dire[i][0];
                int newY = startY + dire[i][1];
                if (inArea(newX, newY) && !visit[newX][newY] &&
                search(board, word, index + 1, newX, newY)) {
                    return true;
                }
            }

            visit[startX][startY] = false;
        }
        return false;
    }

    bool inArea(int x, int y) {
        return x >= 0 && x < row && y >= 0 && y < col;
    }
};

void WordSearch::test() {
    vector<vector<char>> board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
    };

//    string word = "ABCCED";
//    string word = "SEE";
//    string word = "ABCB";
    string word = "ESCFDASABC";

    bool res = exist(board, word);
    cout<<"res: "<<res;

}

#endif //ALGORITHM_WORDSEARCH_H
