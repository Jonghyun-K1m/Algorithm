#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int k;
    string first;
    for(auto& i:phone_book){
        for(auto& j:phone_book) {
            if(i==j)continue;
            if(i.size()>j.size()){
                k=i.find(j);
            }else{
            if(k==0){
                answer=false;
                break;   
            }
        } 
        
    }

    return answer;
}
