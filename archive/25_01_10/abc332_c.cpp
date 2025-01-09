// https://atcoder.jp/contests/abc332/tasks/abc332_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    string s;
    cin >> n >> m >> s;
    int c1=0,c2=0;
    int ans=0;
    rep(i,n) {
        if (s[i]=='0') {
            c1 = max(c1-m,0);
            ans = max(ans,c1+c2);
            c1=0,c2=0;
        }
        if (s[i]=='1') c1++;
        if (s[i]=='2') c2++;
    }
    c1 = max(c1-m,0);
    ans = max(ans,c1+c2);
    print(ans);

    return 0;
}
