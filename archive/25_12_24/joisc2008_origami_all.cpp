// https://atcoder.jp/contests/joisc2008/tasks/joisc2008_origami

#include<bits/stdc++.h>
using namespace std;

template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,a,b;
    cin >> n >> a >> b;
    int mx=0,ans=0;
    unordered_map<int,unordered_map<int,int>> m;
    while (n--) {
        int p,q,r,s;
        cin >> p >> q >> r >> s;
        // 矩形が狭いので、実際に重ねる
        for (int i=p; i<=r; ++i)for(int j=q; j<=s; ++j) {
            ++m[i][j];
            if (chmax(mx,m[i][j])) ans=1;
            else if (mx==m[i][j]) ++ans;
        }
    }
    print(mx);
    print(ans);

    return 0;
}
