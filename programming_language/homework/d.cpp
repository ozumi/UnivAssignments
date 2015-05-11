

void delete(node *x)
{
	x.data=x->right.data;
	x->right=x->right->right;
}



