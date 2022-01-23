#include<bits/stdc++.h>
#include"mystack.cpp"


using namespace std;

int main (){
	mystack<char> s;
	string w= "Ha Noi";
	for (auto x: w)
		s.push(x);
	while (!s.empty()){
		cout << s.top();
		s.pop(); 
	}
}
