// https://atcoder.jp/contests/abc383/tasks/abc383_b

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

    int h,w,d;
    cin >> h >> w >> d;
    v<string> s(h);
    cin >> s;
    vvi t(h,vi(w,0));
    rep(i,h)rep(j,w) {
        if(s[i][j]=='.')t[i][j]=1;
    }
    int ans = 0;
    int u,v,x,y;
    set<int> sh;
    for (int a=0; a<h*w-1; a++)for(int b=a+1; b<h*w; b++) {
        sh = set<int>();
        u = a/w;
        v = a%w;
        x = b/w;
        y = b%w;
        if (t[u][v] && t[x][y]) {
            rep(i,h)rep(j,w) {
                if (t[i][j]) {
                    if (abs(i-u)+abs(j-v) <= d || abs(i-x)+abs(j-y) <= d) sh.insert(i*w+j);
                }
            }
            ans = max(ans,(int)sh.size());
        }
    }
    print(ans);

    return 0;
}
