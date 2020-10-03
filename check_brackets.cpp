#include<bits/stdc++.h>
using namespace std;
bool check(char c1, char c2){
	if(c1=='['&&c2==']') return true;
	if(c1=='('&&c2==')') return true;
	if(c1=='{'&&c2=='}') return true;
	else return false;
}
int main(){
	stack<pair <char , int> > b;
	string s;
	pair <char , int> p;
	cin>>s;
	int fault=-1;
	int l=s.length();
	for(int x=0;x<l;x++){
		if(s[x]=='('||s[x]=='['||s[x]=='{'){
			p = make_pair(s[x],x);
			b.push(p);
		}
		
		else if(s[x]==')'||s[x]=='}'||s[x]==']'){
			if(b.size()==0) {
				fault = x;
				break;
			}
			if(check(b.top().first,s[x])) b.pop();
			else {
				fault = x; 
				break;
			}
		}
		
		else continue;
		
	}
	//cout<<fault;
	if(fault == -1){
		if(b.size()==0) cout<<"Success";
		else {
			while(b.size()>1){
				b.pop();
			}
			cout<<(b.top().second)+1;
		}
	}
	else{
		cout<<fault+1;
	}
	
	
	
	
}
