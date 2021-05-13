 /* Method 1: In the case of recursion just handle the one case the all other cases are handled automatically.. */
// Time complexity = O(n), space complexity = O(1);
#include<climits>
bool BstUti(Node* root, int min, int max) {
    if(root == nullptr) return true;
    if(root->data < min || root->data > max) return false;
    return BstUti(root->left, min, root->data - 1) && BstUti(root->right , root->data + 1, max);
}
bool checkBST(Node* root) {
	return BstUti(root, INT_MIN, INT_MAX);
}
/*Method 2: Do an inorder traversal(LSR), this must be in sorted order for a binary tree to become a BST. */

bool isBST(node* root) 
{ 
	static node *prev = NULL; 
	
	// traverse the tree in inorder fashion and keep track of prev node 
	if (root) 
	{ 
		if (!isBST(root->left)) 
		return false; 

		// Allows only distinct valued nodes 
		if (prev != NULL && 
			root->data <= prev->data) 
		return false; 

		prev = root; 

		return isBST(root->right); 
	} 

	return true; 
} 

