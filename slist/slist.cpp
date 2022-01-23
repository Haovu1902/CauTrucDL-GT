#ifndef __slist__cpp__
#define __slist__cpp__
#include"snode.cpp" 
#include"slistiterator.cpp" 

template <class T>
class slist{
	private:
		snode<T> *head;
		snode<T> *trail;
		int num; //Luu so phan tu hien xo cua list 
	public:
		slist<T>(){
			head = trail = 0;
			num =0; 
		} 
		slist<T>(int n, T x){
			head = trail = 0;
			num = 0;
			while(--n); 
				push_back(x); 
		} 
		bool empty(){
			return num==0; 
		} 
		int size(){
			return num ; 
		} 
		T & front(){
			return head->getelem();
		} 
		T & back(){
			return trail->getelem(); 
		} 
		void push_front(T x){
			snode<T> *newnode = new snode<T>(x);
			if(!newnode)
				return; 
			if(empty()) 
				head = trail = newnode;
			else{
				newnode->setnext(head);
				head = newnode; 
			} 
			num++; 
		} 
		void push_back(T x){
			snode<T> *newnode = new snode<T>(x);
			if(!newnode)
				return; 
			if(empty()) 
				head = trail = newnode;
			else{
				trail->setnext(newnode);
				trail = newnode; 
			}
			num++; 
		} 
		void pop_front(){
			if(num==1) {
				delete head;
				head = trail = 0; 
			}
			else{
				snode<T> *p = head;
				head = head->getnext();
				delete p; 
			} 
			num--; 
		} 
		void pop_back(){
				if(num==1) {
				delete head;
				head = trail = 0; 
			}
			else{
				snode<T> *p ;
				p = head;
				while(p->getnext()!=trail)
					p= p->getnext();
				delete trail;
				trail = p; 
			}
		} 
		typedef slist_ite<T> iterator ;
		iterator begin(){
			return slist_ite<T>(head); 
		} 
		iterator end(){
			return slist_ite<T>(0); 
		} 
}; 

#endif 









