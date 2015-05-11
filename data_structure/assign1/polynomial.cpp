//20121324, oh ju young, assignment1

#include "polynomial.h"
#include <iostream>
#include <math.h>

// Copy constructor
Polynomial::Polynomial(const Polynomial& source)
{
	capacity = source.capacity;
	terms = source.terms;
	termArray = source.termArray;	
}	

Polynomial& Polynomial::operator = (const Polynomial& source)
{
	capacity = source.capacity;
	terms = source.terms;
	termArray = source.termArray;
	
}

Polynomial::~Polynomial()
{
	delete []termArray;
}

// Sum of *this and source polynomials
Polynomial Polynomial::Add(const Polynomial& source)
{
	Polynomial c;
	int ap=0, bp=0;
	while ((ap<terms)&&(bp<source.terms))
	{
		if((termArray[ap].exp==source.termArray[bp].exp))
		{
			float t=termArray[ap].coef+source.termArray[bp].coef;
			if(t)
				c.NewTerm(t, termArray[ap].exp);
			ap++; bp++;
		}
		else if(termArray[ap].exp < source.termArray[bp].exp)
		{
			c.NewTerm(source.termArray[bp].coef, source.termArray[bp].exp);
			bp++;
		}
		else
		{
			c.NewTerm(termArray[ap].coef, termArray[ap].exp);	
			ap++;
		}
	}

	for( ; ap<terms; ap++)
		c.NewTerm(termArray[ap].coef, termArray[ap].exp);
	for( ; bp<source.terms; bp++)
		c.NewTerm(source.termArray[bp].coef, source.termArray[bp].exp);

	return c;
}

Polynomial Polynomial::Mult(const Polynomial& source)
{


	Polynomial c;

	int ap=0, bp=0, cp=0;
	float f=0;
	int e=0;
	
	for( ; ap<terms; ap++)
	{
	bp=0;
		for(; bp<source.terms; bp++)
		{
			f = termArray[ap].coef*source.termArray[bp].coef;
			e = termArray[ap].exp + source.termArray[bp].exp;		
			c.NewTerm(f,e);
		}
	}//multiply first


	int count=0;
	int change=0;
	
	for(int i=0; i<c.terms-1; i++)
	{
		if(c.termArray[i].exp < c.termArray[i+1].exp)
		{
			float temp = c.termArray[i].coef;
			c.termArray[i].coef=c.termArray[i+1].coef;
			c.termArray[i+1].coef=temp;
			int tmp = c.termArray[i].exp;
			c.termArray[i].exp=c.termArray[i+1].exp;
			c.termArray[i+1].exp=tmp;
	
			change++;
		}
			
		if(i==c.terms-2 && change!=0)			
		{	i=0;
			change=0;
		}//arrangement
		

	}

	for(int j=0; j<c.terms-count-1; j++)
	{
		if(c.termArray[j].exp==c.termArray[j+1].exp)
		{	c.termArray[j].coef+=c.termArray[j+1].coef;
		
			for(int k=j; k<c.terms-count-2; k++)
			{	c.termArray[k+1].coef=c.termArray[k+2].coef;
				c.termArray[k+1].exp=c.termArray[k+2].exp;
			}
			count++;
			
			j=j-1;
		}
	}//find same exp and put together

	c.terms=c.terms-count;
	return c;

	
}



float Polynomial::Eval(float x)
{
	float sum = 0;
	int p = 0;
	for( ; p<terms; p++)
	{	
		float a=termArray[p].coef;
		float b=1;
		for(int c=1; c<=termArray[p].exp; c++)
			b*=x;
		sum+=a*b;
	}
	return sum;
}

 
void Polynomial::NewTerm(const float coef, const int exp)
{
if(coef==0&&exp==0)
{}
else if(coef==0)
{}
else
{	if(terms==capacity)
	{
		capacity*=2;
		Term*temp=new Term[capacity];
		int s = 0;

		for(; s<terms; s++)
			temp[s]=termArray[s];

		temp[s+1].coef=coef;
		temp[s+1].exp=exp;

		delete[]termArray;
		termArray=temp;
	}
	termArray[terms].coef=coef;
	termArray[terms++].exp=exp;	

	int change=0;

	 for(int i=0; i<terms-1; i++)
        {
                if(termArray[i].exp < termArray[i+1].exp)
                {
                        float temp = termArray[i].coef;
                        termArray[i].coef=termArray[i+1].coef;
                        termArray[i+1].coef=temp;
                        int tmp = termArray[i].exp;
                        termArray[i].exp=termArray[i+1].exp;
                        termArray[i+1].exp=tmp;

                        change++;
                }

                if(i==terms-2 && change!=0)
                {       i=0;
                        change=0;
                }//arrangement

        }
	
}
}


void Polynomial::Print()
{
	for(int i=0; i<terms; i++)
	{
		std::cout << "Coef: " << termArray[i].coef << ", Exp: " << termArray[i].exp << std::endl;
	}
}
