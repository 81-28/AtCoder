// https://atcoder.jp/contests/abc381/tasks/abc381_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
template<typename T>
using v=vector<T>;
using vi=v<int>;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    if (n%2) {
        YesNo(0);
        return 0;
    }
    vi cn(26,0);
    rep(i,n/2) {
        if (s[i*2] == s[i*2+1]) {
            if (cn[s[i*2]-'0']) {
                YesNo(0);
                return 0;
            }
            cn[s[i*2]-'0']++;
        } else {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
