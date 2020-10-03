#include<bits/stdc++.h>
using namespace std;
vector <int> tree[100000];
int max_depth(int cur){
		int max=0;
	if(tree[cur].size()==0) return 1;
	else {
	
		for(int x=0;x<tree[cur].size();x++){
			if(max<=max_depth(tree[cur][x])+1){
				max=max_depth(tree[cur][x])+1;
			}
		}
	}
	return max;
}

int main(){
	int n;
	cin>>n;
	
	int h;
	int root=-1;
	for(int x=0;x<n;x++){
		cin>>h;
		if(h==-1) {
		root = x;
		continue;
		}
		tree[h].push_back(x);
	}
	
	cout<<max_depth(root);
	
	
}
