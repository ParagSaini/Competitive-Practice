// O(n) solution.

class obj {
    public:
    int sum = 0;
    bool isSumT = true;
};

obj isSumTreeHelper(Node* root) {
    if(root == nullptr) {
        obj temp;
        return temp;
    }
    if(root->left == nullptr && root->right == nullptr) {
        obj temp;
        temp.sum = root->data;
        return temp;
    }
    
    obj A = isSumTreeHelper(root->left);
    obj B = isSumTreeHelper(root->right);
    if(A.isSumT && B.isSumT) {
        obj result;
        if( root->data == (A.sum + B.sum) ) {
            result.isSumT = true;
            result.sum = root->data + A.sum + B.sum;
        } else {
            result.isSumT = false;
        }
        return result;
    }else {
        obj result;
        result.isSumT = false;
        return result;
    }
}
bool isSumTree(Node* root)
{
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return true;
    obj result = isSumTreeHelper(root);
    if(result.isSumT) {
        return true;
    }
    return false;
}