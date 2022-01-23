#ifndef SINGLELIST_cpp
#define SINGLELIST_cpp
#include"NODE.cpp"
#include<bits/stdc++.h>


using namespace std;

template <class Keys,class T>

class SingleList{
	private:
		Node<Keys,T> *header;  				// luu dia chi cua node dau
		Node<Keys,T> *trailer;				// luu dia chi cua node cuoi
		long sz;							// kich thuoc cua list
	public:
		SingleList(){						// ham tao khong doi
			header  = NULL;
			trailer = NULL;
			sz     	= 0;
		}
		long size(){						// phuong thuc tra ve so luong node trong danh sach
			return sz;	
		}	
		int isEmpty(){						// ham kiem tra list co trong khong
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


