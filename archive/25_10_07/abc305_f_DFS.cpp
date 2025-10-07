// https://atcoder.jp/contests/abc305/tasks/abc305_f

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

    int n,m;
    cin >> n >> m;
    // 訪問情報
    v<bool> b(n+1,0);
    // 帰る頂点
    vi r(n+1);
    // 帰る時ショートカットしようとしたが、それだとまだ行っていない分かれ道を飛ばすかもしれない
    int now=1;
    b[1]=1;
    while (1) {
        int k;
        cin >> k;
        if (k==-1) return 0;
        vi a(k);
        cin >> a;
        int nxt=-1;
        rep(i,k) {
            if (!b[a[i]]) {
                nxt=a[i];
                break;
            }
        }
        if (nxt==n) {
            print(nxt);
            string s;
            cin >> s;
            if (s=="OK") return 0;
        }
        if (nxt==-1) nxt=r[now];
        else r[nxt]=now;
        now=nxt;
        b[now]=1;
        print(now);
    }

    return 0;
}
