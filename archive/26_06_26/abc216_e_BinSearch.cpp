// https://atcoder.jp/contests/abc216/tasks/abc216_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    sort(all(a));
    vi sm(n+1,0);
    for (int i=n-1; i>=0; --i) sm[i]=sm[i+1]+a[i];
    int ans=0;
    if (sm[0]<=k) {
        for (int i:a) ans+=i*(i+1)/2;
        print(ans);
        return 0;
    }
    // (l,r]
    int l=0,r=*a.rbegin()+1;
    // mid以上の数のみ採用した時の合計回数がk以下となるかどうか?
    while (l+1<r) {
        int mid=(l+r)/2;
        auto it=lower_bound(all(a),mid);
        int i=it-a.begin();
        int cnt=sm[i]-(mid-1)*(n-i);
        if (cnt<=k) r=mid;
        else l=mid;
    }
    auto itr=lower_bound(all(a),r);
    int idx=itr-a.begin();
    for (int i=idx; i<n; ++i) {
        int d=a[i]-(r-1);
        ans+=d*(d-1)/2;
        ans+=d*r;
    }
    ans+=(r-1)*(k-(sm[idx]-(r-1)*(n-idx)));
    print(ans);

    return 0;
}
