#ifndef __snode__cpp__
#define __snode__cpp__

template <class T>
class snode{
	private:
		T elem;
		snode<T> *next;
		public:
			snode<T>(){
				next = 0;
			}
			snode<T>(T x, snode<T> *nex = 0){
				elem = x;
				next = nex;
			}
			T & getelem(){
				return elem;
			}
			snode<T> *getnext(){
				return next;
			}
			void setelem(T x){
				elem = x; 
			} 
			void setnext(snode<T> *nex){
				next = nex; 
			} 
};

#endif 
