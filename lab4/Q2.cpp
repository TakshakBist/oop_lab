#include <iostream>
#include <cstring>

using namespace std;

class Concatenate{
private:
	char *arr;
public:
	Concatenate(){};
	Concatenate( char string[]){
		arr=new char[strlen(string)];

		for (int i = 0; i < strlen(string); i++)
		{
			arr[i]=string[i];
		}
	}
	Concatenate Join( Concatenate s1, Concatenate s2){
		arr=new char[33];
		arr=strcat(s1.arr,s2.arr);
	}
	void Display(){
		cout << arr <<endl;
	}
	~Concatenate(){
		delete []arr;
	}
};

int main(){
	Concatenate s1("Engineers are ");
	Concatenate s2(" Creatures of Logic");
	Concatenate s3;
	s3.Join(s1,s2);
	s3.Display();
	return 0;
}