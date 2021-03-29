#include generate.h
#include <cstdlib>
#include <ctime>
#include <string>

int * FOS::generateRandomNum(int range,int upperBound,int lowerBound){
    srand((unsigned) time(0));
    int arrayInt[range];   
    for(int i=0; i<range; i++){
        arrayInt[i] = (rand()%upperBound)+lowerBound;
    }
    return arrayInt;
}




string FOS:: generateRandomString(int len) {
    string s;
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return s;
}


string * FOS::gen_Rand_Strings(int length,int range){
    
    string randStrings[range];
    for(int i=0; i<range; i++){
        randStrings[i]= generateRandomString
    }





}