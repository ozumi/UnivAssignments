
// Constructor, create empty sparse matrix with (row, col)
template <class type>
Matrix<type>::Matrix(int row, int col)
{
	int p = (nRow<nCol) ? nCol : nRow;
	int i=0;
	Triple<type> s;
	nRow = row;
	nCol = col;

        headnode = new MatrixNode<type>(false, &s);

        if(p==0)
        {       headnode -> next = headnode;
                return;
        }

        MatrixNode<type>**head = new MatrixNode<type>*[p];

        for (i=0; i<p; i++)
                head[i] = new MatrixNode<type>(true, 0);

        int currentRow = 0;
        MatrixNode<type>*last = head[0];

        last -> right = head[currentRow];

        for(i=0; i<s.col; i++)
                head[i] -> next -> down = head[i];

        for(i=0; i<p-1; i++)
                head[i]->next = head[i+1];

        head[p-1] -> next = headnode;
        headnode -> next = head[0];

        delete [] head;

}
	
// Constructor from istream
template <class type>
Matrix<type>::Matrix(std::ifstream& is)
{
	int i=0;
	Triple<type> s;

	is >> nRow >> nCol >> nElem;
	int p = (nRow < nCol) ? nCol : nRow;

	
	std::cout << "Row : " << nRow << ", Col : " << nCol << ", nElem : " << nElem << std::endl;

	s.row=nRow;
	s.col=nCol;
	s.value=nElem;

	headnode = new MatrixNode<type>(false, &s);

	if(p==0) 
	{	headnode -> next = headnode;
		return;
	}


	MatrixNode<type>**head = new MatrixNode<type>*[p];

	for (i=0; i<p; i++)
		head[i] = new MatrixNode<type>(true, 0);

	int currentRow = 0;
	MatrixNode<type>*last = head[0];

	for(i=0; i<s.value; i++) 
	{
		Triple<type> t;

		is >> t.row >> t.col >> t.value;
	
		if(t.row > currentRow)
		{	last->right = head[currentRow];
			currentRow = t.row;
			last = head[currentRow];
		}
		last = last -> right = new MatrixNode<type>(false, &t);
		head[t.col] -> next = head[t.col] -> next -> down = last;
		
	}

	last -> right = head[currentRow];

	for(i=0; i<s.col; i++) 
		head[i] -> next -> down = head[i];
	
	for(i=0; i<p-1; i++)
		head[i]->next = head[i+1];

	head[p-1] -> next = headnode;
	headnode -> next = head[0];

	delete [] head;

}

// Copy constructor
template <class type>
Matrix<type>::Matrix(const Matrix& a)
{
	
	int i=0;
	Triple<type> s;      


        int p = (a.nRow < a.nCol) ? a.nCol : a.nRow;

	nRow=a.nRow;
        nCol=a.nCol;
        nElem=a.nElem;
//	headnode=a.headnode;


 	s.row=a.nRow;
        s.col=a.nCol;
        s.value=a.nElem;

        headnode = new MatrixNode<type>(false, &s);

        if(p==0)
        {       headnode -> next = headnode;
                return;
        }


        MatrixNode<type>**head = new MatrixNode<type>*[p];

        for (i=0; i<p; i++)
                head[i] = new MatrixNode<type>(true, 0);

        int currentRow = 0;
        MatrixNode<type>*last = head[0];

	MatrixNode<type>*arow=a.headnode->next;
	MatrixNode<type>*acur=arow->right;

	int aa=0;

        while(aa!=nRow)
        {
               
		if(acur!=arow)
		{
		 Triple<type> t;

                t.row=acur->triple.row;
		t.col=acur->triple.col;
		t.value=acur->triple.value;

                if(t.row > currentRow)
                {       last->right = head[currentRow];
                        currentRow = t.row;
                        last = head[currentRow];
                }
                last = last -> right = new MatrixNode<type>(false, &t);
              head[t.col] -> next = head[t.col] -> next -> down = last;
		}

		if(acur->right==arow)
		{
			arow=arow->next;
	std::cout<<"2";
			while(arow->right==arow)
			{std::cout<<"1";
				arow=arow->next;
				aa++;
				if(aa==nRow)
					break;
			}

			acur=arow->right;
		}
		else
		acur=acur->right;
        }

        last -> right = head[currentRow];

//        for(i=0; i<s.col; i++)
//                head[i] -> next -> down = head[i];

        for(i=0; i<p-1; i++)
                head[i]->next = head[i+1];

        head[p-1] -> next = headnode;
        headnode -> next = head[0];

        delete [] head;

}
	
