// https://atcoder.jp/contests/abc411/tasks/abc411_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    v<bool> c(n,0);
    int ans=0;
    rep(i,q) {
        int a;
        cin >> a;
        --a;
        if (c[a]) {
            if ((a&&c[a-1]) && (a<n-1&&c[a+1])) ++ans;
            if ((a<=0||!c[a-1]) && (a>=n-1||!c[a+1])) --ans;
        } else {
            if ((a&&c[a-1]) && (a<n-1&&c[a+1])) --ans;
            if ((a<=0||!c[a-1]) && (a>=n-1||!c[a+1])) ++ans;
        }
        print(ans);
        c[a]=!c[a];
    }

    return 0;
}
