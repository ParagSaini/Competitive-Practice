bool search(int val, int inorder[], int s, int e) {
    for(int i=s; i<=e; i++) {
        if(val == inorder[i]) {
            return true;
        }
    }
    return false;
}

// getting the level order for the next root, 
int* extractKey(int start, int end, int inorder[], int levelOrder[]) {
    int totalNum = end-start+1;
    int num = 0;
    int i=0;
    int* arr = new int[totalNum];
    while(num != totalNum) {
        if( search(levelOrder[i], inorder, start, end)) {
            arr[num] = levelOrder[i];
            num++;
        }
        i++;
    }
    return arr;
}

// actual function (main)
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    if(n == 0) return nullptr;
    if(iStart > iEnd) return nullptr;
    if(iStart == iEnd) {
        Node* node = new Node(inorder[iStart]);
        return node;
    }
    
    Node* root = new Node(levelOrder[0]);
    int ind = 0;
    for(int i=iStart; i<=iEnd; i++) {
        if(inorder[i] == levelOrder[0]){
            ind = i;
            break;
        }
    }
    // make the levelOrder for the left and right subtree.
    
    int* llevel= extractKey(iStart, ind-1, inorder, levelOrder);
    int* rlevel = extractKey(ind+1, iEnd, inorder, levelOrder);
    
    
    root->left = buildTree(inorder, llevel, iStart, ind-1, n);
    root->right = buildTree(inorder, rlevel, ind+1, iEnd, n);
    
    return root;
}