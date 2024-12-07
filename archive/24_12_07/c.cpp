// https://atcoder.jp/contests/abc383/tasks/abc383_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;

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
    set<int> sh;
    vvi dist(h,vi(w,-1));
    vvi t(h,vi(w,0));
    queue<pii> q;
    rep(i,h)rep(j,w) {
        if (s[i][j] == 'H') {
            q.push({i,j});
            sh.insert(i*w+j);
            t[i][j] = 1;
            dist[i][j] = 0;
        } else if(s[i][j] == '.') {
            t[i][j] = 1;
        }
    }
    pii p;
    int x,y,nowd;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        x = p.first,y = p.second;
        nowd = dist[x][y];
        if (nowd+1 <= d) {
            if (x-1 >= 0 && t[x-1][y] && dist[x-1][y] == -1) {
                q.push({x-1,y});
                sh.insert((x-1)*w+y);
                dist[x-1][y] = nowd+1;
            }
            if (x+1 < h && t[x+1][y] && dist[x+1][y] == -1) {
                q.push({x+1,y});
                sh.insert((x+1)*w+y);
                dist[x+1][y] = nowd+1;
            }
            if (y-1 >= 0 && t[x][y-1] && dist[x][y-1] == -1) {
                q.push({x,y-1});
                sh.insert(x*w+y-1);
                dist[x][y-1] = nowd+1;
            }
            if (y+1 < w && t[x][y+1] && dist[x][y+1] == -1) {
                q.push({x,y+1});
                sh.insert(x*w+y+1);
                dist[x][y+1] = nowd+1;
            }
        }
    }
    print(sh.size());

    return 0;
}
