#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    
    int answer = 0;
    int count=0;
    int first,second;
    priority_queue<int, vector<int>, greater<int> >pq;
    
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    while(pq.size()>=2 && pq.top()<K){
            first=pq.top();
            pq.pop();
            second=pq.top();
            pq.pop();
        
            second=first+(second*2);
            pq.push(second);
            count++;
    }


   // cout<<pq.top();
    if(pq.top()<K)answer=-1;
    else answer=count;
    /*
        cout<<endl;
    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }*/
    return answer;
}
