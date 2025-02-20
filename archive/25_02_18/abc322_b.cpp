// https://atcoder.jp/contests/abc322/tasks/abc322_b

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    string s,t;
    cin >> n >> m >> s >> t;
    if (t.substr(0,n) == s) {
        if (t.substr(m-n,n) == s) print(0);
        else print(1);
    } else {
        if (t.substr(m-n,n) == s) print(2);
        else print(3);
    }

    return 0;
}
