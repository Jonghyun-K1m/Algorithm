/*

https://programmers.co.kr/learn/courses/30/lessons/42579

*/

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
template<template<typename> class P=less>
struct compare_sec{
    template<class T1,class T2> bool operator()
    (const pair<T1,T2>&left, const pair<T1,T2> &right){
        return P<T2>()(left.second,right.second);
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
   
    multimap<string,int> m;
    multimap<string,int>::iterator it;
    map<string,int> max;
    map<string,int>::iterator its;
    
    for(int i=0;i<plays.size();i++){
        it=m.find(genres[i]);
        if(it==m.end()) {
            cout<<"pp+++"<<it->second<<"+++"<<plays[i]<<endl;
            m.insert(make_pair(genres[i],plays[i]));//없
            
        }
        else  { //있
            cout<<"as+++"<<it->second<<"+++"<<plays[i]<<endl;
            m.erase(genres[i]);
            m.insert(make_pair(genres[i],it->second+plays[i]));
        }        
    }
    
     vector<pair<string,int>> vd(m.begin(),m.end());
     sort(vd.begin(),vd.end(),compare_sec<greater>());
    vector<pair<string,int>>::iterator iss;
    for(iss=vd.begin();iss!=vd.end();iss++){
        cout<<iss->first<<iss->second<<endl;    
    }
    /*
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<it->second<<endl;    
    }*/
    return answer;
}
