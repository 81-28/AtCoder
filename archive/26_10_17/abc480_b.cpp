// https://atcoder.jp/contests/abc480/tasks/abc480_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<string> s(n);
    cin >> s;
    vi ans(n,0);
    rep(i,m) {
        string t;
        cin >> t;
        bool ok=0;
        int cnt=0,idx=-1;
        rep(j,n) {
            if (s[j]==t) {
                ok=1;
                idx=j;
                break;
            }
            int l=t.size();
            if (s[j].size()!=l) continue;
            int dif=0;
            rep(k,l) {
                if (s[j][k]!=t[k]) ++dif;
            }
            if (dif<2) {
                ++cnt;
                idx=j;
            }
        }
        if (ok || cnt==1) ++ans[idx];
    }
    for (int val:ans) print(val);

    return 0;
}
