#ifndef HASHTABLE_cpp
#define HASHTABLE_cpp
#include"SLIST.cpp"

template<class Keys,class T>

class Hashtable
{
	private:
		int m;      								// kich thuoc bang bam
		SingleList<Keys,T> *table;					
	public:
		Hashtable(int n);							// ham tao co doi
		~Hashtable(){								// ham huy
			delete[] table;		
		}	
		Node<Keys,T> *Add(Keys key, T obj, int (*hash)(Keys,int));				
		Node<Keys,T> *Find(Keys key, int (*hash)(Keys,int));
		bool Contains(Keys key, int (*hash)(Keys,int));
		int Count();
};

template<class Keys,class T>
Hashtable<Keys,T>::Hashtable(int n)
{
	m = n;
	table = new SingleList<Keys,T>[m];
}

template<class Keys,class T>
Node<Keys,T> *Hashtable<Keys,T>::Add(Keys key, T e, int (*hash)(Keys,int))		// ham them 1
{
	Node<Keys,T> *p;
	int h = hash(key,m); // hash la 1 con tro ham
	p = table[h].getNode(key);
	if(p==NULL){
		return table[h].insertLast(key,e);
	}
	else{
		return NULL;
	}
}	

template<class Keys, class T>
Node<Keys,T> *Hashtable<Keys,T>::Find(Keys key, int (*hash)(Keys,int))		// ham tim kiem phan tu co khoa k nao do
{
	int h = hash(key,m);
	return table[h].getNode(key);	
}

template<class Keys, class T>
bool Hashtable<Keys,T>::Contains(Keys key, int (*hash)(Keys,int))		// ham kiem tra xem cai key co trong bang bam chua
{
	int h = hash(key,m);    //hash la 1 con tro ham
	return table[h].getNode(key)!=NULL;
}

template<class Keys, class T>
int Hashtable<Keys,T>::Count()							// ham dem toan bo bang co bao nhieu phan tu
{
	int t = 0;
	for(int i = 0; i < m; i++){
		t = t + table[i].size();	
	}	
	return t;
}


#endif	
