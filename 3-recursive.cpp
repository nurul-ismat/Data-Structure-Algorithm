#include<iostream>

using namespace std;

int facto(int n){
	if(n>=1){
	return n*facto(n-1);
	}

else if(n==0){
	return 1;
	}
}

int main(int argc, char**argv){

cout<< "The value of 6! is";
cout<<facto(6);
return 0;
}
