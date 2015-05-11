
void insertnode(node*l, node*s)
{
	l->left = s->left;
	l->leftThread = s->leftThread;
	l->right = s;
	r->rightThread = true;
	s->left = l;
	s->leftThread = false;

	if(!l->leftThread)
		node *temp = InorderSucc(); //function in the book
		temp->right = l;
}


