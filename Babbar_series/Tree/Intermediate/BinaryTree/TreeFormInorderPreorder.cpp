Node* buildTreeHelper(int in[], int pre[],int rootInd, int s, int e, int n) {
    if(s == e) {
        Node* root = new Node(pre[rootInd]);
        return root;
    }
    if(s > e || rootInd > n) return nullptr;
    
    Node* root = new Node(pre[rootInd]);
    
    int ind = 0;
    for(int i=s; i<=e; i++) {
        if(in[i] == pre[rootInd]) {
            ind = i;
        }
    }
    
    root->left = buildTreeHelper(in, pre, rootInd+1, s, ind-1, n);
    root->right = buildTreeHelper(in, pre, rootInd+ind-s+1 , ind+1, e, n);
    
    
    return root;
    
}
Node* buildTree(int in[],int pre[], int n)
{
    if(n == 0) return nullptr;
    int start = 0;
    int end = n-1;
    int rootInd = 0;
    return buildTreeHelper(in, pre, rootInd, start, end, n);
    
}
