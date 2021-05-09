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

int* primbrute(int n){		// This is prim algorithm to find minimum spanning tree (optimized)using pq
	int* key = new int[n];	// it has 0 based indexing
	int* parent = new int[n];
	bool* sel = new bool[n];
	rep(i,0,n){
		key[i] = INT_MAX;
		parent[i] = -1;
		sel[i] = false;
	}
	priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > pq;
	key[0] = 0;
	pq.push({0,0});
	for(int ctr = 0;ctr<n-1;ctr++){ // time complexity = O(N + E + NlOG(N))

		// int mini = INT_MAX , min_in ;
		// rep(i,0,n){
		// 	if(sel[i] == false && (key[i]< mini)){
		// 		mini = key[i];
		// 		min_in = i;
		// 	}
		// }
		int min_in = pq.top().second;
		pq.pop();
		sel[min_in] = true;
		for(auto x:adj[min_in]){
			int v = x.first;
			int weight = x.second; 
			if(sel[v] == false && weight<key[v]){
				parent[v] = min_in;
				pq.push({key[v] , v});
				key[v] = weight;
			}
		}
	}

	return parent;
}

void graph(){
	int n,e;cin>>n>>e; //no. of nodes and edges
    rep(i,0,e){
    	int x,y,w;cin>>x>>y>>w;			//	This time we store start and end node and it's weight
    	adj[x].push_back(make_pair(y,w));
    	adj[y].push_back(make_pair(x,w));
    }

    int* mst = primbrute(n);

    for(int i =1;i<n;i++){
    	cout<<mst[i]<<" "<<i<<"\n";
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
        Solve();
    }
    return 0;
}