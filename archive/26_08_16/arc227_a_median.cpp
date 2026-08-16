// https://atcoder.jp/contests/arc227/tasks/arc227_a

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    v<string> s(3);
    cin >> n >> s;
    vvi idx(3);
    rep(i,3) {
        rep(j,2*n) {
            if (s[i][j]=='0') continue;
            idx[i].pb(j);
        }
    }
    int ans=0;
    string str(n*2,'0');
    rep(j,n) {
        vi a;
        rep(i,3) a.pb(idx[i][j]);
        sort(all(a));
        int k=a[1];
        str[k]='1';
        rep(i,3) ans+=abs(k-idx[i][j]);
    }
    print(ans);
    print(str);

    return 0;
}
