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

/* CHECK t */
map<int , vector<pair<int,int> > > adj; //adjacency list
map<int , bool> vis; // visited array for 0 based indexing;

int* dijkstra(int n,int start){
	int* dis = new int[n+1];
	rep(i,0,n+1)dis[i] = INT_MAX;
	priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > pq;
	pq.push(make_pair(0,start));
	dis[start] = 0;
	while(!pq.empty()){
		int d = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for(auto x:adj[node]){
			if(x.second + d < dis[x.first]){
				dis[x.first] = x.second + d;
				pq.push(make_pair(dis[x.first] , x.first));
			} 
		}
	}
	return dis;
}

void graph(){
	int n,e;cin>>n>>e; //no. of nodes and edges
    rep(i,0,e){
    	int x,y,w;cin>>x>>y>>w;			//	This time we store start and end node and it's weight
    	adj[x].push_back(make_pair(y,w));
    	adj[y].push_back(make_pair(x,w));
    }

    int* dis = dijkstra(n,1);

    rep(i,1,n+1){
    	cout<<dis[i]<<" ";
    }
}
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