// Assignment operator
template <class type>
Matrix<type>& 
Matrix<type>::operator=(const Matrix& a)
{
	nRow = a.nRow;
	nCol = a.nCol;
	nElem = a.nElem;
	headnode = a.headnode;
/*
       int i=0;
        Triple<type> s;


        int p = (a.nRow < a.nCol) ? a.nCol : a.nRow;


        nRow=a.nRow;
        nCol=a.nCol;
        nElem=a.nElem;

        s.row=a.nRow;
        s.col=a.nCol;
        s.value=a.nElem;

        headnode = new MatrixNode<type>(false, &s);

        if(p==0)
        {       headnode -> next = headnode;
                return *this;
        }


        MatrixNode<type>**head = new MatrixNode<type>*[p];

        for (i=0; i<p; i++)
                head[i] = new MatrixNode<type>(true, 0);

        int currentRow = 0;
        MatrixNode<type>*last = head[0];



        MatrixNode<type>*arow=a.headnode->next;
        MatrixNode<type>*acur=arow->right;

        while(arow!=a.headnode)
        {
                Triple<type> t;

                t.row=acur->triple.row;
                t.col=acur->triple.col;
                t.value=acur->triple.value;

                if(t.row > currentRow)
                {       last->right = head[currentRow];
                        currentRow = t.row;
                        last = head[currentRow];
                }
                last = last -> right = new MatrixNode<type>(false, &t);
                head[t.col] -> next = head[t.col] -> next -> down = last;

                if(acur->right==arow)
                {
                        while(acur->right==arow)
                        {       arow=arow->next;
                                if(arow==a.headnode)
                                        break;
                        acur=arow->right;
                }}
                else
                acur=acur->right;
        }

        last -> right = head[currentRow];

        for(i=0; i<s.col; i++)
                head[i] -> next -> down = head[i];

        for(i=0; i<p-1; i++)
                head[i]->next = head[i+1];

        head[p-1] -> next = headnode;
        headnode -> next = head[0];

        delete [] head;

*/

	return *this;
}
	
// Destructor
template <class type>
Matrix<type>::~Matrix()
{
	MatrixNode<type>*av;

	if(!(this->headnode)) return;
	MatrixNode<type>*x = (this->headnode) -> right;
	this->headnode -> right =av;
	av = this->headnode;
	
	while(x!=(this->headnode)) {
	MatrixNode<type>*y = x-> right;
	x -> right = av;
	av = y;
	x = x -> next;
	}
	headnode = 0;
}

// Add Matrix b to *this
template <class type>
Matrix<type>
Matrix<type>::operator+(const Matrix& b)
{
Matrix<type> m(b);

	MatrixNode<type>*row =this->headnode -> next;
	MatrixNode<type>*last =row -> right;
	MatrixNode<type>*mrow = m.headnode -> next;
	MatrixNode<type>*mlast = mrow -> right;
	MatrixNode<type>*temp = last;

	while(mrow!=headnode)
	{
	while(last!=row)
	{
		if(mlast->triple.col==last->triple.col)
		{
			mlast->triple.value=(mlast->triple).value+(last->triple).value;
			temp=mlast;
			mlast=mlast->right;
			last=last->right;
			
		}
		else if(mlast->triple.col > last->triple.col)
		{
			last->right=mlast;
			temp->right=last;
			last=last->right;
		}
		else
		{
			temp=mlast;
			mlast=mlast->right;
		}
	}
		row=row->next;
		mrow=mrow->next;
		last=row->right;
		mlast=mrow->right;
	}

	return m;
}
	
