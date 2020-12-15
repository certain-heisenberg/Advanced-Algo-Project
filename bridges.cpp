#include <bits/stdc++.h>
using namespace std;

const int maxN=1e5+5;

vector<int> arr[maxN];
bool vis[maxN];

int in[maxN], low[maxN];
int timer=1;

set<pair<int, int>> st;

void dfs(int v, int p){
	vis[v]=1;
	
	in[v]=low[v]=timer++;
	
	for(int child: arr[v]){
		if(child==p) continue;
		
		if(vis[child]==1) low[v]=min(low[v], in[child]);
		else{
			dfs(child, v);
			if(low[child]>in[v]){
				st.insert({child, v});
			}
			low[v]=min(low[v], low[child]);
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=m; i++){
		int a,b;
		cin>>a>>b;
		arr[a].push_back(b);
	}
	
	for(int i=1; i<=n; i++){
		if(vis[i]==0) dfs(i, -1);
	}
	
	cout<<"Bridges in the given graph are :"<<endl;
	
	for(auto c: st){
		cout<<c.first<<" "<<c.second<<endl;
	}
}
