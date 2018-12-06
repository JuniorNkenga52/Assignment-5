/*Nkengla Muluh Awa Junior
 * CS 300
 * 11/21/2018
 * */
#ifndef BST_h
#define BST_h
#include<string>

using namespace std;

template<class T>
struct node{
T data;
node<T>* left;
node<T>* right;
};

template<class T>
class BST {
	node<T>* root;
	public:
	int count=0;
        BST():root(NULL){}
	void add(const T&);
//	void remove(const T&);
	T search(const T&,const T&);
	void printInOrder();
	private:
	void add(const T&,node<T>*&);
        T search(const T&,const T&,node<T>*);
        void printInOrder(node<T>*);
//	void remove(const T&,root);
};
template<class T>
void BST<T>::printInOrder(){
	printInOrder(root);
}
template<class T>
void BST<T>::printInOrder(node<T> *p){
	if(p!=NULL){
	printInOrder(p->left);
	cout<<p->data<<endl;
	printInOrder(p->right);
	}
}
template<class T>
void BST<T>::add(const T& item){
	count++;
add(item,root);
}
template<class T>
void BST<T>::add(const T& item,node<T>*& p){
if(p==NULL){
	p=new node<T>;
	p->data=item;
	p->left=NULL;
	p->right=NULL;
}else if(p->data>item){
	add(item,p->left);
}else if(p->data<item){
	add(item,p->right);
 }
}
template<class T>
T BST<T>::search(const T& item,const T& item2){
	return search(item,item2,root);
}
template<class T>
T BST<T>::search(const T& item,const T& item2,node<T>* p){
	if(p==NULL){
		return item2; 
	}else if(p->data==item){
		 return p->data;
	}else if(p->data<item){
		 return search(item,item2,p->right);
	}else if(p->data>item){
		 return search(item,item2,p->left);
	}
}
#endif
