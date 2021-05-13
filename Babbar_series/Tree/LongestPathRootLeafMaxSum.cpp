class obj {
    public:
    int sum = 0;
    int NumNode = 0;
};
obj FindResult(Node* root ) {
    if(root->left == nullptr && root->right == nullptr) {
        obj result;
        result.sum = root->data;
        result.NumNode = 1;
        return result;
    }
    
    obj result1, result2;
    if(root->left != nullptr) {
        result1 = FindResult(root->left);
    }
    if(root->right != nullptr) {
        result2 = FindResult(root->right);
    }
    
    if(result1.NumNode == result2.NumNode) {
        if(result1.sum >= result2.sum) {
            result1.NumNode++;
            result1.sum += root->data;
            return result1;
        } else {
            result2.NumNode++;
            result2.sum += root->data;
            return result2;
        }
    }else if(result1.NumNode > result2.NumNode) {
        result1.NumNode++;
        result1.sum += root->data;
        return result1;
    }
    else {
        result2.NumNode++;
        result2.sum += root->data;
        return result2;
    }
}
int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	if(root == nullptr) return 0;
	obj result = FindResult(root);
	return result.sum;
	
}