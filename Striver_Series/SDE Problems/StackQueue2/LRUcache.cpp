#include<bits/stdc++.h>
using namespace std;

// T.c O(1)
class LRUCache {
public:
    class Node{
        public:
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int val){
            key = k;
            value = val;
            prev = this;
            next = this;
        }
    };
    int maxCapacity = 0; 
    int size = 0;        // maintain the current size
    Node* head = nullptr;           // head of Doubly linked list
    unordered_map<int, Node*> NodeAddress;           // Hashtable contains the key and its Nodeaddress in doubly linked list
    
    // constructor
    LRUCache(int capacity) {             
        maxCapacity = capacity;
    }
    // remove any node with given address from DLL
    void RemoveNode(Node* NodeAdd) {
        if(NodeAdd->next == NodeAdd) {         // one node case
            head = nullptr;
        }
        else if(head == NodeAdd) {            // first Node case
            Node* lastNode = head->prev;
            head = head->next;
            head->prev = lastNode;
            lastNode->next = head;
        }else {
            Node* next_node = NodeAdd->next;
            Node* prev_node = NodeAdd->prev;
            
            prev_node->next = next_node;
            next_node->prev = prev_node;
        }
        delete(NodeAdd);
        size--;
    }

    // adding New node to front of the DLL
    void AddFront(int key, int value) {
        Node* newNode = new Node(key, value);
        if(head == nullptr) {
            head = newNode;
        }else {
            Node* lastNode = head->prev;
            Node* firstNode = head;
        
            newNode->next = firstNode;
            firstNode->prev = newNode;
            lastNode->next = newNode;
            newNode->prev = lastNode;
            head = newNode;
        }
        size++;
        return;        
    }
    int get(int key) {
        // checking whether the key exists in our hastable or not?
        if(NodeAddress.count(key)) {
            // key present, their now adding that node in front of DLL and return the value
            int val = NodeAddress[key]->value;
            RemoveNode(NodeAddress[key]);
            NodeAddress.erase(key);
            AddFront(key, val);
            NodeAddress[key] = head;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if given key is already present in our DLL or hashtable then updating the existed node.
        if(NodeAddress.count(key)) {
            RemoveNode(NodeAddress[key]);
            NodeAddress.erase(key);
        }
        else if(size == maxCapacity) {
            Node* lastNode = head->prev;
            int willRemove = lastNode->key;
            RemoveNode(lastNode);
            NodeAddress.erase(willRemove);
        }
        
        AddFront(key, value);
        NodeAddress[key] = head;
    }
};