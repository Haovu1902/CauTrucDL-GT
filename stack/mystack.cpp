#ifndef __mystack__cpp__
#define __mystack__cpp__

template <class T>

class mystack{
	private:
		T *s;
		int t;
		int N;
		
	public:
		mystack (){
			N = 1;
			s = new T[N];
			t = -1;
		}
		int size(){
			return t+1;
		}
		int empty(){
			return t==-1;
		}
		T top(){
			return s[t];
		}
		void pop(){
			t--;
		}
		void push(T x)
		{
			if(t==N-1)
			{
				N =2*N;
				T *temp = new T[N]; 
				for(int i=0; i<=t; i++)
					temp[i] = s[i];
				delete []s;
				s = temp;
				
			}
			t++;
			s[t] = x;
			
		} 
};
#endif

