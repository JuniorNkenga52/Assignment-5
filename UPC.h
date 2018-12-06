/*Nkengla Muluh Awa Junior
 * CS 300
 * 11/21/2018
 * */
#ifndef UPC_h
#define UPC_h
#include<string>
using namespace std;

class UPC {
	string code,name;
	public:
	UPC(string a="",string b=""):code(a),name(b){}
	string getCode(){return code;}
	string getName(){return name;}
	friend ostream& operator<<(ostream& os,const UPC& a);
	friend bool operator<(const UPC& a,const UPC& b);
	friend bool operator>(const UPC&,const UPC&);
	friend bool operator==(const UPC&,const UPC&);
};
bool operator==(const UPC& a,const UPC& b){
        return a.code==b.code;
}
bool operator>(const UPC& a,const UPC& b){
	return a.code>b.code;
}
ostream& operator<<(ostream& os,const UPC& a){
	os<<a.name;
	return os;
}
bool operator<(const UPC& a,const UPC& b){
	return a.code<b.code;
}
#endif
