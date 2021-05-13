#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

// storing the level order Traversal in the string, including the nullptr as 1001(greater than maxValue in root->val)
string serialize(TreeNode* root) {
    string result;
    if(root == nullptr) return result;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if(cur == nullptr) {
            result.append("1001 ");
            continue;
        }else {
            result.append(to_string(cur->val)).append(" ");
        }
        q.push(cur->left);
        q.push(cur->right);
    }
    return result;
}

void splitVals(string data, vector<int>& nodeVal){
    int start = 0;
    for(int i=0; i<data.length(); i++) {
        if(data[i] == ' ') {
            nodeVal.push_back(stoi(data.substr(start, i-start)));
            start = i+1;
        }
    }
}

// Decodes your encoded data to tree.
// Making the tree using the level ordered string, by seperating the values of root nodes first.
TreeNode* deserialize(string data) {
    if(data.length() == 0) return nullptr;
    vector<int> nodeVal;
    splitVals(data, nodeVal);
    
    int index = 0;
    TreeNode* root = new TreeNode(nodeVal[index++]);
    queue<TreeNode*> q;
    q.push(root);
    while(index < nodeVal.size()) {
        int size = q.size();
        while(size) {
            TreeNode* curNode = q.front();
            q.pop();
            if(nodeVal[index] == 1001) {
                curNode->left = nullptr;
                index++;
            }else {
                curNode->left = new TreeNode(nodeVal[index++]);
                q.push(curNode->left);
            }
            if(nodeVal[index] == 1001) {
                curNode->right = nullptr;
                index++;
            }else {
                curNode->right = new TreeNode(nodeVal[index++]);
                q.push(curNode->right);
            }
            size--;
        }
    }
    return root;
}


// ANOTHER SOLUTION USING RECURSION PREORDER AND QUEUE
// storing the preorder traversal of the tree in the tree
string serialize(TreeNode* root) {
    if(!root) return "1001 ";
    string result = to_string(root->val).append(" ");
    string leftSerialize = serialize(root->left);
    string rightSerialize = serialize(root->right);
    
    return result.append(leftSerialize).append(rightSerialize);
}

// spliting the root->val in a queue
queue<int> SplitString(string data) {
    int s = 0;
    queue<int> result;
    for(int i=0; i<data.length(); i++) {
        if(data[i] == ' ') {
            result.push(stoi(data.substr(s, i-s)));
            s = i+1;
        }
    }
    return result;
}

// building up the tree using the preorder traversal and queue
TreeNode* deserializeHelper(queue<int>& vals) {
    if(vals.front() == 1001) {
        vals.pop();
        return nullptr;
    }
    TreeNode* root = new TreeNode(vals.front());
    vals.pop();
    root->left = deserializeHelper(vals);
    root->right = deserializeHelper(vals);
    return root;
}
TreeNode* deserialize(string data) {
    queue<int> vals = SplitString(data);
    return deserializeHelper(vals);
}