// https://atcoder.jp/contests/abc465/tasks/abc465_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using A=array<int,6>;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    // 6次元累積和
    vector sm(11,vector(11,vector(11,vector(11,vvi(11,vi(11,0))))));
    while (n--) {
        string s;
        int vl;
        cin >> s >> vl;
        A ar;
        // 0を開けるために +1
        rep(i,6) ar[i]=s[i]-'0' +1;
        sm[ar[0]][ar[1]][ar[2]][ar[3]][ar[4]][ar[5]]+=vl;
    }
    rep1(a,10)rep1(b,10)rep1(c,10)rep1(d,10)rep1(e,10)rep1(f,10) {
        sm[a][b][c][d][e][f]+=sm[a][b][c][d][e][f-1];
    }
    rep1(a,10)rep1(b,10)rep1(c,10)rep1(d,10)rep1(e,10)rep1(f,10) {
        sm[a][b][c][d][e][f]+=sm[a][b][c][d][e-1][f];
    }
    rep1(a,10)rep1(b,10)rep1(c,10)rep1(d,10)rep1(e,10)rep1(f,10) {
        sm[a][b][c][d][e][f]+=sm[a][b][c][d-1][e][f];
    }
    rep1(a,10)rep1(b,10)rep1(c,10)rep1(d,10)rep1(e,10)rep1(f,10) {
        sm[a][b][c][d][e][f]+=sm[a][b][c-1][d][e][f];
    }
    rep1(a,10)rep1(b,10)rep1(c,10)rep1(d,10)rep1(e,10)rep1(f,10) {
        sm[a][b][c][d][e][f]+=sm[a][b-1][c][d][e][f];
    }
    rep1(a,10)rep1(b,10)rep1(c,10)rep1(d,10)rep1(e,10)rep1(f,10) {
        sm[a][b][c][d][e][f]+=sm[a-1][b][c][d][e][f];
    }
    int q;
    cin >> q;
    while (q--) {
        string x,y;
        cin >> x >> y;
        A l,r;
        bool ok=1;
        rep(i,6) {
            l[i]=x[i]-'0';
            r[i]=y[i]-'0' +1;
            if (l[i]>=r[i]) {
                ok=0;
                break;
            }
        }
        if (!ok) {
            print(0);
            continue;
        }
        int ans=0;
        int mx=1<<6;
        rep(i,mx) {
            A idx;
            rep(j,6) idx[j] = (i>>j)&1 ? l[j]:r[j];
            int val = sm[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]][idx[5]];
            int b = __builtin_popcountll(i);
            ans += (b&1)? -val:val;
        }
        print(ans);
    }

    return 0;
}
