// https://atcoder.jp/contests/tessoku-book/tasks/abc007_3

#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
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

    int r,c;
    pii st,go;
    cin >> r >> c >> st.f >> st.s >> go.f >> go.s;
    st.f--,st.s--,go.f--,go.s--;
    v<string> m(r);
    cin >> m;
    vvi d(r,vi(c,-1));
    queue<pii> q;
    q.push(st);
    d[st.f][st.s] = 0;
    while (!q.empty()) {
        pii pos=q.front();
        q.pop();
        if (m[pos.f-1][pos.s] == '.' && d[pos.f-1][pos.s] == -1) {
            d[pos.f-1][pos.s] = d[pos.f][pos.s]+1;
            q.push({pos.f-1,pos.s});
        }
        if (m[pos.f+1][pos.s] == '.' && d[pos.f+1][pos.s] == -1) {
            d[pos.f+1][pos.s] = d[pos.f][pos.s]+1;
            q.push({pos.f+1,pos.s});
        }
        if (m[pos.f][pos.s-1] == '.' && d[pos.f][pos.s-1] == -1) {
            d[pos.f][pos.s-1] = d[pos.f][pos.s]+1;
            q.push({pos.f,pos.s-1});
        }
        if (m[pos.f][pos.s+1] == '.' && d[pos.f][pos.s+1] == -1) {
            d[pos.f][pos.s+1] = d[pos.f][pos.s]+1;
            q.push({pos.f,pos.s+1});
        }
        if (d[go.f][go.s] != -1) {
            print(d[go.f][go.s]);
            return 0;
        }
    }

    return 0;
}
