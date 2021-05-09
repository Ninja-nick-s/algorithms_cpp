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

int parent[1000000];
int ranker[1000000];

void makeset(int n){
    rep(i,0,n){
        parent[i] = i;
        ranker[i] = 0;
    }
}

int findpar(int node){      // time complexity = O(4*constant) = O(1);
    if(node == parent[node]){
        return node;
    }

    return parent[node] = findpar(parent[node]);
}

void union_(int u , int v){  //time complexity = O(1);
	u = findpar(u);
	v = findpar(v);
    if(ranker[u] > ranker[v]){
        parent[v] = u;
    } 
    else if(ranker[u] < ranker[v]){
        parent[u] = v;
    }
    else{
        parent[v] = u;
        ranker[u]++;
    }
}

void minspanningtree(){   // KRAUSKAL'S ALGORITHM (USING DISJOINT SET DATA STRUCTURE)
	int n,e;cin>>n>>e; //no. of nodes and edges
	makeset(n);
	vector<pair<int , pair<int,int> > > gh;
    rep(i,0,e){
    	int x,y,w;cin>>x>>y>>w;			//	This time we store start and end node and it's weight
    	gh.push_back(make_pair(w,make_pair(x,y)));
    }

    sort(all(gh));

    int sz = gh.size();
    int cost = 0;
    rep(i,0,sz){
    	int wt = gh[i].first;
    	pair<int,int> p = gh[i].second ;
    	int x = p.first;
    	int y = p.second;
    	if(findpar(x) != findpar(y)){
    		cout<<x<<" "<<y<<" "<<wt<<"\n";
    		cost+= wt;
    		union_(x,y);
    	}
    }
    cout<<"Total cost = "<<cost<<"\n";
    
}
void Solve(){
    minspanningtree();
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