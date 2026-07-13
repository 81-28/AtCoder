// https://atcoder.jp/contests/abc201/tasks/abc201_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int h,w;
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    // 高橋君が得る点
    vvi a(h,vi(w,0));
    rep(i,h)rep(j,w) {
        if (!i&&!j) continue;
        a[i][j]=((s[i][j]=='-')^((i+j)&1))?1:-1;
    }
    // そのマスからゴールまでの、得点差を求める
    for (int i=h-1; i>=0; --i) {
        for (int j=w-1; j>=0; --j) {
            if (i==h-1&&j==w-1) continue;
            set<int> st;
            if (i+1<h) st.insert(a[i+1][j]);
            if (j+1<w) st.insert(a[i][j+1]);
            a[i][j]+=(i+j)&1?*st.begin():*st.rbegin();
        }
    }
    print(!a[0][0]?"Draw":a[0][0]>0?"Takahashi":"Aoki");

    return 0;
}
