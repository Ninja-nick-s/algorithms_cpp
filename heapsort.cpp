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

void heapify(int heap[] , int i){
    int in = ceil((float(i)/2))- 1;
    if(in>=0 && heap[in] < heap[i]){
        swap(heap[in],heap[i]);
        heapify(heap , in);
    } 
}

void makeheap(int a[],int n , int heap[]){
    heap[0] = a[0];
    for(int i =1 ;i<n;i++){
        heap[i] = a[i];
        heapify(heap,i);
    }
}

void del_heapify(int heap[],int n,int i = 0){
    if(2*i+2>n){
        return;
    }
    if(heap[i]<heap[2*i+1]){
        del_heapify(heap,n,2*i +1);
        swap(heap[i],heap[2*i + 1]);
    }
    else if(heap[i]<heap[2*i+2]){
        del_heapify(heap,n,2*i+2);
        swap(heap[i],heap[2*i+2]);
    }
}
void heapsort(int heap[],int n){
    if(n<1)return;
    swap(heap[0],heap[n-1]);
    del_heapify(heap,n-2);
    rep(i,0,n)cout<<heap[i]<<" ";
    cout<<"\n";
    heapsort(heap,n-1);
}
/* CHECK t */
void Solve(){
    int n;cin>>n;
    int a[n];IA(a,n);
    int heap[n];
    makeheap(a,n,heap);
    rep(i,0,n)cout<<heap[i]<<" ";
    cout<<"\n";
    heapsort(heap,n);
    rep(i,0,n)cout<<heap[i]<<" ";
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