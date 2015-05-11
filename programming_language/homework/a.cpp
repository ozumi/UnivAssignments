

void changearray(double *list)
{
	double temp=0; // 1

	for(double i=0; i<n/2; i++)  // even n: n/2+1, odd n:(n-1)/2+1
	{
		temp=list[i];
		list[i]=list[n-i-1];
		list[n-i-1]=temp;    //even n: n/2*3, odd n:(n-1)/2*3
	}
} //total : even n : 2n+2, odd n: 2n


