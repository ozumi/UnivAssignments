#include "matrix.h"
#include <iostream>

// matrix test
using namespace std;

int main()
{
	ifstream myReadFile;
	myReadFile.open("matrix.txt");
		
	// create matrix from file
	Matrix<int> t(myReadFile);
Matrix<int> c(9,9);
	myReadFile.close();
	t.Print();
myReadFile.open("test.txt");
	Matrix<int> b(myReadFile);

	myReadFile.close();
b.Print();

cout<<"---"<<endl;
t.SwapRow(4,6);
//t.Print();
cout<<"----"<<endl;
t.SwapCol(1,7);	

	cout << "----" << endl;
	// insert new element
//	t.CreateElement(5,5,777);
//c.Print();
	cout << "----" << endl;
t.Print();
t=t*t;

//t.CreateElement(6,6,777);

cout<<"----"<<endl;
	b.Print();		
	return 0;
}
