#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    for(auto& i:completion){
        for(auto& j:participant){
            if(i==j){
                j="default";
                break;   
            }
            
        }
    }
    for(auto& j:participant){
        if(j!="default")answer=j;
       // cout<<j;   
    }
    return answer;
}
