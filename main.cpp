#include <iostream>

using namespace std;

struct node{
  int data;
  struct node* left;
  struct node* right;
};

// void insertNode(node ** binary_tree, int value){
//   node* tmp;
//   if(!(*binary_tree)){
//     tmp = (node*)malloc(sizeof(node));
//     tmp->left = tmp->right = NULL;
//     tmp->data = value;
//     *binary_tree = tmp;
//     return;
//   }
//   if(value < (*binary_tree)->data){
//     insertNode
//   }
// }

struct node* newNode(int value){
  struct node* tmp = (struct node*)malloc(sizeof(struct node));
  tmp->data = value;
  tmp->left = tmp->right = NULL;
  return tmp;
}

struct node* insertNode(struct node* srcnode, int value){
  if(srcnode == NULL) return newNode(value);

  if(srcnode->data > value){
    srcnode->left = insertNode(srcnode->left, value);
  }else if(srcnode->data < value){
    srcnode->right = insertNode(srcnode->right, value);
  }

  return srcnode;
}

void printNode(struct node* root_node){
  if(root_node != NULL){
    printNode(root_node->left);
    cout << root_node->data << endl;
    printNode(root_node->right);
  }
}

int main(){
 struct node* root_node = NULL;
 int data = 0;
 // root_node = insertNode(root_node, 10);
 // insertNode(root_node, 20);
 // insertNode(root_node, 30);
 // insertNode(root_node, 25);
 // insertNode(root_node, 36);
 // insertNode(root_node, 56);
 // insertNode(root_node, 78);
 while(data != 100){
   cout << "Data : ";
   cin >> data;

   if(root_node == NULL){
     root_node = insertNode(root_node, data);
   }else{
     insertNode(root_node, data);
   }
 }

 printNode(root_node);
}
