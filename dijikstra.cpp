
#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
 #define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define all(x) x.begin(),x.end()
const int INF = 1000000000000000;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


vector<pair<int,int>> wg[100050];


vi d(100050,INF);
vi dijkstra(int src)
{
    set<pair<int,int>> s;

    // vi parent(n+1,-1);
    
    d[src]=0;
    s.insert({0,src});
    while(!s.empty()){
        int i=s.begin()->second;
        s.erase(s.begin());
        for (auto & e:wg[i]){
            int nb=e.first;
            int w=e.second;
            if (d[i]+w<d[nb]){
                s.erase({d[nb],nb});
                d[nb]=d[i]+w;
                s.insert({d[nb],nb});
                // parent[nb]=i;
            }
        }
    }
   // return parent;
    return d;

}

int32_t main(){
 fastIO;

 wg[0].pb({1,8});
 wg[1].pb({0,8});
 wg[0].pb({5,3});
 wg[5].pb({0,3});
 wg[0].pb({4,15});
 wg[4].pb({0,15});
 wg[1].pb({3,1});
 wg[3].pb({1,1});
 wg[1].pb({2,5});
 wg[2].pb({1,5});
 wg[4].pb({8,1});
 wg[8].pb({4,1});
 wg[3].pb({2,4});
 wg[2].pb({3,4});
 dijkstra(0);

 cout<<d[3];

 

return 0;
}