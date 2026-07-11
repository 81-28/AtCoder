// https://atcoder.jp/contests/abc466/tasks/abc466_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,m;
    cin >> n >> m;
    map<int,vi> mp;
    rep1(i,n) {
        int c,s;
        cin >> c >> s;
        mp[c].pb(s);
    }
    rep1(k,m) {
        int l=mp[k].size();
        if (!l) {
            cout<<-1<<' ';
            continue;
        }
        sort(rall(mp[k]));
        cout<<mp[k][0]<<' ';
    }

    return 0;
}
