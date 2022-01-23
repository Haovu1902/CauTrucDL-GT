#include<bits/stdc++.h>
#include"btree.cpp"


using namespace std;

void print(BNode<int>*p){
	cout<<p->getElem() << "\t";	
}	
int tong = 0;
void tinhtong(BNode<int>*p){
	tong = tong + p->getElem();	
}	
int main(){
	BTree<int> b; 
	BNode<int> *p;
	p = b.insert(0,10);
	p = b.insert(b.getRoot(),30);
	b.insert(p,50);
	b.insert(p,40);
	p = b.insert(b.getRoot(),20);
	b.insert(p,60);	
	cout << "So nut cua cay: " <<b.size();
	cout << "\n";
		
	b.preOrder(b.getRoot(),print);
	cout << "\n";
	b.inOrder(b.getRoot(),print);
	cout << "\n";
	b.postOrder(b.getRoot(),print);
	
	b.postOrder(b.getRoot(),tinhtong);
	cout << "\nTong cac nut tren cay= " <<tong;
	b.remove(b.getRoot()->getRight());
	cout << "\n Cay sau khi xoa: ";
	b.preOrder(b.getRoot(),print);
	cout << "\nSo nut cua cay: " <<b.size();
	
} 

