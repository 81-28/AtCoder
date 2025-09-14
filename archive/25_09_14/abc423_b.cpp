// https://atcoder.jp/contests/abc423/tasks/abc423_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi l(n);
    cin >> l;
    int b=-1,e=-1;
    rep(i,n) {
        if (l[i]) {
            if (b==-1) b=i;
            e=i;
        }
    }
    print(e-b);

    return 0;
}
