/*************************************Ninja-nick-s*****************************************/

#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define YES {cout<<"YES\n";return;} 
#define NO {cout<<"NO\n";return;} 
#define all(x) x.begin(), x.end()
#define rep(i,start,end) for(auto i=(start)-((start)>(end));i!=(end)-((start)>(end));((start)<(end)?i++:i--))
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);
ll ans = 1;
while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}
return ans;}

void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] <<" "  ;}
void IA(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
string yup="YES";
string nope="NO";

map<int , vector<int> > adj; //adjacency list
map<int , bool> vis; // visited array
int tin = 0;
void dfscall(int start ,int parent , int timer[] , int low[]){
	vis[start] = true;	//this is a function to find articulation point in graph
	timer[start] = low[start] = tin++;
	for(auto x:adj[start]){
		if(x == parent)continue;

		if(!vis[x]){
			dfscall(x,start,timer,low);
			low[start] = min(low[start] , low[x]);
			if(low[x] >= timer[start] && parent!=-1){
				cout<<start<<"\n";
			}
		}
		else{
			low[start] = min(timer[x] , low[start]);
		}
	}
}
/*
	Articulation point is an vertice of graph, which if we remove our graph gets divided into
	different components.

	To find that our low[adj_node] >= timeofinsertion[node] && parent!=-1
*/
void graph(){
	int n,e;cin>>n>>e; //no. of nodes and edges
    rep(i,0,e){
    	int x,y;cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    int timer[n];
    int low[n];
    rep(i,0,n){
    	timer[i] = -1;
    	low[i] = -1;
    }
    rep(i,0,n){
    	if(!vis[i]){
    		dfscall(i,-1,timer,low);
    	}
	}
}
/* CHECK t */
void Solve(){
    graph();
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif

    fast;
    int t = 1;
    //cin >> t;
    //cout<<fixed<<setprecision(9);
    while(t--){
        Solve();cout<<"\n";
    }
    return 0;
}