#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
string valueA, valueB;
vector<int> digitsA;
vector<int> digitsB;
int baseA, baseB;
unsigned long long int resultA, resultB;
void fillDigits(){
    for (auto digit : valueA){
        if(isdigit(digit)) digitsA.push_back(digit-'0');
        else digitsA.push_back(digit - 55);
    }
    for (auto digit : valueB){
        if(isdigit(digit)) digitsB.push_back(digit-'0');
        else digitsB.push_back(digit - 55);
    }
    baseA = (*max_element(digitsA.begin(),digitsA.end()))+1;
    baseB = (*max_element(digitsB.begin(),digitsB.end()))+1;

    if(baseA < 2) baseA = 2;
    if(baseB < 2) baseB = 2;

}

void resultNumA(){
    resultA = 0;
    int length = digitsA.size();
    for(int i = 0; i < length;i++){
        resultA+=pow(baseA,i)*digitsA[length-1-i];
    }
}

void resultNumB(){
    resultB = 0;
    int length = digitsB.size();
    for(int i = 0; i < length;i++){
        resultB+=pow(baseB,i)*digitsB[length-1-i];
    }
}


void findBases(){
    if(baseA > 36 || baseB > 36) cout<<valueA<<" is not equal to "<<valueB<<" in any base 2..36"<<endl;
    else if(resultA == resultB) cout<<valueA<<" (base "<<baseA<<") = "<<valueB<<" (base "<<baseB<<")"<<endl;
    else if(resultA>resultB){
        baseB++;
        resultNumB();
        findBases();
    }
    else{
        baseA++;
        resultNumA();
        findBases();
    }
}

void results(){
    resultNumA();
    resultNumB();
}

int main(){
    while(cin>>valueA>>valueB){
        fillDigits();
        results();
        findBases();
        digitsA.clear();
        digitsB.clear();
    }
}
