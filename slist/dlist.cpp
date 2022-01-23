#ifndef __dlist__cpp__
#define __dlist__cpp__
#include"dnode.cpp"
#include"dlistite.cpp"
template <class T>
class dlist
{
	private:
		dnode<T> *head;
		dnode<T> *trail;
		int num;
	public:
	dlist<T>()
	{
		head = trail = 0;//NULL
		num = 0;
	}	
	dlist<T>(T x, int n)
	{
		head = trail = 0;
		num = 0;
		int i = 0;
		while (i<n) 
		{
			push_front(x);
			i++;
		}
	}		
	bool empty(){ return num==0;}
	int size() { return num; }
	T &front() { return head->getelem();}
	T &back() { return trail->getelem();}
	void push_front(T x)
	{
		if(empty())
			head = trail = new dnode<T>(x);
		else
		{
			dnode<T> *newnode =  new dnode<T>(x);
			
			newnode->setnext(head);
			head->setprev(newnode);
			head = newnode;
			/*			
			head =  new dnode<T>(x,head,0);
			head->getnext()->setprev(head);*/
		}
		num++;		
	}
	void push_back(T x)
	{
		if(empty())
			head = trail = new dnode<T>(x);
		else
		{
			dnode<T> *newnode =  new dnode<T>(x);
			newnode->setprev(trail);
			trail->setnext(newnode);
			trail = newnode;
		}
		num++;
	}
	void pop_front()
	{
		if(num==1)
			head = trail = 0;
		else
			head = head->getnext();
		num--;
	}
	void pop_back()
	{
		if(num==1)
			head = trail = 0;
		else
			trail = trail->getprev();
		num--;
	}
	//Bo lap xuoi
	typedef dlist_ite<T> iterator;
	iterator begin()
	{
		return dlist_ite<T>(head);
	}
	iterator end()
	{
		return dlist_ite<T>(0);
	}
	typedef dlist_reite<T> reverse_iterator;
	reverse_iterator rbegin()
	{
		return dlist_reite<T>(trail);
	}
	reverse_iterator rend()
	{
		return dlist_reite<T>(0);
	}
	void insert(iterator it, T x)
	{
		if(it.getcurr()==head)
			push_front(x);
		else
		{
			dnode<T> *newnode = new dnode<T>(x);
			dnode<T> *p = it.getcurr();
			dnode<T> *q = p->getprev();
			
			p->setprev(newnode);
			newnode->setnext(p);
			q->setnext(newnode);
			newnode->setprev(q);
			num++;
		}
		
	}
	void erase(iterator it)
	{
		if(it.getcurr()==head)
			return pop_front();
		if(it.getcurr()==trail)
			return pop_back();
		dnode<T> *pre = it.getcurr()->getprev();
		dnode<T> *nex = it.getcurr()->getnext();
		pre->setnext(nex);
		nex->setprev(pre);
		num--;
	}
};

#endif
