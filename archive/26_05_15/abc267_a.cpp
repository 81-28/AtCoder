// https://atcoder.jp/contests/abc267/tasks/abc267_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    map<string,int> m={
        {"Mo",5},
        {"Tu",4},
        {"We",3},
        {"Th",2},
        {"Fr",1}
    };
    string s;
    cin >> s;
    print(m[s.substr(0,2)]);

    return 0;
}
