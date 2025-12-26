// https://atcoder.jp/contests/joi2024ho/tasks/joi2024ho_a

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,t;
    cin >> n >> t;
    vi a(n);
    cin >> a;
    sort(all(a));
    int mi=*a.begin();
    // 全てのaを(mi-t,mi]に収める
    rep1(i,n-1) {
        int d=a[i]-mi;
        int r=(d-1)/t+1;
        a[i]-=t*r;
    }
    sort(all(a));
    int ans=(*a.rbegin()-*a.begin()+1)/2;
    // 最大最小をズラす
    for (int i=n-1; i>0; --i) {
        a[i]-=t;
        chmin(ans,(a[i-1]-a[i]+1)/2);
    }
    print(ans);

    return 0;
}
