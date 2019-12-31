/*
https://programmers.co.kr/learn/courses/30/lessons/42578


*/


#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> m;
    map<string,int>::iterator it;
    
    vector<string> temp;
    
    for(auto& i:clothes){
        
        m[i[1]]++;
        
    }
    for(it=m.begin();it!=m.end();it++){
        answer=answer*(it->second+1);
    }
    return answer-1;
}
