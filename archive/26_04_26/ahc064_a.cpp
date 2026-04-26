// https://atcoder.jp/contests/ahc064/tasks/ahc064_a

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using ull=unsigned long long;
using ld=long double;
constexpr int INF=numeric_limits<int>::max()/4;
const ld PI=acos(-1);
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
using vvb=v<vb>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
// const pii dir[8]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
inline int ManhattanDist(const pii& a,const pii& b){return abs(a.first-b.first)+abs(a.second-b.second);}
// using mint=modint998244353;
// using mint=modint1000000007;
// using mint=modint;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する
#define substring(s,l,r) s.substr(l,r-l)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

// `double pow()`では大きい数の時に誤差が発生する オーバーフローに注意 剰余のときは`modint.pow()`で良い
int int_pow(int a,int b) {
    int r=1;
    while(b){if(b&1)r*=a;a*=a;b>>=1;}
    return r;
}
// log(0)=-1
int int_log2(int n) {
    int i=-1;
    for(;n>0;n>>=1)++i;
    return i;
}
// `double log10()`も同様に誤差が発生するので、`to_string(n).size()`が良い

// #define f first
// #define s second
// // pairの足し算
// template<typename F,typename S>
// pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// // pairのデクリメント
// template<typename F,typename S>
// pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}
// // pairと定数の掛け算
// template<typename F,typename S,typename T>
// pair<F,S> operator*(const pair<F,S>& p,const T& a){return{p.f*a,p.s*a};}
// // 定数とpairの掛け算
// template<typename F,typename S,typename T>
// pair<F,S> operator*(const T& a,const pair<F,S>& p){return{a*p.f,a*p.s};}

// AtCoderでは、inもoutもvector,pair,tuple組み合わせて使えない
template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename... Args>
istream &operator>>(istream &is,tuple<Args...> &t){apply([&is](auto&... args){((is>>args),...);},t);return is;}
template<typename... Args>
ostream &operator<<(ostream &os,const tuple<Args...> &t){apply([&os](const auto&... args){int i=0;((os<<(i++?" ":"")<<args),...);},t);return os;}
void print(){cout<<endl;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}
template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}

// 区間のクエリが必要ならセグ木使う
// 値の範囲が大きい→座標圧縮で解けないかを考える

