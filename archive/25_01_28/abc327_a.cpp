// https://atcoder.jp/contests/abc327/tasks/abc327_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s,t;
    cin >> n >> s;
    rep(i,n-1) {
        t=s.substr(i,2);
        if(t=="ab" || t=="ba") {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}