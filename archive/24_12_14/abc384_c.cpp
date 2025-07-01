// https://atcoder.jp/contests/abc384/tasks/abc384_c

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

bool compare(const pair<int, string>& a, const pair<int, string>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    int score;
    string name;
    v<pair<int,string>> ans;
    rep1(i,31) {
        score = 0;
        name = "";
        if (i%2) {
            score += a;
            name += 'A';
        }
        if ((i>>1)%2) {
            score += b;
            name += 'B';
        }
        if ((i>>2)%2) {
            score += c;
            name += 'C';
        }
        if ((i>>3)%2) {
            score += d;
            name += 'D';
        }
        if ((i>>4)%2) {
            score += e;
            name += 'E';
        }
        ans.pb({score,name});
    }
    sort(all(ans),compare);
    for(auto p:ans) {
        print(p.second);
    }

    return 0;
}
