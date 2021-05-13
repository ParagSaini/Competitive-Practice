
string traverse(Node* root, unordered_map<string, pair<int, int>>& m) {
    string s;
    if(root == nullptr) return s;
    string sl = traverse(root->left, m);
    string sr = traverse(root->right, m);
    s = sl + to_string(root->data) + sr;
    if(m.count(s)) {
        m[s].second++;
    } else {
        m[s] = {root->data, 1};
    }
    return s;
}
void printAllDups(Node* root)
{
    unordered_map<string, pair<int, int>> m;
    traverse(root, m);
    
    priority_queue<int, vector<int>, greater<int>> q;
    for(auto i : m) {
        if(i.second.second > 1) {
            q.push(i.second.first);
        }
    }
    if(q.empty()) {
        cout<<-1<<" ";
        return;
    }
    while(q.size()) {
        cout<<q.top()<<" ";
        q.pop();
    }
    
    
}