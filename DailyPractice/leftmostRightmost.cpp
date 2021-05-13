// link: https://practice.geeksforgeeks.org/problems/leftmost-and-rightmost-nodes-of-binary-tree/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1
void printCorner(Node *root)
{
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int s = q.size();
        Node* temp;
        if(s != 1) cout<<q.front()->data<<" ";
        while(s--) {
            temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        cout<<temp->data<<" ";
    }
}