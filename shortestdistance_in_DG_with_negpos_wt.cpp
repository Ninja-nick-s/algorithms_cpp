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

struct node{
	int u,v,wt;
};

vector<node> edges;
void negpos_cycle(int n,int e){	//Bellman ford algorithm used to find shortest distance in directed graph with negative weights
	vector<int> dist(n , 1000000);
	int src;cin>>src;	// Enter the source to start from
	dist[src] = 0;
	rep(i,0,n-1){
		rep(j,0,e){
			node edge = edges[j];
			if(dist[edge.u] + edge.wt < dist[edge.v]){
				dist[edge.v] = dist[edge.u] + edge.wt ;
			}
		}
	}
	int fl =1;
	rep(j,0,e){
		node edge = edges[j];
		if(dist[edge.u] + edge.wt < dist[edge.v]){
			cout<<"Negative cycle\n";
			fl = 0;
			break;
		}
	}
	if(fl){
		cout<<"Positive cycle\n";
		rep(i,0,n){
			cout<<dist[i]<<" ";
		}
	}
}
void graph(){
	int n,e;cin>>n>>e;
	rep(i,0,e){
		int x,y,w;cin>>x>>y>>w;
		node edge;
		edge.u = x;
		edge.v = y;
		edge.wt = w;
		edges.push_back(edge);
	}
	negpos_cycle(n,e);
}
/*
test case // source is 0 here
6 7
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2
2 4 3
0
*/
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