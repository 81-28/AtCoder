// https://atcoder.jp/contests/joi2023ho/tasks/joi2023ho_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    unordered_map<int,int> mp;
    unordered_map<int,int> c;
    int j=1;
    rep(i,n) {
        if (!mp[a[i]]) {
            mp[a[i]]=j;
            c[j]=a[i];
            ++j;
        }
    }
    // 若い番号が消えて、繋がらず、後に出てきた時、数の大小の関係で見たら間違いとなる
    // {数,個数}
    deque<pii> q;
    rep(i,n) {
        int now=mp[a[i]];
        print(now);
        int sm=1;
        for (;!q.empty(); q.pop_back()) {
            auto[num,cnt]=q.back();
            print(num,cnt);
            if (num<now) break;
            sm+=cnt;
        }
        q.pb({now,sm});
    }
    for (;!q.empty(); q.pop_front()) {
        auto[num,cnt]=q.front();
        rep(i,cnt) print(c[num]);
    }

    return 0;
}
