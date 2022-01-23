#include"bits/stdc++.h"
#include"slist.cpp"

using namespace std;
 
int main(){
	slist<float> sl(5, 100);
	
	sl.push_front(500); 
	//cout << sl.front();
	//sl.pop_front();
	sl.push_back(2000);
	cout << "\nPhan tu cuoi cung : " << sl.back(); 
	//cout << "\n" << sl.front(); 
	cout << "\nDanh sach cac phan tu cua list :";
	for(slist<float>::iterator it = sl.begin(); it!=sl.end(); it++)
		cout << *it << "\t"; 
	 
	 
} 
