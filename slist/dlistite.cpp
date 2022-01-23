#ifndef __dlist_ite__cpp__
#define __dlist_ite__cpp__
#include"dnode.cpp"
template <class T>
class dlist_ite
{
	private:
		dnode<T> *curr;
	public:
		dlist_ite<T>(dnode<T> *c=0)
		{
			curr = c;
		}
		dnode<T> *getcurr() { return curr; }
		dlist_ite<T> & operator =(dlist_ite *it)
		{
			this->curr = it->getcurr();
			return *this;
		}
		T &operator *() { return curr->getelem();}
		dlist_ite<T> operator ++(int)
		{
			curr = curr->getnext();
			return curr;
		}
		dlist_ite<T> operator ++()
		{
			dlist_ite<T> temp = curr;
			curr = curr->getnext();
			return temp;			
		}	
		bool operator !=(dlist_ite it)
		{
			return curr!= it.getcurr(); 
		}
	
};

template <class T>
class dlist_reite
{
	private:
		dnode<T> *curr;
	public:
		dlist_reite<T>(dnode<T> *c) { curr = c; }
		dnode<T> * getcurr() { return curr; }
		dlist_reite<T> & operator =(dlist_reite<T> *it)
		{
			this->curr = it->getcurr();
			return *this;
		}
		T &operator *() { return curr->getelem() ;}
		dlist_reite<T> operator ++(int)
		{
			curr = curr->getprev();
			return curr;
		}
		dlist_reite<T> operator ++()
		{
			dlist_reite<T> temp = curr;
			curr = curr->getprev();
			return temp;
		}
		bool operator !=(dlist_reite<T> it) 
		{
			return curr!=it.getcurr();
		}
	
};




#endif
