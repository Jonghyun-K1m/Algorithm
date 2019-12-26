#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    multimap<string,int> m;
    multimap<string,int>::iterator it;
    for(auto& i : participant){
        m.insert(make_pair(i,5));
    }
    for(auto& j : completion){
       it=m.find(j);
       it->second=10;
    }
    for(it = m.begin(); it != m.end(); it++)
        if(it->second==5){
            cout << it->first << ' ' << it->second << '\n';
            answer=it->first;
        }
    return answer;
}
