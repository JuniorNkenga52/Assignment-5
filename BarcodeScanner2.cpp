#include"LinkedList.h"
#include<time.h>
#include<fstream>
#include<string>
#include<sstream>
#include"UPC.h"
#include"arraySearch.h"
#include"BST.h"

 using namespace std;
void readIntoBST(BST<UPC>&);
int readIntoArray(UPC*&);
void buildList(LinkedList<UPC>*&,int);
void searchList(UPC&,LinkedList<UPC>*&,int);
int function(UPC&,int&);

int main(){
string code;
BST<UPC> bst;
readIntoBST(bst);///bst is created here

UPC* array=new UPC[1050000]; ///unsorted array
int size=readIntoArray(array); 
LinkedList<UPC> *list=new LinkedList<UPC>[1000];  //// Hash table
buildList(list,1000);  /// inserting data into the hash table here 
cout<<"UPC Code: ";
cin>>code;
UPC except("-1","Not Found");
UPC entry(code);
clock_t t;
t=clock();
cout<<bst.search(entry,except)<<endl;
t=clock()-t;
cout<<"BST time: "<<t<<" milliseconds"<<endl;
clock_t t1;
t1=clock();
search(array,entry,size);
t1=clock()-t1;
cout<<"Array time: "<<t1<<" milliseconds"<<endl;
clock_t t2;
t2=clock();
searchList(entry,list,1000);
t2=clock()-t2;
cout<<"Hash table time: "<<t2<<" milliseconds"<<endl;
delete[] array;
for(int i=0; i<1000; i++){
	list[i].destroylist();
}
return 0;
}
void readIntoBST(BST<UPC>& bst){
        ifstream ff;
 ff.open("upc_corpus.txt");
 string line;
 while(getline(ff,line)){
         istringstream ss(line);
         string code,name;
         getline(ss,code,',');
         getline(ss,name);
         UPC upc(code,name);
         bst.add(upc);
 }
}
int readIntoArray(UPC*& array){
int size=0;
 ifstream ff;
 ff.open("upc_corpus.txt");
 string line;
 while(getline(ff,line)){
         istringstream ss(line);
         string code,name;
         getline(ss,code,',');
         getline(ss,name);
         UPC upc(code,name);
         array[size]=upc;
         size++;
 }
 return size;
}
void buildList(LinkedList<UPC>*& list,int index){
 ifstream ff;
 ff.open("upc_corpus.txt");
 string line;
 while(getline(ff,line)){
         istringstream ss(line);
         string code,name;
         getline(ss,code,',');
         getline(ss,name);
         UPC upc(code,name);
         int bucket=function(upc,index);
	 list[bucket].insertFirst(upc);
   }
}
int function(UPC& upc,int& index){
	long code;
	stringstream ss(upc.getCode());
	ss>>code;
	return code%index;
}
void searchList(UPC& entry,LinkedList<UPC>*& list,int index){
	int bucket=function(entry,index);
	bool res=list[bucket].search(entry);
}