// Subtract Matrix b to *this
template <class type>
Matrix<type>
Matrix<type>::operator-(const Matrix& b)
{
	Matrix<type> m(b);
	
        MatrixNode<type>*row = headnode -> next;
        MatrixNode<type>*last = row -> right;
        MatrixNode<type>*mrow = m.headnode -> next;
        MatrixNode<type>*mlast = mrow -> right;
        MatrixNode<type>*temp = last;

        while(mrow!=headnode)
        {
        while(last!=row)
        {
                if(mlast->triple.col==last->triple.col)
                {
                        mlast->triple.value=(mlast->triple).value-(last->triple).value;
                        temp=mlast;
                        mlast=mlast->right;
                        last=last->right;

                }
                else if(mlast->triple.col > last->triple.col)
                {
                        last->right=mlast;
                        temp->right=last;
                        last=last->right;
                }
                else
                {
                        temp=mlast;
                        mlast=mlast->right;
                }
        }
                row=row->next;
                mrow=mrow->next;
                last=row->right;
                mlast=mrow->right;
        }

	return m;
}
	
// Multiply Matrix b to *this
template <class type>
Matrix<type>
Matrix<type>::operator*(const Matrix& b)
{
	Matrix<type> m(b);

	MatrixNode<type>*row = headnode -> next;
        MatrixNode<type>*last = row -> right;
        MatrixNode<type>*mcol = m.headnode -> next;
	MatrixNode<type>*mrow= m.headnode -> next;
        MatrixNode<type>*mlast = mcol -> right;
        MatrixNode<type>*temp = last;
	type sum=0;
	Triple<type> t;

	int c=0, i=0, r=0;

        while(row!=headnode)
        {
	c=0, i=0;
	mcol=m.headnode->next;
	
        MatrixNode<type>**elm=new MatrixNode<type>*[nCol];

        while(mcol!=m.headnode)
        {
		last=row->right;
		mlast=mcol->down;
	
		while(last!=row&&mlast!=mcol)
		{
                if(last->triple.col==mlast->triple.row)
                {
                        sum+=(mlast->triple).value*(last->triple).value;
                        last=last->right;
                        mlast=mlast->down;
                }
                else if(last->triple.col > mlast->triple.row)
                {
                        mlast=mlast->down;
                       
                }
                else if(last->triple.col < mlast->triple.row)
                {
                        last=last->right;
                }
		else{}

		if(last==row||mlast==mcol)
		{
			if(sum!=0){
			t.row=r;
			t.col=c;
			t.value=sum;
			sum=0;
			elm[i]=new MatrixNode<type>(false, &t);
			i++;
			}
		}
		}

	mcol=mcol->next;
	c++;
        }
		temp=mrow;
		for(int k=0; k<i; k++)
		{
		temp->right=elm[k];
		temp=elm[k];	
		}
	        temp->right=mrow;

	row=row->next;
	mrow=mrow->next;
	r++;

	delete [] elm;
        }

	return m;
}
	
