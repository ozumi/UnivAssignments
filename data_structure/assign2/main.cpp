#include "stack.h"
#include "calculator.h"
#include <iostream>

// stack & calculator test

int main()
{
	// Stack test
	Stack<int> s;
	
	s.Push(23);
	s.Push(102);
	s.Print();
	printf("--\n");
	
	s.Push(345);
	s.Push(77);
	s.Print();
	printf("--\n");
	
	s.Pop();
	s.Push(678);
	s.Push(91011);
	s.Print();
	printf("--\n");

	// Calculator test

char str[] ="-10-((-2+(2+4*3))-12)+ 122*--(123 + (120+888) - 300)";
//char str[] = "5/0.5-3+((4*5)-(2+(11*30)))";
//char str[]="1*8+7-(3*2)";
     

	// The correct result is 101372
	std::cout << "Result : " << Eval(str) << std::endl;
		
	return 0;

}
