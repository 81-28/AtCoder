// https://atcoder.jp/contests/abc309/tasks/abc309_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi g(n+1);
    int p;
    for (int i=2; i<=n; i++) {
        cin >> p;
        g[p].pb(i);
    }
    map<int,int> mp;
    pii pa;
    rep(i,m) {
        cin >> pa;
        mp[pa.first]=max(mp[pa.first],pa.second);
    }
    set<int> s;
    queue<pii> q;
    q.push({1,0});
    pii pos;
    while (!q.empty()) {
        pos=q.front();
        q.pop();
        if (pos.second||mp[pos.first]) s.insert(pos.first);
        for (int val:g[pos.first]) {
            q.push({val,max(pos.second-1,mp[pos.first])});
        }
    }
    print(s.size());


    return 0;
}
