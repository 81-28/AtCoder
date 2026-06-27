// https://atcoder.jp/contests/abc464/tasks/abc464_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,m;
    cin >> n >> m;
    map<int,int> cnt;
    // {前,後}の色
    map<int,v<pii>> p;
    rep1(i,n) {
        int a,d,b;
        cin >> a >> d >> b;
        p[d].pb({a,b});
        ++cnt[a];
    }
    rep1(i,m) {
        for (auto[a,b]:p[i]) {
            if (!--cnt[a]) cnt.erase(cnt.find(a));
            ++cnt[b];
        }
        print(cnt.size());
    }

    return 0;
}
