// https://atcoder.jp/contests/abc483/tasks/abc483_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    // {番号,票数}
    map<int,int> cnt;
    // g[i][j]:1希望がiで2希望がjの票数
    v<unordered_map<int,int>> g(n);
    // {-票数,番号}
    set<pii> s;
    while (m--) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        ++cnt[a];
        ++g[a][b];
    }
    rep(i,n) s.insert({-cnt[i],i});
    rep(i,n) {
        // i番目が辞退する場合の票の移動をさせる
        pii tmp={-cnt[i],i};
        s.erase(tmp);
        for (auto[num,c]:g[i]) {
            pii p={-cnt[num],num};
            s.erase(p);
            cnt[num]+=c;
            p={-cnt[num],num};
            s.insert(p);
        }

        print(s.begin()->second +1);

        // 戻す
        for (auto[num,c]:g[i]) {
            pii p={-cnt[num],num};
            s.erase(p);
            cnt[num]-=c;
            p={-cnt[num],num};
            s.insert(p);
        }
        s.insert(tmp);
    }

    return 0;
}
