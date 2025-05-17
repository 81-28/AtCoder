// default_map

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define f first
#define s second
using pii=pair<int,int>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


// デフォルト値を変えられるmap
// []のデフォルト値以外はmapと変わらない
template<typename K,typename V>
class d_map:public map<K,V>{
public:
    V d_val;
    d_map(const V& default_value):d_val(default_value){}
    V& operator[](const K& key) {
        auto it=this->find(key);
        if (it==this->end()) {
            it=this->emplace(key,d_val).first;
        }
        return it->second;
    }
};
// unordered
template<typename K,typename V>
class unordered_d_map:public unordered_map<K,V>{
public:
    V d_val;
    unordered_d_map(const V& default_value):d_val(default_value){}
    V& operator[](const K& key) {
        auto it=this->find(key);
        if (it==this->end()) {
            it=this->emplace(key,d_val).first;
        }
        return it->second;
    }
};


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,d;
    cin >> n >> m >> d;
    d_map<int,int> dm(d);
    pii p;
    rep(i,n) {
        cin >> p;
        // dm[p.f]=p.s;
        dm[p.f]+=p.s;
    }
    for (auto pp:dm) print(pp);
    rep(i,m) print(dm[i]);
    dm[-1];
    print(dm.at(-1));

    return 0;
}
