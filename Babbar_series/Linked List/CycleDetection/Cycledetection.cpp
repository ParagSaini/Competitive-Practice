#include<bits/stdc++.h>
using namespace std;

// return true if it contains the cycle, otherwise return false.
bool has_cycle(SinglyLinkedListNode* head) {

/* Logic : While traversing the linked list storing the address of each node in a set 'address_of_node', and on each node check whether 
or not address of that node is already present in the set or not, if present means their is a cycle. 
NOTE : we use address here not the node->data, because address is unique, but node data may be repeated.
*/
    unordered_set<SinglyLinkedListNode*> address_of_node;  
    SinglyLinkedListNode* start = head;
    while(start != nullptr)    // traversing the linked list.
    {
        if(address_of_node.count(start))  // checking the address of current node is present in set or not.
            return true;
        address_of_node.insert(start);    // if not present, we add it to our set.
        start = start->next;              // next node.
    }
    return false;              // after travesing the linked list if no address is repeating, return false, no cycle in the linked list.

}