// https://atcoder.jp/contests/abc425/tasks/abc425_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<endl;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    bool ok=1;
    map<int,int> cnt;
    vi ans(n,-1);
    rep(i,n) {
        if (a[i]!=-1) {
            ++cnt[a[i]];
            if (cnt[a[i]]>1) {
                ok=0;
                break;
            } else {
                ans[i]=a[i];
            }
        }
    }
    if (ok) {
        vi rem;
        rep1(i,n) {
            if (!cnt[i]) rem.pb(i);
        }
        YesNo(1);
        int j=0;
        rep(i,n) {
            if (ans[i]==-1) cout<<rem[j++]<<' ';
            else cout<<ans[i]<<' ';
        }
        print();
    } else YesNo(0);

    return 0;
}
