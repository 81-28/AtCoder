// https://atcoder.jp/contests/abc330/tasks/abc330_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
using ll=long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> s(n);
    cin >> s;
    v<v<bool>> o(n,v<bool>(n,0));
    vvi gr(n),gc(n);
    rep(i,n)rep(j,n) {
        if (s[i][j] == 'o') {
            o[i][j] = 1;
            gr[i].pb(j);
            gc[j].pb(i);
        }
    }
    ll ans = 0;
    rep(i,n)rep(j,n) {
        if (o[i][j]) {
            ans += (gr[i].size()-1)*(gc[j].size()-1);
        }
    }
    print(ans);

    return 0;
}
