
#include "stringoperation/SimplifyPath.h"

void test();

void normalTest() {
    string path = "1231/23432///123/.../.././";
    string res, tmp;
    stringstream ss(path);
    while (getline(ss, tmp, '/')) {
        cout<<tmp<<endl;
    }
}

int main(){

    test();
    return 0;

}

void test() {

    SimplifyPath test;
    test.test();
}

