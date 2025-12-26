// https://atcoder.jp/contests/joig2025-open/tasks/joig2025_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vvi a(n,vi(n));
    cin >> a;
    int sm=0;
    vvi cnt(n,vi(n,0));
    rep(i,n-1)rep(j,n-1) {
        set<int> st;
        rep(x,2)rep(y,2) st.insert(a[i+x][j+y]);
        if (st.size()>2) ++sm;
    }
    int add=0;
    // 全ての位置で全ての置き換えを試す
    rep(i,n)rep(j,n) {
        set<int> st;
        for (int x=max(i-1,0); x<min(i+2,n); ++x) {
            for (int y=max(j-1,0); y<min(j+2,n); ++y) st.insert(a[x][y]);
        }
        // 色数が制限されており、周囲と同じ色を塗る必要がある場合
        if (st.size()==k) {
            rep1(c,k) {
                int res=0;
                if (i&&j) {
                    st.clear();
                    st.insert(a[i-1][j-1]);
                    st.insert(a[i-1][j]);
                    st.insert(a[i][j-1]);
                    st.insert(a[i][j]);
                    int p=st.size();
                    st.clear();
                    st.insert(a[i-1][j-1]);
                    st.insert(a[i-1][j]);
                    st.insert(a[i][j-1]);
                    st.insert(c);
                    int q=st.size();
                    if (p==2 && q==3) ++res;
                    if (p==3 && q==2) --res;
                }
                if (i&&j+1<n) {
                    st.clear();
                    st.insert(a[i-1][j]);
                    st.insert(a[i-1][j+1]);
                    st.insert(a[i][j]);
                    st.insert(a[i][j+1]);
                    int p=st.size();
                    st.clear();
                    st.insert(a[i-1][j]);
                    st.insert(a[i-1][j+1]);
                    st.insert(a[i][j+1]);
                    st.insert(c);
                    int q=st.size();
                    if (p==2 && q==3) ++res;
                    if (p==3 && q==2) --res;
                }
                if (i+1<n&&j) {
                    st.clear();
                    st.insert(a[i][j-1]);
                    st.insert(a[i][j]);
                    st.insert(a[i+1][j-1]);
                    st.insert(a[i+1][j]);
                    int p=st.size();
                    st.clear();
                    st.insert(a[i][j-1]);
                    st.insert(a[i+1][j-1]);
                    st.insert(a[i+1][j]);
                    st.insert(c);
                    int q=st.size();
                    if (p==2 && q==3) ++res;
                    if (p==3 && q==2) --res;
                }
                if (i+1<n&&j+1<n) {
                    st.clear();
                    st.insert(a[i][j]);
                    st.insert(a[i][j+1]);
                    st.insert(a[i+1][j]);
                    st.insert(a[i+1][j+1]);
                    int p=st.size();
                    st.clear();
                    st.insert(a[i][j+1]);
                    st.insert(a[i+1][j]);
                    st.insert(a[i+1][j+1]);
                    st.insert(c);
                    int q=st.size();
                    if (p==2 && q==3) ++res;
                    if (p==3 && q==2) --res;
                }
                chmax(add,res);
            }
        } else {
            // 色数に余裕がある場合、周囲に無い色で塗る
            int res=0;
            if (i&&j) {
                st.clear();
                st.insert(a[i-1][j-1]);
                st.insert(a[i-1][j]);
                st.insert(a[i][j-1]);
                st.insert(a[i][j]);
                if (st.size()==2) {
                    st.clear();
                    st.insert(a[i-1][j-1]);
                    st.insert(a[i-1][j]);
                    st.insert(a[i][j-1]);
                    st.insert(0);
                    if (st.size()==3) ++res;
                }
            }
            if (i&&j+1<n) {
                st.clear();
                st.insert(a[i-1][j]);
                st.insert(a[i-1][j+1]);
                st.insert(a[i][j]);
                st.insert(a[i][j+1]);
                if (st.size()==2) {
                    st.clear();
                    st.insert(a[i-1][j]);
                    st.insert(a[i-1][j+1]);
                    st.insert(a[i][j+1]);
                    st.insert(0);
                    if (st.size()==3) ++res;
                }
            }
            if (i+1<n&&j) {
                st.clear();
                st.insert(a[i][j-1]);
                st.insert(a[i][j]);
                st.insert(a[i+1][j-1]);
                st.insert(a[i+1][j]);
                if (st.size()==2) {
                    st.clear();
                    st.insert(a[i][j-1]);
                    st.insert(a[i+1][j-1]);
                    st.insert(a[i+1][j]);
                    st.insert(0);
                    if (st.size()==3) ++res;
                }
            }
            if (i+1<n&&j+1<n) {
                st.clear();
                st.insert(a[i][j]);
                st.insert(a[i][j+1]);
                st.insert(a[i+1][j]);
                st.insert(a[i+1][j+1]);
                if (st.size()==2) {
                    st.clear();
                    st.insert(a[i][j+1]);
                    st.insert(a[i+1][j]);
                    st.insert(a[i+1][j+1]);
                    st.insert(0);
                    if (st.size()==3) ++res;
                }
            }
            chmax(add,res);
        }
    }
    print(sm+add);

    return 0;
}
