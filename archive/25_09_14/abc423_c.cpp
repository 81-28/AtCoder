// https://atcoder.jp/contests/abc423/tasks/abc423_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,r;
    cin >> n >> r;
    vi l(n);
    cin >> l;
    int ans=0;
    int add=0;
    for (int i=r-1; i>=0; --i) {
        if (l[i]) ++add;
        else {
            ans+=(1+add*2);
            add=0;
        }
    }
    add=0;
    for (int i=r; i<n; ++i) {
        if (l[i]) ++add;
        else {
            ans+=(1+add*2);
            add=0;
        }
    }
    print(ans);

    return 0;
}
