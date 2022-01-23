#ifndef __dnode__cpp__
#define __dnode__cpp__
template <class T>
class dnode
{
	private:
		T elem;
		dnode<T> *next;
		dnode<T> *prev;
	public:
		dnode<T> (T x, dnode<T> *n = 0, dnode<T> *p = 0)// 0 - NULL
		{
			elem = x;
			next = n;
			prev = p;
		}
		T & getelem() { return elem; }
		dnode<T> * getnext() { return next; }
		dnode<T> * getprev() { return prev;}
		void setnext(dnode<T> *n){ next = n; }
		void setprev(dnode<T> *p){ prev = p; }
		void setelem(T x){ elem = x; }	
};

#endif
