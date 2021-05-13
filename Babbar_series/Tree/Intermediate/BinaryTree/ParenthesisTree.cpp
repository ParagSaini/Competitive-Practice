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

int findLeftIndex(string str, int s, int e) {
    stack<char> st;

    for(int i=s; i<=e; i++) {
        if(str[i] == '(') {
            st.push(str[i]);
        }else if(str[i] == ')') {
            st.pop();
            if(st.empty()) {
                return i;
            }
        }
    }
    return -1;

}
Node* buildTree(string str, int s, int e) {
    if(s > e) return nullptr;
    if(s == e) {
        Node* node = new Node(str[s]-'0');
        return node;
    }

    Node* root = new Node(str[s] - '0');
    int ind = findLeftIndex(str, s, e);

    root->left = buildTree(str, s+2, ind-1);
    root->right = buildTree(str, ind+2, e-1);

    return root;
}
void preorder(Node* root) {
    if(root == nullptr) return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    string s = "1(2)(3(4)(5))";
    Node* root = buildTree(s, 0, s.length()-1);
    preorder(root);
    return 0;    
}