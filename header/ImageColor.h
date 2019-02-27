//
// Created by Yory on 2018/12/22.
//

#ifndef ALGORITHM_IMAGECOLOR_H
#define ALGORITHM_IMAGECOLOR_H

#endif //ALGORITHM_IMAGECOLOR_H

class ImageColor{
public:
    void testImageColor();

private:
    bool Ok(int k);
    void BackTrack(int t);

    int nodeSum;//图的顶点个数
    int colorSum;//颜色个数
    int **image;
    int *solve;
    long solveSum;
};

void ImageColor::testImageColor(){
    nodeSum = 5;
    colorSum = 4;
    solveSum = 0;

/*
0 1 1 1 0
1 0 1 1 1
1 1 0 1 0
1 1 1 0 1
0 1 0 1 0
*/

    image = new int*[nodeSum];
    solve = new int[nodeSum];
    for(int i = 0; i < nodeSum; ++i){
        image[i] = new int[nodeSum];
        solve[i] = 0;
        for (int j = 0; j < nodeSum; ++j) {
            cin>>image[i][j];
        }
    }

    cout<<endl;
    BackTrack(0);
    cout<<"sum: "<<solveSum<<endl;
}

bool ImageColor::Ok(int k) {
    //遍历此结点的颜色是否与相邻结点的颜色相同
    for (int i = 0; i < nodeSum; ++i) {
        if(image[k][i] == 1 && solve[i] == solve[k]) {
            return false;
        }
    }
    return true;
}

void ImageColor::BackTrack(int t) {
    if(t == nodeSum){
        ++solveSum;
        for (int j = 0; j < nodeSum; ++j) {
            cout<<solve[j]<<' ';
        }
        cout<<endl;
        return;
    }

    for (int j = 1; j <= colorSum; ++j) {
        solve[t] = j;
        if(Ok(t)){
            BackTrack(t+1);
        }
        solve[t] = 0;
    }
}


