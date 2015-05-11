

int count(*node)
{
	if(node==NULL) //1
		return 0; //1

	if(node->left==NULL && node->right==NULL) //1
		return 1; //1
	else
		return count(node->left)+count(node->right); //level of tree
}
//total time : 3n+3 (n is level of tree)


