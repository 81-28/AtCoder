// https://atcoder.jp/contests/abc414/tasks/abc414_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int a;
bool isPal(int n) {
    vi vec;
    while (n>0) {
        vec.pb(n%a);
        n/=a;
    }
    int l=0,r=vec.size()-1;
    while (l<r) {
        if (vec[l]!=vec[r]) return 0;
        ++l,--r;
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> a >> n;
    vi p(13);
    p[0]=1;
    rep1(i,12) p[i]=p[i-1]*10;

    int ans=0;
    // i:桁数
    rep1(i,12) {
        int d=(i+1)/2;
        int e=i-d;
        int mx=p[d];
        for (int j=p[d-1]; j<mx; ++j) {
            int m=j;
            int sm=m*p[e];
            if (i%2) m/=10;
            for (int k=e-1; k>=0; --k) {
                sm+=m%10*p[k];
                m/=10;
            }
            if (sm>n) {
                print(ans);
                return 0;
            }
            if (isPal(sm)) ans+=sm;
        }
    }
    print(ans);

    return 0;
}
