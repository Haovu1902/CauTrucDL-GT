#ifndef __slist_ite__cpp__
#define __slist_ite__cpp
#include"snode.cpp"
template <class T>

class slist_ite{
	private:
		snode<T> *curr; 
	public:
		slist_ite(snode<T> *c=0){
			curr = c; 
		} 
		snode<T> *getcurr(){
			return curr; 
		} 
		slist_ite<T> &operator =(slist_ite<T> *it){
			this->curr = it->getcurr();
			return *this; 
		} 
		T & operator *(){
			curr->getelem(); 
		} 
		slist_ite<T> operator ++(int){
			curr = curr->getnext();
			return curr; 
		} 
		slist_ite<T> operator ++(){
			slist_ite<T> it = curr;
			curr = curr->getnext();
			return it; 
		} 
		bool operator !=(slist_ite<T> it){
			return curr != it.getcurr(); 
		} 
	
		
}; 










#endif 
