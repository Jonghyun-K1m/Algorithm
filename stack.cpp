#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int size=s.size();
    stack<char> nstack;
    int check_zero=0;
    int i=0;
//    cout<<size;
   
    for(int i=0;i<size;i++){
        if(s[i]=='(')nstack.push('(');
            else{
                if(i==0){
                    check_zero=1;
                    break;
                }
                nstack.pop();
       //         cout<<"vist"<<i;
     //           cout<<s[i];
            }
    }
    
   // cout<<check_zero<<endl;

    if(nstack.empty() && check_zero ==0 )answer=true;
    else answer=false;
    return answer;
}
