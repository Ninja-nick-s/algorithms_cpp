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
map<int , bool> vis; // visited array for 0 based indexing;
bool dfscall(int start,int prev){
	vis[start] = true;
	//cout<<start<<" ";
	for(auto x:adj[start]){
		if(!vis[x]){
			if(!dfscall(x , start)) return false;
		}
		else if(x!=prev){
			return false;
		}
	}
	return true;
}
void graph(){
	int n,e;cin>>n>>e; //no. of nodes and edges
    rep(i,0,e){
    	int x,y;cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }

    cout<<dfscall(0,-1);
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