// Swap i-th row with j-th row
template <class type>
Matrix<type>& 
Matrix<type>::SwapRow(int i, int j)
{

        MatrixNode<type>*I = headnode -> next;
        MatrixNode<type>*J = headnode -> next;
        MatrixNode<type>*lefti;
        MatrixNode<type>*leftj;
        MatrixNode<type>*righti;
        MatrixNode<type>*rightj;
        MatrixNode<type>*now;
        MatrixNode<type>*nowrow;
        MatrixNode<type>*temp;
        MatrixNode<type>*nowi;
        MatrixNode<type>*nowj;


	for(int k = 0; k<i; k++)
		I= I -> next;
	
	for(int k = 0; k<j; k++)
		J = J -> next;
	

	now=I->right;	
	I->right=J->right;
	J->right=now;

	now=I->right;
	while(now->right!=J)
	{	
		now->triple.row=i;
		now=now->right;
	}
	now->triple.row=i;
	now->right=I;

	now=J->right;
	while(now->right!=I)
	{
		now->triple.row=j;
		now=now->right;
	}
	now->triple.row=j;
	now->right=J;


        nowrow=headnode->next;

        int noi=0;
        int noj=0;

        while(nowrow!=headnode)
        {
        noi=1;
        noj=1;





                temp=nowrow;
                now=temp->down;
                for(int a=0; a<nRow; a++)
                {
                        if(now==nowrow)
                        {
                                lefti=temp;
                                righti=nowrow;
                                a=nRow;
                                noi=1;
                        }
                        else if(temp->triple.row < now->triple.row)
                        {       lefti=temp;
                                temp=now;
                                now=now->down;
                        }
                        else if(temp->triple.row>now->triple.row)
                        {
                                righti=now;
                                nowi=temp;
                                a=nRow;
                                noi=0;
                        }
                        else if(now->triple.row>i)
                        {
                                lefti=temp;
                                righti=now;
                                a=nRow;
                                noi=1;
                        }
                        else{}
                }
                temp=now;
                now=temp->down;
                for(int a=i+1; a<nRow; a++)
                {
                        if(now==nowrow)
                        {
                                leftj=temp;
                                rightj=nowrow;
                                a=nRow;
                                noj=1;
                        }
                        else if(temp->triple.row<now->triple.row)
                        {
                                temp=now;
                                now=now->down;
                        }
                        else if(temp->triple.row>now->triple.row)
                        {
                                leftj=temp;
                                rightj=now->down;
                                nowj=now;
                                a=nRow;
                                noj=0;
                        }
                        else if(now->triple.row>j)
                        {
                                leftj=temp;
                                rightj=now;
                                a=nCol;
                                noj=1;
                        }
                        else{}
                }


                if(noi==0&&noj==0)
                {
                        if(righti==nowj)
                        {

                                lefti->down=nowj;
                                nowj->down=nowi;
                                nowi->down=rightj;
                        }
                        else
                        {
                        lefti->down=righti;
                        leftj->down=rightj;
                        lefti->down=nowj;
                        nowj->down=righti;
                        leftj->down=nowi;
                        nowi->down=rightj;
                        }

                }
                else if(noi==1&&noj==0)
                {
                        if(righti==nowj)
                        {}
                        else
                        {
                        nowj->down=lefti->down;
                        lefti->down=nowj;
                        leftj->down=rightj;
                        }
                }
                else if(noi==0&&noj==1)
                {
                        if(righti==nowj)
                        {}
                        else
                        {
                        nowi->down = leftj->down;
                        leftj->down = nowi;
                        lefti->down = righti;
                        }
                }
                else if(noi==1&&noj==1)
                {}
                else{}

                nowrow=nowrow->next;
        }


	return *this;

}
	
