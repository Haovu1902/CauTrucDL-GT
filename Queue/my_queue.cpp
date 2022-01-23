#include<bits/stdc++.h>

using namespace std;

template <class T>
 
class Queue
{
	int num,cap,F,L; 
	T *elem;
	public:
		Queue() 
		{
			num=F=L=cap=0; 
			elem=NULL;
		}
		~Queue() 
		{
		if(elem) 
			delete[]elem;
		}
		int size()
		{
		return num;
		}
		bool empty() 
		{
		return num==0;
		} 
		T &front() 
		{
		return elem[F];
		}
		T &back() 
		{
		return  L==0?elem[cap-1]:elem[L-1];
		}
		void pop()
		{
		F=(F+1)%cap; num--;
		} 
		void push(T x)
		{
			if(num==cap)
			{
				cap=cap?cap*2:1;   
				T *tem=new T[cap];
				for(int i=0,j=F;j<F+num;j++,i++) 
					tem[i]=elem[j%num];
				if(elem) 
					delete[]elem;
					elem=tem;
					F=0;L=num;
			}
			elem[L]=x ; 	
			L=(L+1)%cap;
			num++;
		}
};
int main()
{
	Queue<int> Q;
	for(auto x:{3,2,7,9,4,8,5,1,6})
		Q.push(x);
	while(Q.size())
	{
		cout<<Q.front()<<" ";	
		Q.pop();
	}
}




