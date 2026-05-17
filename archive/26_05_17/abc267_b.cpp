// https://atcoder.jp/contests/abc267/tasks/abc267_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    vb b(10,0);
    vi a={3,2,4,1,3,5,0,2,4,6};
    vi cnt(7,0);
    rep(i,10) {
        b[i]=s[i]-'0';
        if (b[i]) ++cnt[a[i]];
    }
    if (b[0]) {
        YesNo(0);
        return 0;
    }
    rep(i,7-2)for (int j=i+2; j<7; ++j) {
        if (!(cnt[i]&&cnt[j])) continue;
        for (int k=i+1; k<j; ++k) {
            if (!cnt[k]) {
                YesNo(1);
                return 0;
            }
        }
    }
    YesNo(0);

    return 0;
}
