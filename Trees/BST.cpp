#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BST{
   

    public:
        Node* root;
        BST(int data){
            this->root = new Node(data);   
        }

        void insert(int data){
            this->root = insert(this->root,data);
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
        Node* insert(Node* node,int data){
            if(node == NULL){
                node = new Node(data);
                return node;
            }
            if(data > node->data){
                node->right = insert(node->right,data);
            }
            if(data < node->data){
                node->left = insert(node->left,data);
            }
            return node;
        }
};
int main(){
    BST* bst = new BST(10);
    bst->insert(5);
    bst->insert(15);
    bst->insert(3);
    bst->insert(7);
    bst->insert(12);
    bst->insert(18);
    bst->levelOrder(bst->root);
}