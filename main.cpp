#include <iostream>
#include "Header.h"

using namespace std;

void PrintNode(struct node* root_node){
  if(root_node != NULL){
    PrintNode(root_node->left);
    cout << root_node->data << endl;
    PrintNode(root_node->right);
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

 PrintNode(root_node);
}