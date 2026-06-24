// https://atcoder.jp/contests/abc215/tasks/abc215_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,m;
    cin >> n >> m;
    unordered_map<int,bool> mp;
    rep1(k,n) {
        int a;
        cin >> a;
        while (!(a&1)) {
            mp[2]=1;
            a>>=1;
        }
        while (a%3==0) {
            mp[3]=1;
            a/=3;
        }
        for (int i=5; i*i<=a; i+=6) {
            while (a%i==0) {
                mp[i]=1;
                a/=i;
            }
            int j=i+2;
            while (a%j==0) {
                mp[j]=1;
                a/=j;
            }
        }
        if (a>1) mp[a]=1;
    }
    vi ans;
    rep1(k,m) {
        bool ok=1;
        int a=k;
        while (!(a&1)) {
            if (mp[2]) {
                ok=0;
                break;
            }
            a>>=1;
        }
        if (!ok) continue;
        while (a%3==0) {
            if (mp[3]) {
                ok=0;
                break;
            }
            a/=3;
        }
        if (!ok) continue;
        for (int i=5; i*i<=a; i+=6) {
            while (a%i==0) {
                if (mp[i]) {
                    ok=0;
                    break;
                }
                a/=i;
            }
            if (!ok) break;
            int j=i+2;
            while (a%j==0) {
                if (mp[j]) {
                    ok=0;
                    break;
                }
                a/=j;
            }
        }
        if (!ok) continue;
        if (a>1 && mp[a]) continue;
        ans.pb(k);
    }
    print(ans.size());
    for (int i:ans) print(i);

    return 0;
}