vvi y;
vvi x;
v<tuple<bool,int,int>> a;
void mv(int type,int i,int j,int k) {
    if (type) {
        rep(l,k) {
            int val=x[j].back();
            x[j].pop_back();
            a[val]={0,i,y[i].size()};
            y[i].pb(val);
        }
    } else {
        rep(l,k) {
            int val=y[i].back();
            y[i].pop_back();
            a[val]={1,j,x[j].size()};
            x[j].pb(val);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ofstream output("out.txt");

    int r;
    cin >> r;
    vvi y(r,vi(10));
    cin >> y;
    vvi x(r);
    // {待機側かどうか,路線,何番目か}
    a=v<tuple<bool,int,int>>(10*r);
    rep(i,r)rep(j,10) a[y[i][j]]={0,i,j};

    // We'll implement a straightforward (but not optimal) solver.
    // Strategy:
    // 1) Move all departure lines to waiting lines (type 0 moves).
    // 2) Create one empty waiting line by moving one waiting's content onto another.
    // 3) For each destination line (except one reserved scratch departure),
    //    for each required car id in order, bring that car to the head of its waiting
    //    by moving head elements to the scratch waiting (via a scratch departure),
    //    then move the desired car to the destination departure, and restore the moved
    //    elements back. Each basic move is output as its own turn (K=1).

    int SCR_WAIT = r-1; // index of waiting we will try to make empty initially
    int SCR_DEP = 0;    // index of departure used as scratch departure (must remain empty until last)

    // Represent departures and waitings as deques: head -> front, tail -> back
    vector<deque<int>> dep(r), wait(r);
    for(int i=0;i<r;i++){
        for(int j=0;j<10;j++) dep[i].push_back(y[i][j]);
    }

    // record moves: each element is a tuple(type,i,j,k)
    vector<tuple<int,int,int,int>> moves;

    auto do_move0 = [&](int i,int j,int k){
        // departure i tail -> waiting j head
        // perform as up to k single moves to preserve original order
        int avail = (int)dep[i].size();
        int moved = min(k, avail);
        for(int t=0;t<moved;++t){
            int val = dep[i].back(); dep[i].pop_back();
            wait[j].push_front(val);
        }
        if(moved>0) moves.emplace_back(0,i,j,moved);
    };
    auto do_move1 = [&](int j,int i,int k){
        // waiting j head -> departure i tail
        int avail = (int)wait[j].size();
        int moved = min(k, avail);
        for(int t=0;t<moved;++t){
            int val = wait[j].front(); wait[j].pop_front();
            dep[i].push_back(val);
        }
        if(moved>0) moves.emplace_back(1,i,j,moved);
    };

    // 1) Move all departures to their corresponding waitings (type0). Do in one turn
    // We'll record individually but they are logically a single turn in earlier approach; to keep
    // simplicity and correctness we append them one per turn.
    for(int i=0;i<r;i++){
        do_move0(i,i,10);
    }

    // Now all dep are empty, wait[i] has 10 elements each.
    // 2) Create an empty waiting SCR_WAIT by moving its content to another waiting (choose dst)
    int dst_for_scr = (SCR_WAIT==0?1:0);
    // move waiting SCR_WAIT -> departure SCR_DEP (k=10)
    do_move1(SCR_WAIT,SCR_DEP,10);
    // move departure SCR_DEP -> waiting dst_for_scr (k=10)
    do_move0(SCR_DEP,dst_for_scr,10);
    // now wait[SCR_WAIT] is empty; wait[dst_for_scr] has 20

    // We'll process destination departures in order, but keep SCR_DEP as the last
    vector<int> dests;
    for(int i=0;i<r;i++) if(i!=SCR_DEP) dests.push_back(i);
    dests.push_back(SCR_DEP);

    auto find_in_wait = [&](int id)->pair<int,int>{
        for(int i=0;i<r;i++){
            for(int p=0;p<(int)wait[i].size();++p) if(wait[i][p]==id) return {i,p};
        }
        return {-1,-1};
    };

    // helper to find a waiting that can accept k elements (size+k <=20) and not equal to exclude
    auto find_wait_with_space = [&](int exclude,int k)->int{
        for(int i=0;i<r;i++) if(i!=exclude && (int)wait[i].size()+k<=20) return i;
        return -1;
    };

    // helper to transfer k elements from waiting src head to waiting dst via an empty departure
    auto transfer_wait_to_wait = [&](int src,int dst,int k){
        int remain = k;
        while(remain>0){
            if(wait[src].empty()) break;
            int can_to_wait = 20 - (int)wait[dst].size();
            if(can_to_wait<=0) break;
            // gather all departures with available capacity (exclude src,dst)
            bool any=false;
            for(int d=0; d<r && remain>0 && can_to_wait>0; ++d){
                if(d==src || d==dst) continue;
                int cap = 15 - (int)dep[d].size();
                if(cap<=0) continue;
                int avail_src = (int)wait[src].size();
                int take = min(remain, min(avail_src, min(cap, can_to_wait)));
                if(take<=0) continue;
                do_move1(src,d,take);
                do_move0(d,dst,take);
                remain -= take;
                can_to_wait -= take;
                any = true;
            }
            if(!any){
                // try using SCR_DEP even if it equals src/dst
                int d = SCR_DEP;
                int cap = 15 - (int)dep[d].size();
                int avail_src = (int)wait[src].size();
                int take = min(remain, min(avail_src, min(cap, can_to_wait)));
                if(take>0){
                    do_move1(src,d,take);
                    do_move0(d,dst,take);
                    remain -= take;
                    continue;
                }
                break;
            }
        }
    };

    // For efficiency, process odd-indexed destination lines first (position-wise),
    // then even-indexed lines. This allows simultaneous filling of multiple lines.
    vector<int> odd_dests, even_dests;
    for(int d=0; d<r; ++d){ if(d%2==1) odd_dests.push_back(d); else even_dests.push_back(d); }

    auto process_group = [&](const vector<int>& group){
        for(int pos=0; pos<10; ++pos){
            // build candidates: dest -> (waiting w, idx)
            struct Cand{int dest; int w; int idx; int order;};
            vector<Cand> cand;
            for(int dest : group){
                int want = dest*10 + pos;
                auto pr = find_in_wait(want);
                if(pr.first==-1) continue;
                cand.push_back({dest, pr.first, pr.second, (int)cand.size()});
            }
            if(cand.empty()) continue;
            // compute LIS on w values in order of dest (cand already in group order)
            int n = cand.size();
            vector<int> dp(n,1), prev(n,-1);
            for(int i=0;i<n;++i){
                for(int j=0;j<i;++j){
                    if(cand[j].w < cand[i].w && dp[j]+1>dp[i]){ dp[i]=dp[j]+1; prev[i]=j; }
                }
            }
            // reconstruct LIS
            int best = 0; for(int i=1;i<n;++i) if(dp[i]>dp[best]) best=i;
            vector<int> lis_idx;
            for(int cur=best; cur!=-1; cur=prev[cur]) lis_idx.push_back(cur);
            reverse(lis_idx.begin(), lis_idx.end());
            // prepare subset S as those cand indices in lis_idx
            // attempt to assign resources (temp waiting and dep intermediate) for each in S
            vector<int> S;
            vector<int> assigned_tempW(n, -1), assigned_dep(n, -1);
            // build list of available temp waitings
            for(int id : lis_idx){
                int dest = cand[id].dest;
                int w = cand[id].w;
                int idxv = cand[id].idx;
                // find tempW distinct and with capacity
                int tempW = -1;
                for(int t=0;t<r;++t){
                    if(t==w) continue;
                    if((int)wait[t].size()+idxv<=20){
                        bool used=false;
                        for(int prev_id : S){ if(assigned_tempW[prev_id]==t) { used=true; break; } }
                        if(used) continue;
                        tempW=t; break;
                    }
                }
                if(tempW==-1) continue; // cannot assign tempW, skip
                // find departure intermediate distinct and with capacity
                int dep_i = -1;
                for(int d=0; d<r; ++d){
                    if(d==cand[id].dest) continue; // don't use the destination dep
                    bool used=false;
                    for(int prev_id : S){ if(assigned_dep[prev_id]==d){ used=true; break; } }
                    if(used) continue;
                    if((int)dep[d].size()+idxv<=15){ dep_i=d; break; }
                }
                if(dep_i==-1) continue; // cannot assign dep
                S.push_back(id);
                assigned_tempW[id]=tempW;
                assigned_dep[id]=dep_i;
            }
            if(S.empty()){
                // fallback: process one candidate sequentially
                int id = lis_idx.back();
                int dest = cand[id].dest; int w = cand[id].w; int idxv = cand[id].idx;
                int tempW = -1;
                for(int t=0;t<r;++t) if(t!=w && (int)wait[t].size()+idxv<=20){ tempW=t; break; }
                if(tempW==-1) tempW = (w+1)%r;
                transfer_wait_to_wait(w,tempW,idxv);
                do_move1(w,dest,1);
                transfer_wait_to_wait(tempW,w,idxv);
                continue;
            }
            // perform transfers to tempW using assigned dep intermediates
            // To satisfy non-crossing for these transfers, sort S by assigned_dep and assigned_tempW
            vector<int> order = S;
            sort(order.begin(), order.end(), [&](int a,int b){
                if(assigned_dep[a]!=assigned_dep[b]) return assigned_dep[a]<assigned_dep[b];
                return assigned_tempW[a]<assigned_tempW[b];
            });
            for(int id : order){
                int dest = cand[id].dest;
                int want = dest*10 + pos;
                auto pr_now = find_in_wait(want);
                if(pr_now.first==-1) continue; // already moved
                int src = pr_now.first;
                int idxv = pr_now.second;
                int tempW = assigned_tempW[id];
                if(idxv>0){
                    // transfer necessary head elements from src to tempW
                    transfer_wait_to_wait(src, tempW, idxv);
                }
                // desired car will be moved once in the by_dest loop below
            }
            // move desired cars from their waitings to destination departures (all in parallel logically)
            // ensure ordering by dest increasing to maintain non-crossing
            vector<int> by_dest = S;
            sort(by_dest.begin(), by_dest.end(), [&](int a,int b){ return cand[a].dest < cand[b].dest; });
            for(int id : by_dest){
                int dest = cand[id].dest;
                int want = dest*10 + pos;
                auto pr_now = find_in_wait(want);
                if(pr_now.first==-1) continue;
                int src = pr_now.first;
                // move one if available
                if(!wait[src].empty()) do_move1(src,dest,1);
            }
            // restore from tempW back to original waiting
            for(int id : order){
                int src_temp = assigned_tempW[id];
                int planned = cand[id].idx;
                // only restore up to available
                int avail = (int)wait[src_temp].size();
                int to_restore = min(planned, avail);
                if(to_restore>0) transfer_wait_to_wait(src_temp, cand[id].w, to_restore);
            }
        }
    };

    process_group(odd_dests);
    process_group(even_dests);

    // Output each recorded move as its own turn to guarantee validity.
    int m = (int)moves.size();
    output << m << '\n';
    for(auto &mv : moves){
        int type,i,j,k; tie(type,i,j,k)=mv;
        output << 1 << '\n';
        output << type << ' ' << i << ' ' << j << ' ' << k << '\n';
    }
    output.close();
    cout << "complete" << endl;

    return 0;
}
