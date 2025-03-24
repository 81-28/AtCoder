// https://atcoder.jp/contests/abc314/tasks/abc314_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    // 0:未,1:小,2:大
    vi si(n,0);
    // 文字が確定したかどうか
    v<bool> d(n,0);
    string ans=s;
    int q;
    cin >> q;
    vi t(q),x(q);
    v<char> c(q);
    rep(i,q) cin >> t[i] >> x[i] >> c[i];

    bool ds=0;
    for (int i=q-1; i>=0; i--) {
        if (t[i]==1 && !d[x[i]-1]) {
            ans[x[i]-1]=c[i];
            if (si[x[i]-1]==0) si[x[i]-1]=1+isupper(c[i]);
            d[x[i]-1]=1;
        }
        if (t[i]==2 && !ds) {
            rep(j,n) {
                if (si[j]==0) si[j]=1;
            }
            ds=1;
        }
        if (t[i]==3 && !ds) {
            rep(j,n) {
                if (si[j]==0) si[j]=2;
            }
            ds=1;
        }
    }
    rep(i,n) {
        if (si[i]==1) ans[i]=tolower(ans[i]);
        if (si[i]==2) ans[i]=toupper(ans[i]);
    }
    print(ans);

    return 0;
}
