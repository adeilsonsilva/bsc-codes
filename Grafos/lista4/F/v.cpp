#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) (int)s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl
#define ONLINE_JUDGE 1 

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

int st,ed,days,c,l;
vi adj[105];
bool vis[105][205];

bool BFS()
{
    fr(i,1,c)
        fr(j,0,days)
            vis[i][j] = 0;

    queue<ii> q;
    q.push(mp(st,0));
    vis[st][0] = 1;

    while(!q.empty())
    {
        int u = q.front().ff;
        int d = q.front().ss;
        q.pop();
        if(u == ed && d == days)
            return true;

        rep(i,sz(adj[u]))
        {
            int v = adj[u][i];

            if(d+1 <= days && !vis[v][d+1])
            {
                q.push(mp(v,d+1));
                vis[v][d+1] = true;
            }
        }
    }

    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10681 - Teobaldo's Trip.INP","r",stdin);
    freopen("10681 - Teobaldo's Trip.OUT","w",stdout);
    #endif

    while(read2(c,l) && c)
    {
        fr(i,1,c) adj[i].clear();

        rep(i,l)
        {
            int u,v;
            read2(u,v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

        read3(st,ed,days);

        if(BFS()) puts("Yes, Teobaldo can travel.");
        else puts("No, Teobaldo can not travel.");
    }

    return 0;
}
