// https://atcoder.jp/contests/abc358/tasks/abc358_c

// Ctrl + Shift + B       => Build
// Terminal << "./a.out"  => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;


int n,m;


int main() {
    cin >> n >> m;
    vector<set<int>> b;
    set<int> ok;
    for (int i = 0; i < m; i++)
    {
        ok.insert(i);
    }
    
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        set<int> nowSet;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'o')
            {
                nowSet.insert(j);
            }
        }
        b.push_back(nowSet);
    }

    
    for (int i = 0; i < n; i++)
    {
        if (b[i] == ok)
        {
            cout << 1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                set<int> merge = b[i];
                merge.insert(b[j].begin(),b[j].end());
                if (merge == ok)
                {
                    cout << 2 << endl;
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j && j != k && k != i)
                {
                    set<int> merge = b[i];
                    merge.insert(b[j].begin(),b[j].end());
                    merge.insert(b[k].begin(),b[k].end());
                    if (merge == ok)
                    {
                        cout << 3 << endl;
                        return 0;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (i != j && j != k && k != l && l != i)
                    {
                        set<int> merge = b[i];
                        merge.insert(b[j].begin(),b[j].end());
                        merge.insert(b[k].begin(),b[k].end());
                        merge.insert(b[l].begin(),b[l].end());
                        if (merge == ok)
                        {
                            cout << 4 << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    for (int o = 0; o < n; o++)
                    {
                        if (i != j && j != k && k != l && l != i && o != i && o != j && o != k && o != l)
                        {
                            set<int> merge = b[i];
                            merge.insert(b[j].begin(),b[j].end());
                            merge.insert(b[k].begin(),b[k].end());
                            merge.insert(b[l].begin(),b[l].end());
                            merge.insert(b[o].begin(),b[o].end());
                            if (merge == ok)
                            {
                                cout << 5 << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    for (int o = 0; o < n; o++)
                    {
                        for (int p = 0; p < n; p++)
                        {
                            if (i != j && j != k && k != l && l != i && o != i && o != j && o != k && o != l && p != i && p != j && p != k && p != l && p != o)
                            {
                                set<int> merge = b[i];
                                merge.insert(b[j].begin(),b[j].end());
                                merge.insert(b[k].begin(),b[k].end());
                                merge.insert(b[l].begin(),b[l].end());
                                merge.insert(b[o].begin(),b[o].end());
                                merge.insert(b[p].begin(),b[p].end());
                                if (merge == ok)
                                {
                                    cout << 6 << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    for (int o = 0; o < n; o++)
                    {
                        for (int p = 0; p < n; p++)
                        {
                            for (int q = 0; q < n; q++)
                            {
                                if (i != j && j != k && k != l && l != i && o != i && o != j && o != k && o != l && p != i && p != j && p != k && p != l && p != o && q != i && q != j && q != k && q != l && q != o && q != p)
                                {
                                    set<int> merge = b[i];
                                    merge.insert(b[j].begin(),b[j].end());
                                    merge.insert(b[k].begin(),b[k].end());
                                    merge.insert(b[l].begin(),b[l].end());
                                    merge.insert(b[o].begin(),b[o].end());
                                    merge.insert(b[p].begin(),b[p].end());
                                    merge.insert(b[q].begin(),b[q].end());
                                    if (merge == ok)
                                    {
                                        cout << 7 << endl;
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    for (int o = 0; o < n; o++)
                    {
                        for (int p = 0; p < n; p++)
                        {
                            for (int q = 0; q < n; q++)
                            {
                                for (int r = 0; r < n; r++)
                                {
                                    if (i != j && j != k && k != l && l != i && o != i && o != j && o != k && o != l && p != i && p != j && p != k && p != l && p != o && q != i && q != j && q != k && q != l && q != o && q != p && r != i && r != j && r != k && r != l && r != o && r != p && r != q)
                                    {
                                        set<int> merge = b[i];
                                        merge.insert(b[j].begin(),b[j].end());
                                        merge.insert(b[k].begin(),b[k].end());
                                        merge.insert(b[l].begin(),b[l].end());
                                        merge.insert(b[o].begin(),b[o].end());
                                        merge.insert(b[p].begin(),b[p].end());
                                        merge.insert(b[q].begin(),b[q].end());
                                        merge.insert(b[r].begin(),b[r].end());
                                        if (merge == ok)
                                        {
                                            cout << 8 << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    for (int o = 0; o < n; o++)
                    {
                        for (int p = 0; p < n; p++)
                        {
                            for (int q = 0; q < n; q++)
                            {
                                for (int r = 0; r < n; r++)
                                {
                                    for (int s = 0; s < n; s++)
                                    {
                                        if (i != j && j != k && k != l && l != i && o != i && o != j && o != k && o != l && p != i && p != j && p != k && p != l && p != o && q != i && q != j && q != k && q != l && q != o && q != p && r != i && r != j && r != k && r != l && r != o && r != p && r != q && s != i && s != j && s != k && s != l && s != o && s != p && s != q && s != r)
                                        {
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        set<int> merge;
        for (int j = 0; j < n; j++)
        {
            if (i!=j)
            {
            merge.insert(b[j].begin(),b[j].end());
            }
            
        }
        if (merge == ok)
        {
            cout << 9 << endl;
            return 0;
        }
        
    }
    

    cout << 10 << endl;
    
    

    return 0;
}
