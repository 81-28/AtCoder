// https://atcoder.jp/contests/abc225/tasks/abc225_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define pb push_back

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vi p,c;
void dfs(const int& n,vi& vec) {
    if (n==-1) return;
    dfs(p[n],vec);
    vec.pb(n);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    p=c=vi(n+1,-1);
    while (q--) {
        int m,x,y;
        cin >> m >> x;
        if (m!=3) {
            cin >> y;
            if (m==1) c[x]=y,p[y]=x;
            else c[x]=p[y]=-1;
        } else {
            vi res;
            dfs(x,res);
            for (int y=c[x]; y!=-1; y=c[y]) res.pb(y);
            cout<<res.size()<<' ';
            print(res);
        }
    }

    return 0;
}
