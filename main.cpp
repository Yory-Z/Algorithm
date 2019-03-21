
#include "stringoperation/MinimumWindowSubstring.h"

void test();

void normalTest() {
    string str = "abcdefg";
    cout<<(str.find("a"))<<endl;
    cout<<(str.find("f"))<<endl;
    cout<<(str.find("g"))<<endl;
    cout<<(str.find("o"))<<endl;
    cout<<UINT32_MAX<<endl;
}

int main(){

    test();
    return 0;

}

void test() {

    MinimumWindowSubstring test;
    test.test();
}

