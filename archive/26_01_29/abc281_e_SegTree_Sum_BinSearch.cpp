// https://atcoder.jp/contests/abc281/tasks/abc281_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return a+b;}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    vi a(n);
    cin >> a;
    vi b=a;
    sort(all(b));
    uniq(b);
    int len=b.size();
    unordered_map<int,int> mp;
    rep(i,len) mp[b[i]]=i;

    segtree<S,op,e> cnt(len),sm(len);
    rep(i,m-1) {
        int j=mp[a[i]];
        cnt.set(j,cnt.get(j)+1);
        sm.set(j,sm.get(j)+a[i]);
    }
    vi ans;
    rep(i,n-m+1) {
        int idx=i+m-1;
        int j=mp[a[idx]];
        cnt.set(j,cnt.get(j)+1);
        sm.set(j,sm.get(j)+a[idx]);

        // mid=[l,r) : 下から数えた個数の和 sm.prod(0,mid) が、lでk未満,rでk以上となる様に二分探索
        int l=0,r=len;
        while (l+1<r) {
            int mid=(l+r)/2;
            int cntm=cnt.prod(0,mid);
            if (cntm<k) l=mid;
            else r=mid;
        }
        int cntl=cnt.prod(0,l);
        int smn=sm.prod(0,l)+b[l]*(k-cntl);
        ans.pb(smn);

        j=mp[a[i]];
        cnt.set(j,cnt.get(j)-1);
        sm.set(j,sm.get(j)-a[i]);
    }
    print(ans);

    return 0;
}
