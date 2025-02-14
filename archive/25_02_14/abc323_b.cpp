// https://atcoder.jp/contests/abc323/tasks/abc323_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> s(n);
    cin >> s;
    v<pii> ans(n);
    pii p;
    rep(i,n) {
        p = {0,i+1};
        rep(j,n) {
            if (i!=j && s[i][j] == 'o') {
                p.first--;
            }
        }
        ans[i] = p;
    }
    sort(all(ans));
    rep(i,n) cout << (i?" ":"") << ans[i].second;
    cout<<'\n';

    return 0;
}
