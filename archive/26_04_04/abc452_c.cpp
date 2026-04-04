// https://atcoder.jp/contests/abc452/tasks/abc452_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    // mp[i][j]:文字数iのj文字目としてあり得る文字
    map<int,map<int,set<char>>> mp;
    int m;
    cin >> m;
    v<string> s(m);
    rep(i,m) {
        cin >> s[i];
        int l=s[i].size();
        rep(j,l) mp[l][j].insert(s[i][j]);
    }
    rep(i,m) {
        int l=s[i].size();
        if (l!=n) {
            YesNo(0);
            continue;
        }
        bool ok=1;
        rep(j,n) {
            auto[a,b]=p[j];
            if (mp[a][b-1].find(s[i][j])==mp[a][b-1].end()) {
                ok=0;
                break;
            }
        }
        YesNo(ok);
    }

    return 0;
}
