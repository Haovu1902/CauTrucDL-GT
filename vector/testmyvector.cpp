#include<bits/stdc++.h> 
#include"myvector.cpp"

using namespace std;
int main()
{
	Vector<int> V(7,6);
	cout<<"\nVector ban dau:";for(int i=0;i<V.size();i++) cout<<V[i]<<" ";
	for(int i=0;i<V.size();i++) V[i]=i*i;
	cout<<"\nVector binhphuong:";for(int i=0;i<V.size();i++) cout<<V[i]<<" ";
	V.push_back(11);
	V.push_back(13);
	V.insert(2,20);
	cout<<"\nVector :";for(int i=0;i<V.size();i++) cout<<V[i]<<" ";
	cout<<"\nDuyet :";for(Vector<int>::iterator it=V.begin();it!=V.end();it++) cout<<*it<<"\t";	
	cout<<"\nDuyet auto : ";for(auto x:V) cout<<x<<" ";
	cout<<"\nNguoc : "; for(auto it=V.rbegin();it!=V.rend();it++) cout<<*it<<" ";
}
