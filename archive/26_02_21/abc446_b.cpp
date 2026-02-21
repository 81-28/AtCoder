// https://atcoder.jp/contests/abc446/tasks/abc446_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vb b(m+1,0);
    rep(i,n) {
        int l;
        cin >> l;
        vi x(l);
        cin >> x;
        int res=0;
        rep(j,l) {
            if (b[x[j]]) continue;
            b[x[j]]=1;
            res=x[j];
            break;
        }
        print(res);
    }

    return 0;
}