// Swap i-th col with j-th col
template <class type>
Matrix<type>& 
Matrix<type>::SwapCol(int i, int j)
{
	MatrixNode<type>*I = headnode -> next;	
        MatrixNode<type>*J = headnode -> next;
        MatrixNode<type>*lefti;
        MatrixNode<type>*leftj;
        MatrixNode<type>*righti;
        MatrixNode<type>*rightj;
        MatrixNode<type>*now;
	MatrixNode<type>*nowrow;
	MatrixNode<type>*temp;
	MatrixNode<type>*nowi;
	MatrixNode<type>*nowj;
       
        for(int k = 0; k<i; k++)
                I= I -> next;
        
        for(int k = 0; k<j; k++)
                J = J -> next; 

	now=I->down;
        I->down=J->down;
        J->down=now;

        now=I->down;
        while(now->down!=J)
        {
            now->triple.col=i;
                now=now->down;
        }
        now->triple.col=i;
        now->down=I;

        now=J->down;
        while(now->down!=I)
        {
               now->triple.col=j;
               now=now->down;
        }
        now->triple.col=j;
        now->down=J;

	nowrow=headnode->next;

	int noi=0;
	int noj=0;

	while(nowrow!=headnode)
	{
	noi=1;
	noj=1;


                temp=nowrow;
                now=temp->right;
                for(int a=0; a<nCol; a++)
                {
                        if(now==nowrow)
                        {
                                lefti=temp;
                                righti=nowrow;
                                a=nCol;
                                noi=1;
                        }
                        else if(temp->triple.col < now->triple.col)
                        {	lefti=temp;
                                temp=now;
                                now=now->right;
                        }
                        else if(temp->triple.col>now->triple.col)
                        {	
                                righti=now;
                                nowi=temp;
                                a=nCol;
                                noi=0;
                        }
                        else if(now->triple.col>i)
                        {
                                lefti=temp;
                                righti=now;
                                a=nCol;
                                noi=1;
                        }
                        else{}
		}
		temp=now;
		now=temp->right;
                for(int a=i+1; a<nCol; a++)
                {
                        if(now==nowrow)
                        {
                                leftj=temp;
                                rightj=nowrow;
				a=nCol;
				noj=1;
                        }
                        else if(temp->triple.col<now->triple.col)
                        {
                                temp=now;
                                now=now->right;
                        }
                        else if(temp->triple.col>now->triple.col)
                        {
                                leftj=temp;
                                rightj=now->right;
				nowj=now;
				a=nCol;
				noj=0;
                        }
                        else if(now->triple.col>j)
                        {
                                leftj=temp;
                                rightj=now;
				a=nCol;
				noj=1;
                   	}
			else{}
		}


		if(noi==0&&noj==0)
		{
			if(righti==nowj)
			{
				
				lefti->right=nowj;
				nowj->right=nowi;
				nowi->right=rightj;
			}			
			else
			{
			lefti->right=righti;
			leftj->right=rightj;
			lefti->right=nowj;
			nowj->right=righti;
			leftj->right=nowi;
			nowi->right=rightj;
			}

		}
		else if(noi==1&&noj==0)
		{
			if(righti==nowj)
			{}
			else
			{
			nowj->right=lefti->right;
			lefti->right=nowj;
			leftj->right=rightj;
			}
		}
		else if(noi==0&&noj==1)
		{
			if(righti==nowj)
			{}
			else
			{
			nowi->right = leftj->right;
			leftj->right = nowi;
			lefti->right = righti;
			}
		}
		else if(noi==1&&noj==1)
		{}
		else{}

		nowrow=nowrow->next;
	}
		
	return *this;
}
	
// Create single element in the matrix
template <class type>
Matrix<type>& 
Matrix<type>::CreateElement(int i, int j, type val)
{
	Triple<type> c;
	c.row=i;
	c.col=j;
	c.value=val;

	MatrixNode<type>*n = new MatrixNode<type>(false, &c); 
	MatrixNode<type>*nowrow = headnode->next;
	MatrixNode<type>*final = nowrow -> right;
	MatrixNode<type>*temp = final;
	MatrixNode<type>*now;
	int rownum  = 0;

	while(final != headnode)
	{
		if(rownum == c.row)
		{
			final=nowrow->right;
			
			if(final->right==nowrow)
			{
				final->right = n;
				n -> right = nowrow;
			}
			else
			{
				
				if(final->triple.col > c.col)
				{
				nowrow->right=n;
				n->right=final;
				}
				else{
				while(final->right!=nowrow)
				{
					temp = final;
					final = final->right;
					
					if(final->triple.col > c.col)
					{	temp->right = n;
						n->right = final;
						break;
					}
				}	
				if(final->right==nowrow)
				{	final->right = n;
					n->right = nowrow;
				}
				}
			}	
		
		final = headnode;
		}
		else
		{
			rownum++;

			nowrow=nowrow->next;
		}
	}

	nowrow=headnode->next;

	for(int i=0; i<c.col; i++)
		nowrow=nowrow->next;
	

	now=nowrow->down;

	if(now==nowrow)
	{
		n->down = nowrow;
		nowrow->down = n;
	}
	else
	{
		while(now!=nowrow)
		{	
			if(now->triple.row<c.row)
			{	temp=now;
				now=now->down;
			}
			else
			break;
		}
		temp->down=n;
		n->down=now;
	}

	return *this;
}
	
// Transpose matrix
template <class type>
Matrix<type>& 
Matrix<type>::Transpose()
{
	



	return *this;
}




