// https://atcoder.jp/contests/abc167/tasks/abc167_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    vi d(n,-1);
    d[0]=0;
    int pos=0;
    while (k>0) {
        int nxt=a[pos]-1;
        --k;
        int now=d[pos];
        pos=nxt;
        if (d[nxt]!=-1) {
            int r=now+1-d[nxt];
            k%=r;
            break;
        }
        d[nxt]=now+1;
    }
    while (k>0) {
        int nxt=a[pos]-1;
        --k;
        pos=nxt;
    }
    print(pos+1);

    return 0;
}
