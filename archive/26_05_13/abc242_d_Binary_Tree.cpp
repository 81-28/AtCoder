// https://atcoder.jp/contests/abc242/tasks/abc242_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    int q;
    cin >> s >> q;
    while (q--) {
        int t,k;
        cin >> t >> k;
        --k;
        int sm=0;
        rep(i,t) {
            if (k==0) {
                sm+=t-i;
                break;
            }
            if (k&1) sm+=2;
            else ++sm;
            k/=2;
        }
        print(char('A'+(s[k]-'A'+sm)%3));
    }

    return 0;
}
