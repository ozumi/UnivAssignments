
template<class type>
Stack<type>::~Stack()
{
	delete []array;
}

template<class type>
type& Stack<type>::Top()
{
	if(IsEmpty()) throw "Stack is empty.";
	return array[top];
}

template<class type>
void Stack<type>::Push(const type& item)
{
	if(top==capacity-1)
	{
		type *temp = new type [capacity*2];
		for(int i=0; i<capacity; i++)
			temp[i]=array[i];	
		
		delete []array;
		array = temp;		
		capacity*=2;
	}
	array[++top]=item;
}

template<class type>
void Stack<type>::Pop()
{
	if(IsEmpty()) throw "Stack is empty. Cannot delete.";
	array[top--].~type();
}

template<class type>
bool Stack<type>::IsEmpty() const
{
	if(top==-1)
		return 1;
	else
		return 0;
}
