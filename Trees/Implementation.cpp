#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};


class Tree{
    public:
        Node* root;
    
        Tree(){
            root = NULL;
        }

        void insert(int val){
            this->root = new Node(val);
            populate(this->root);
        }

        void levelOrder(Node* node){
            if(node == NULL) return;
            queue<Node*> q;
            q.push(node);
            while(!q.empty()){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    Node* curr = q.front();
                    q.pop();
                    cout << curr->data << " ";
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                cout << endl;
            }
        }

        private: 
            void populate(Node* node){
                cout << "Do you want to add a left child" << endl;
                string left;
                cin >> left;
                if(left == "yes"){
                    cout << "Enter the value of the left child" << endl;
                    int val;
                    cin >> val;
                    node->left = new Node(val);
                    populate(node->left);
                }else{
                    node->left = NULL;
                }
                cout << "Do you want to add a right child" << endl;
                string right;
                cin >> right;
                if(right == "yes"){
                    cout << "Enter the value of the right child" << endl;
                    int val;
                    cin >> val;
                    node->right = new Node(val);
                    populate(node->right);
                }
                else{
                    node->right = NULL;
                }


            }
        

    
};

int main(){
    Tree* t = new Tree();
    t->insert(15);
    t->levelOrder(t->root);
}