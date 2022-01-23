#ifndef SINGLELIST_cpp
#define SINGLELIST_cpp
#include"NODE.cpp"
#include<bits/stdc++.h>


using namespace std;

template <class Keys,class T>

class SingleList{
	private:
		Node<Keys,T> *header;
		Node<Keys,T> *trailer;
		long sz;
	public:
		SingleList(){
			header  = NULL;
			trailer = NULL;
			sz     	= 0;
		}
		long size(){
			return sz;	
		}	
		int isEmpty(){
			return sz==0;	
		}	
		Node<Keys,T> *insertLast(Keys k, T e)     // chen them 1 node vao cuoi danh sach
		{      
			Node<Keys,T> *q;
			q = new Node<Keys,T>;
			q->setKey(k);
			q->setElem(e);
			if(header==NULL){
				header = q;
				trailer = q;
			}	
			else{
				trailer->setNext(q);
				trailer = q;
			}
			sz++;
			return q;
		}
		void replace(Node<Keys,T> *p, Keys k, T e)			// loai bo node do con tro p tro toi
		{	
			p->setKey(k);
			p->setelem(e);
		}		
		void remove(Node<Keys,T> *p)          // loai bo node do con tro p tro toi
		{
			Node<Keys,T> *p1;
			if(p==header){
				if(size()==1)
				{
					header = NULL;
					trailer = NULL;		
				}
				else
					header = header->getNext();
				sz--;
			}
			else
			{
				p1 = header;
				while(p1->getNext()!=p)    // vong lap tim den vi tri cua node truoc node p
					p1 = p1->getNext();
				if(p1!=NULL)
				{
					if(p!=trailer)       // tim thay node can xoa
						p1->setNext(p->getNext());	
					else{
						trailer = p1;
						p1->setNext(NULL);
					}	
					sz--;
				}	
			}
			delete p;	
		}	
		Node<Keys,T> *getNode(Keys k)			// tim kiem tuan tu
		{	
			Node<Keys,T> *p;
			p = header;
			while(p!=NULL && p->getKey()!=k)
				p = p->getNext();
			return p;
		}
};
#endif


