// https://atcoder.jp/contests/ACcareer27/tasks/ACcareer27_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    if (s.size()<=1) {
        YesNo(0);
        return 0;
    }
    YesNo(s[0]=='A'&&s[1]=='C');

    return 0;
}
