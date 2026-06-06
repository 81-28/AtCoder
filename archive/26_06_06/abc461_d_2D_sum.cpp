// https://atcoder.jp/contests/abc461/tasks/abc461_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,k;
    cin >> h >> w >> k;
    v<string> s(h);
    cin >> s;
    vvi sm(h+1,vi(w+1,0));
    rep1(i,h)rep1(j,w) sm[i][j] = (s[i-1][j-1]-'0') + sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1];
    // r[i][x][cnt]:[i,x]の範囲で、合計がcntとなる数
    int ans=0;
    unordered_map<int,int> r;
    vi c;
    rep1(i,h) {
        for (int x=i; x<=h; ++x) {
            c.clear();
            rep1(j,w) {
                int cnt=sm[x][j]-sm[i-1][j];
                ++r[cnt];
                c.pb(cnt);
            }
            rep1(j,w) {
                int cnt=k+sm[x][j-1]-sm[i-1][j-1];
                ans+=r[cnt];
                --r[c[j-1]];
            }
        }
    }
    print(ans);

    return 0;
}
