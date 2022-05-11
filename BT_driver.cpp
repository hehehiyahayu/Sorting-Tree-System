#include <iostream>
#include "BT_driver.h"

using namespace std;

void printTab(int numTab){
	for(int i = 0; i < numTab; i++){
		cout << "\t";
	}
}

void processPrint(node* root, int level){
	if(root == NULL){
		printTab(level);
		cout << "---<empty>---" << endl;
		return;
	}
	printTab(level);
	cout << "value = " << root->data << endl;

	printTab(level);
	cout << "left" << endl;
	processPrint(root->left, level + 1);

	printTab(level);
	cout << "right" << endl;
	processPrint(root->right, level + 1);

	printTab(level);
	cout << "done" << endl;
}

void printTree(node* root){
	processPrint(root, 0);
}

void DelTree(struct node* root_node){
  if (root_node == NULL) return;

    /* first delete both subtrees */
    DelTree(root_node->left);
    DelTree(root_node->right);
    /* then delete the node */
//    cout << "\n Deleting node: " << root_node->data<<endl;
    delete root_node;
}

//struct node* search(int PilihanNode){
//	struct no *data = root;
//	while(data!=NULL && data->PilihanNode !=PilihanNode){
//		if(PilihanNode < data->PilihanNode){
//			data = data->left;
//		}else if(PilihanNode > data-PilihanNode){
//			data = data->right;
//		}else{
//			break;
//		}
//	}
//	return data;
//}
//
//void DelNode(int PilihanNode){
//	struct node* data = search(PilihanNode);
//	if(data != NULL){
//		
//	}
//}

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
