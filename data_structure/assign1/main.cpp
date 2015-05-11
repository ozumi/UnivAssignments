#include "polynomial.h"
#include <iostream>

int main()
{
	Polynomial f, g;
	
	f.NewTerm(1, 1.51); 
	


	std::cout << "f is " << std::endl;
	f.Print();
		
	g.NewTerm(2, 0);
       
	std::cout << "g is " << std::endl;
	g.Print();

	// copy constructor test
	std::cout << "h is created from f" << std::endl;
	Polynomial h = f;
	h.Print();
	
	// assignment operator test
	std::cout << "h is copied from g " << std::endl;
	h = g;	
	h.Print();
	
	// Add test
	std::cout << "f + g is" << std::endl;
	h = f.Add(g);	
	h.Print();
	
	// Mult test
	std::cout << "f * g is" << std::endl;
	h = f.Mult(g);
	h.Print();
	
	// Eval test
	std::cout << "f(2) is " << f.Eval(2.0) << std::endl;
	
	return 0;
}
