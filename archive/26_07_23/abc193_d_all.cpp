// https://atcoder.jp/contests/abc193/tasks/abc193_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

int int_pow(int a,int b) {
    int r=1;
    while(b){if(b&1)r*=a;a*=a;b>>=1;}
    return r;
}

#define endl '\n' // flushしたい場合は無効化
void print(){cout<<endl;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int k;
    string s,t;
    cin >> k >> s >> t;
    vi cnt(10,k),cnta(10,0),cntb(10,0);
    rep(i,4) {
        --cnt[s[i]-'0'];
        ++cnta[s[i]-'0'];
        --cnt[t[i]-'0'];
        ++cntb[t[i]-'0'];
    }
    int ans=0,sm=0;
    rep1(i,9) {
        if (cnt[i]<1) continue;
        int add=cnt[i]--;
        ++cnta[i];
        rep1(j,9) {
            if (cnt[j]<1) continue;
            add*=cnt[j]--;
            ++cntb[j];
            int a=0,b=0;
            rep1(k,9) {
                a+=k*int_pow(10,cnta[k]);
                b+=k*int_pow(10,cntb[k]);
            }
            sm+=add;
            if (a>b) ans+=add;
            --cntb[j];
            ++cnt[j];
        }
        --cnta[i];
        ++cnt[i];
    }
    print((ld)ans/sm);

    return 0;
}
