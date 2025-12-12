// https://atcoder.jp/contests/abc402/tasks/abc402_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi ten(2*n-1);
    ten[0]=1;
    rep1(i,n*2-2) ten[i]=ten[i-1]*10%m;
    vvi a(n,vi(n));
    rep(i,n)rep(j,n) {
        cin >> a[i][j];
        a[i][j]*=ten[n*2-2-i-j];
        a[i][j]%=m;
    }
    if (n==1) {
        print(a[0][0]);
        return 0;
    }
    v<v<set<int>>> s(n,v<set<int>>(n));
    // 左上から半分
    s[0][0].insert(a[0][0]);
    rep1(i,n-1) {
        int x=i;
        for (int y=0; x>=0; --x,++y) {
            if (x) {
                for (int val:s[x-1][y]) s[x][y].insert((a[x][y]+val)%m);
            }
            if (y) {
                for (int val:s[x][y-1]) s[x][y].insert((a[x][y]+val)%m);
            }
        }
    }
    // 右下から半分
    s[n-1][n-1].insert(a[n-1][n-1]);
    for (int i=n-2; i>0; --i) {
        int x=i;
        for (int y=n-1; x<n; ++x,--y) {
            if (x<n-1) {
                for (int val:s[x+1][y]) s[x][y].insert((a[x][y]+val)%m);
            }
            if (y<n-1) {
                for (int val:s[x][y+1]) s[x][y].insert((a[x][y]+val)%m);
            }
        }
    }
    int ans=0;
    rep(x,n) {
        int y=n-1-x;
        if (x<n-1) {
            for (int val:s[x+1][y]) {
                auto it=s[x][y].lower_bound(m-val);
                if (it!=s[x][y].begin()) {
                    --it;
                    chmax(ans,*it+val);
                } else chmax(ans,(*s[x][y].rbegin()+val)%m);
            }
        }
        if (y<n-1) {
            for (int val:s[x][y+1]) {
                auto it=s[x][y].lower_bound(m-val);
                if (it!=s[x][y].begin()) {
                    --it;
                    chmax(ans,*it+val);
                } else chmax(ans,(*s[x][y].rbegin()+val)%m);
            }
        }
    }
    print(ans);

    return 0;
}
