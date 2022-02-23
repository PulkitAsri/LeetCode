/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

*/

class Solution {
    //prevNode newNode
    map<Node*, Node*> mp;
public:
    Node* solve(Node* node){
        
        //base case
        if(node==NULL) return NULL;
        
        // handling repeat cases and not calling it further
        // so returning it (avoid infinite calls)
        if(mp[node]) return mp[node];
        
        //first process node => node cloning
        Node* newNode= new Node(node->val);
        mp[node]=newNode;
        
        //call every neighbour
        for(auto &eachNode: node->neighbors){
            //edge cloning
            newNode->neighbors.push_back(solve(eachNode)); 
        }
        
        return newNode;   
    }
    
    Node* cloneGraph(Node* node) {
        return solve(node);
    }
};