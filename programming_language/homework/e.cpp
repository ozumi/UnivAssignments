
int sum(chain &x)
{
	Iterator*a=x.first;
	Iterator*b=a->link->link->link->link;
	int sum=0;

	for(int i=1; i<=n-5; i++)
	{	sum=a.data + b.data;
		a=a->link;
		b=b->link;
	}

	return sum;
}





