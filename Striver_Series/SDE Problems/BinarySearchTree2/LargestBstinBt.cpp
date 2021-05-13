#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
//   T.c - O(n) & s.c O(H) -- space that our recursive stack takes
class BstAns{
    public:
    int mini, maxi, size;
    bool isBst;
    BstAns(int mi, int ma, int s, bool bst){
        mini = mi;
        maxi = ma;
        size = s;
        isBst = bst;
    }
};
BstAns largestBstHelper(Node* root, int& maxSize) {
    if(root == nullptr) {
        return BstAns(INT_MAX, INT_MIN, 0, true);
    }
    BstAns leftT = largestBstHelper(root->left, maxSize);
    BstAns rightT = largestBstHelper(root->right, maxSize);

    if(leftT.isBst && rightT.isBst && leftT.maxi < root->data && rightT.mini > root->data) {
        int curSize = leftT.size + rightT.size + 1;
        if(curSize > maxSize) maxSize = curSize;
        // remember the nullptr node also.
        return BstAns(min(leftT.mini, root->data), max(rightT.maxi, root->data), curSize, true);
    }

    return BstAns(min(leftT.mini, root->data), max(rightT.maxi, root->data), leftT.size + rightT.size + 1, false);
}
int largestBst(Node *root)
{
	if(root == nullptr) return 0;
	int maxSize = 1;
	largestBstHelper(root, maxSize);
	return maxSize;
}

// t.c O(n2) && s.c O(H).
bool isBst(Node* root, int& n, int& prev) {
    if(!root) return true;
    
    if(!isBst(root->left, n, prev)) return false;
    
    if(prev >= root->data) return false;
    prev = root->data;
    n++;
    
    if(!isBst(root->right, n, prev)) return false;
    return true;
}
int largestBst(Node *root)
{
	if(!root) return 0;
	int n = 0;
	int prev = INT_MIN;
	if(isBst(root, n, prev)) return (n);
	return max(largestBst(root->left), largestBst(root->right));
}