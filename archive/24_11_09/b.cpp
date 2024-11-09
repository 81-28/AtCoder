// https://atcoder.jp/contests/abc379/tasks/abc379_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    int combo = 0;
    rep(i,n) {
        if (s[i] == 'O') {
            combo++;
        } else {
            ans += combo/k;
            combo = 0;
        }
    }
    ans += combo/k;
    print(ans);

    return 0;
}
