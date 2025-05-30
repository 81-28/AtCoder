// https://atcoder.jp/contests/abc301/tasks/abc301_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int cnt=0;
    int last;
    rep(i,n) {
        bool t=s[i]=='T';
        cnt+=t*2-1;
        last=t;
    }
    print((cnt>0||(cnt==0&&!last))?'T':'A');

    return 0;
}
