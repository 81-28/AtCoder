// https://atcoder.jp/contests/abc320/tasks/abc320_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m;
    v<string> s(3);
    cin >> m >> s;
    rep(i,3) s[i] = s[i]+s[i]+s[i];
    vvi p(6);
    p[0]={0,1,2},p[1]={0,2,1},p[2]={1,0,2},p[3]={1,2,0},p[4]={2,0,1},p[5]={2,1,0};
    int idx;
    vvi t(10,vi(6,INT_MAX));
    rep(i,10)rep(j,6) {
        idx=0;
        rep(k,m*3) {
            if (s[p[j][idx]][k]-'0' == i) idx++;
            if (idx==3) {
                t[i][j]=k;
                break;
            }
        }
    }

    int ans=INT_MAX;
    rep(i,10)rep(j,6) ans = min(ans,t[i][j]);
    print(ans==INT_MAX ? -1:ans);

    return 0;
}
