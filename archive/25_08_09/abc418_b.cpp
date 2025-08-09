// https://atcoder.jp/contests/abc418/tasks/abc418_b

#include<bits/stdc++.h>
using namespace std;

using ld=long double;
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    ld ans=0;
    for (int i=0; i<n-2; ++i) {
        if (s[i]!='t') continue;
        for (int j=i+2; j<n; ++j) {
            if (s[j]!='t') continue;
            int cnt=0;
            for (int k=i; k<=j; ++k) {
                if (s[k]=='t') ++cnt;
            }
            chmax(ans,((ld)cnt-2)/(j-i+1-2));
        }
    }
    cout<<fixed<<setprecision(16);
    print(ans);

    return 0;
}
