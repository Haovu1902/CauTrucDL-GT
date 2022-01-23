#ifndef NODE_cpp
#define NODE_cpp

template <class Keys,class T>

class Node{
	private: 
		Keys key;							// luu gia tri khoa
		T elem;								// luu gia tri cua node hien tai
		Node<Keys,T> *next;					// luu dia chi cua node tiep theo
	public:
		Node(){							// ham tao khong doi
			next = 0;	
		}
		Keys getKey(){					// goi gia tri cua khoa
			return key;	
		}	
		void setKey(Keys k){
			key = k;	
		}	
		Node<Keys,T> *getNext(){       //Tra lai dia chi cua doi tuong do thanh phan Next tro den
			return next;
		}
		void setNext(Node<Keys,T> *p){   // Dat thanh phan Next tro vao doi tuong la doi cua phuong thuc
			next = p;
		}
		T getElem(){
			return elem;          //Tra lai dia chi cua phan tu luu trong Node
		}
		void setElem(T e){        //Dat thay the phan tu luu trong Node bang phan tu moi
			elem = e;
		}
};

#endif
