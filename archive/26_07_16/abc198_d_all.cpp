// https://atcoder.jp/contests/abc198/tasks/abc198_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

int int_pow(int a,int b) {
    int r=1;
    while(b){if(b&1)r*=a;a*=a;b>>=1;}
    return r;
}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    v<string> s(3);
    cin >> s;
    vi siz(3);
    map<char,bool> m;
    rep(i,3) {
        siz[i]=s[i].size();
        rep(j,siz[i]) m[s[i][j]]=1;
    }
    map<char,int> mp;
    int l=0;
    for (auto[c,b]:m) mp[c]=l++;
    if (l>10) {
        print("UNSOLVABLE");
        return 0;
    }
    vi a(10);
    rep(i,10) a[i]=i;
    do {
        vi n(3,0);
        bool ok=1;
        rep(i,3) {
            if (a[mp[s[i][0]]]==0) {
                ok=0;
                break;
            }
            n[i]+=a[mp[s[i][0]]]*int_pow(10,siz[i]-1);
        }
        if (!ok) continue;
        rep(i,3) {
            for (int j=1; j<siz[i]; ++j) {
                n[i]+=a[mp[s[i][j]]]*int_pow(10,siz[i]-1-j);
            }
        }
        if (n[0]+n[1]==n[2]) {
            rep(i,3) print(n[i]);
            return 0;
        }
    } while (next_permutation(all(a)));
    print("UNSOLVABLE");

    return 0;
}
