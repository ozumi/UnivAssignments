#ifndef CALCULATOR_H
#define CALCULATOR_H

//
// Simple calculator using Stack
//
// CSE231 Winter 2013
//
// Won-Ki Jeong (wkjeong@unist.ac.kr)
//20121324 oh ju young
//
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
Stack<double> opr; // stack for operands
Stack<char> opt;   // stack for operators
Stack<double> output;
Stack<double> order;
//
// Modify Eval() below to evaluate the given expression
//
double Eval(char* in)
{
	char temp[1000];//postfix array
	char tp;
	
	double out = 0;
	
	char buf[1000]; // temp buffer
	char lastToken = '#';
	
	double operand;
	int i = 0, bi = 0, j = 0, n=0, q=0;
	
	opt.Push('#');


	while(in[i] != '\0')
	{
		char c=in[i];
		
		// Operators
		if(c == '+' || c == '-' ||
		   c == '*' || c == '/' ||
		   c == '(' || c == ')')
		{
			if(bi > 0)
			{
				buf[bi++] = NULL;
				operand = atof(buf);				
				bi = 0;
				temp[j++]='@';
				
				// push operand
				std::cout << "New operand : " << operand << std::endl;
				
				if(q==1)
				{
					opr.Push(-operand);
				 	q=0;
				}
				else
					opr.Push(operand);
				
				
			}

			// push operator
			std::cout << "New operator : " << c << std::endl;
			
			//stack and temp
			if(opt.Top()=='#')
			{
				if(i==0 && c=='-')
					q=1;
				else			
					opt.Push(c);	
			}
			else{
			
			if(c==')')
			{
				for(; opt.Top() != '('; opt.Pop())
				{	temp[j++]=opt.Top();
					
				}	
				opt.Pop();
				
			}
			else if(c=='(')
			{
				opt.Push(c);
				
			}
			else if(c=='*' || c=='/')
			{
				if(opt.Top()=='-' || opt.Top()=='+' || opt.Top()=='(')
				{	opt.Push(c);
					
				}
				else 
				{	while(opt.Top()=='*' || opt.Top()||'/')
					{
					temp[j++]=opt.Top();
					opt.Pop();
					}
					opt.Push(c);
				
				}
				
			}		
			else if(c=='+')
			{
			
				if(opt.Top()=='(')
				{	opt.Push(c);
					
				}
				else 
				{	while(opt.Top()=='+' || opt.Top()=='-' || opt.Top()=='*' || opt.Top()=='/')
					{
					temp[j++]=opt.Top();
					opt.Pop();
					}
					opt.Push(c);
				}
				
			}
                       else if(c=='-')
                       {
				
					if(in[i-1]=='+' || in[i-1]=='/' || in[i-1]=='*' || in[i-1]=='(' || in[i-1]=='-')
					{
						if(in[i+1]=='-')
							i+=1;
						else
							q=1;	
					}
					else 
					{
                        		       
                                	       	while(opt.Top()=='+'|| opt.Top()=='*' || opt.Top()=='/' || opt.Top()=='-')
                                       		{	
						temp[j++]=opt.Top();
						opt.Pop();
						}
						opt.Push(c);
                              		}  	
				
                       		 
			}
			else {}
			}
		}	
		// Operands
		else if(c=='.' || c == '0' || c == '1' ||
				c == '2' || c == '3' ||
				c == '4' || c == '5' ||
				c == '6' || c == '7' ||
				c == '8' || c == '9')
		{
			buf[bi++] = c;
		}
		else {}
			
	
		i++;

	}

	// push the very last operand if exists
	if(bi > 0)
	{
		buf[bi++] = NULL;
		operand = atof(buf);
		bi = 0;
		
		// push operand
		std::cout << "New operand : " << operand << std::endl;
		temp[j++]='@';
		opr.Push(operand);
	}

	if(opt.Top()!='#')
	{
	for(; opt.Top()!='#'; opt.Pop())
		temp[j++]=opt.Top();
	}
	j--;
	

	for(; opr.IsEmpty()!=1;opr.Pop())
		order.Push(opr.Top());

	int k=0;

	for(; k<=j; k++)
	{
		
		tp=temp[k];

		if(tp=='+'||tp=='-'||tp=='/'||tp=='*')
		{
			double le,ri;
			ri=output.Top();
			output.Pop();
			le=output.Top();
			output.Pop();

			if(tp=='*')
				output.Push(le*ri);	
			else if(tp=='/')
				output.Push(le/ri);
			else if(tp=='+')
				output.Push(le+ri);
			else if(tp=='-')
				output.Push(le-ri);
			else{}
		}
		else
		{
			output.Push(order.Top());
			order.Pop();
		}	
	
	}

	out=output.Top();

	return out;	
}


#endif
