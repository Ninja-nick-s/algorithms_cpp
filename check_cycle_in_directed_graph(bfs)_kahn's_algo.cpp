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
map<int , vector<int> > adj; //adjacency list
map<int , bool> vis; // visited array;
bool topo_cyclic(int n){			//to check if directed graph is acyclic it's toposort should exist
	vector<int> indeg(n);			//using that concept we are going to check if cyclic directed 
	for(auto x:adj){				// graph or acyclic;
		for(auto y:adj[x.first]){
			indeg[y]++;
		}
	}
	queue<int> q;
	for(int i=0;i<n;i++){		//1. In kahn's algorithm we first assign n degree to nodes
		if(indeg[i]==0){		//2. Then we push nodes with indegree 0 in queue
			q.push(i);			//3. Then we call bfs and reduce the indegree for each visited node.
		}						//4. Then again we check if indegree is zero then push in stack;
	}							//5. As the bfs call is over we pop the node from queue
	int cnt = 0;
	while(!q.empty()){
		int k = q.front();
		q.pop();
		cnt++;
		for(auto x:adj[k]){
			indeg[x]--;
			if(indeg[x] == 0){
				q.push(x);
			}
		}
	}
	if(cnt==n) return false; //it means it is acyclic graph
	return true;     // it means it is cyclic directed graph
}
void graph(){
	int n,e;cin>>n>>e; //no. of nodes and edges
    rep(i,0,e){
    	int x,y;cin>>x>>y;
    	adj[x].push_back(y);
    	//adj[y].push_back(x);
    }
    cout<<topo_cyclic(n);
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