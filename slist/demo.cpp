#include<bits/stdc++.h>
#include"dlist.cpp"
using namespace std;
class Sinhvien
{
	private:
		string hoten;
	public:
		void Nhap()
		{
			cout<<"Nhap ho ten:";
			cin.ignore();
			getline(std::cin, hoten);
		}	
};
int main()
{
//	dlist<Sinhvien> dl;
//	Sinhvien x;
//	x.Nhap();
//	dl.push_front(x);
	
	dlist<int> dl;
	
	dl.push_front(1000);
	dl.push_back(500);
	
	dlist<int>::iterator it1 = dl.begin();
	it1++;
	dl.insert(it1,300);
//	dlist<int>::iterator it2 = dl.begin();
//	it2++;
//	dl.erase(it2);
	for(dlist<int>::iterator it = dl.begin(); it !=dl.end(); ++it)
		cout<<*it<<"\t";
	cout<<"\n";
	for(dlist<int>::reverse_iterator it = dl.rbegin(); it !=dl.rend(); ++it)
		cout<<*it<<"\t";
	
}
