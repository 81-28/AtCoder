// https://atcoder.jp/contests/abc393/tasks/abc393_a

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s,t;
    cin >> s >> t;
    if(s=="sick") {
        if(t=="sick") print(1);
        else print(2);
    } else {
        if(t=="sick") print(3);
        else print(4);
    }

    return 0;
}
