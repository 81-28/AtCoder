// https://atcoder.jp/contests/abc385/tasks/abc385_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,x,y;
    cin >> h >> w >> x >> y;
    v<string> s(h);
    string t;
    cin >> s >> t;
    x--;
    y--;
    int n = t.size();
    set<int> se;
    rep(i,n) {
        if (t[i] == 'U' && s[x-1][y] != '#') {
            x--;
            if (s[x][y] == '@') se.insert(x*w+y);
        }
        if (t[i] == 'D' && s[x+1][y] != '#') {
            x++;
            if (s[x][y] == '@') se.insert(x*w+y);
        }
        if (t[i] == 'L' && s[x][y-1] != '#') {
            y--;
            if (s[x][y] == '@') se.insert(x*w+y);
        }
        if (t[i] == 'R' && s[x][y+1] != '#') {
            y++;
            if (s[x][y] == '@') se.insert(x*w+y);
        }
    }
    print(x+1,y+1,se.size());

    return 0;
}
