#include <iostream>
#include "Header.h"

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

void DelNode(struct node* root_node){
  if (root_node == NULL) return;

    /* first delete both subtrees */
    DelNode(root_node->left);
    DelNode(root_node->right);

    /* then delete the node */
    cout << "\n Deleting node: " << root_node->data<<endl;
    delete root_node;
}


int main(){
 struct node* root_node = NULL;
 int data = 0;
 int inputuser;
 // root_node = insertNode(root_node, 10);
 // insertNode(root_node, 20);
 // insertNode(root_node, 30);
 // insertNode(root_node, 25);
 // insertNode(root_node, 36);
 // insertNode(root_node, 56);
 // insertNode(root_node, 78);
 BackMenu:
 cout << "MENU \n";
 cout << "-------- \n";
 cout << " 1. Insert \n";
 cout << " 2. Delete \n";
 cout << " Tree Data :  " << endl << endl;
 printTree(root_node);
 cout << "\n\n Your Choice : ";
 cin >> inputuser;

 if(inputuser == 1){
 	while(data != 100){
   	cout << "Data : ";
   	cin >> data;

   	if(root_node == NULL){
      root_node = insertNode(root_node, data);
   	}else{
      insertNode(root_node, data);
    }
    goto BackMenu;
 	}
 }else if(inputuser == 2){
 	system("cls");
 	DelNode(root_node);
	data = NULL;
	cout << data <<endl;

 }else{
 	system("cls");
 	cout << "Invalid Input, Please Retry...\n";
 	main();
 }

}
