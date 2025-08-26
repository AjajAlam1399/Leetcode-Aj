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
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        if(node->neighbors.size()==0){
            return new Node(node->val);
        }
        unordered_map<Node*,Node*>map;
        return fun(node,map);
    }

    Node* fun(Node * node,unordered_map<Node*,Node*>&map){
        vector<Node*> neighbour;
        Node* clone=new Node(node->val);
        map[node]=clone;
        for(auto adjNode : node->neighbors){
            if(map.find(adjNode)!=map.end()){
                neighbour.push_back(map[adjNode]);
            }
            else{
                neighbour.push_back(fun(adjNode,map));
            }
        }
        clone->neighbors=neighbour;
        return clone;
    }
};