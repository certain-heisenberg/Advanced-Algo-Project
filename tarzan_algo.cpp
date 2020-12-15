#include <bits/stdc++.h>
using namespace std;

const int maxN=1e5+5;

vector<int> arr[maxN];
bool vis[maxN];

int in[maxN], low[maxN];

bool onStack[maxN];
stack<int> st;
int timer=1;

int cnt;
vector<vector<int>> scc;

void dfs(int v){
	vis[v]=1;
	
	in[v]=low[v]=timer++;
	onStack[v]=1;
	st.push(v);
	
	for(int child: arr[v]){
		if(vis[child]==1 && onStack[child]){
			low[v]=min(low[v], in[child]);
		}
		else if(vis[child]==0){
			dfs(child);
			if(onStack[child]) low[v]=min(low[v], low[child]);
		}
	}
	
	if(in[v]==low[v]){
		vector<int> temp;
		cnt++;
		while(1){
			int u=st.top();
			st.pop();
			onStack[u]=0;
			temp.push_back(u);
			
			if(u==v) break;
		}
	
		scc.push_back(temp);
	}
}

#define kk

int main(){
	#ifdef kk
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
	
	int n, m;
	cin>>n>>m;
	
	for(int i=1; i<=m; i++){
		int a, b;
		cin>>a>>b;
		arr[a].push_back(b);
	}
	
	for(int i=1; i<=n; i++){
		if(vis[i]==0){
			dfs(i);
		}
	}
	
	cout<<"Total # of SCC in the given graph is "<<cnt<<endl<<endl;
	
	cout<<"Different SCC are:"<<endl;
	
	for(auto c: scc){
		for(auto d: c) cout<<d<<" ";
		cout<<endl;
	}
}

/*
8 12
1 2
2 3
3 1
2 8
3 4
8 4
4 8
7 8
5 4
5 7
7 6
6 5
*/
