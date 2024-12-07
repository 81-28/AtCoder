// https://atcoder.jp/contests/abc383/tasks/abc383_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,t,tt,v;
    cin >> n;
    int ans = 0;
    rep(i,n) {
        cin >> t >> v;
        if (i!=0) {
            ans -= (t-tt);
            if (ans<0) ans=0;
        }
        tt = t;
        ans += v;
    }
    print(ans);

    return 0;
}
