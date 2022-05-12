#include <iostream>
#include "main.h"
#include "BT_driver.h"

using namespace std;

struct node* minValueNode(struct node* node){
	struct node* current = node;
	
	while(current && current->left != NULL){
		current = current->left;
	}
	
	return current;
}

struct node* deleteNode(struct node* root, int key){
	if(root == NULL) return root;
	
	if(key < root->data){
		root->left = deleteNode(root->left, key);
	}else if(key > root->data){
		root->right = deleteNode(root->right, key);
	}else {
		if(root->left == NULL){
			struct node* temp = root->right;
			free(root);
			return temp;
		}else if(root->right == NULL){
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		
		struct node* temp = minValueNode(root->right);
		
		root->data = temp->data;
		
		root->right = deleteNode(root->right, temp->data);
	}	
	return root;
}

void menu_list(){
	cout << "Menu\n";
	cout << "------------\n";
	cout << "1. Insert Node\n";
	cout << "2. Delete Node\n";
	cout << "3. Delete Tree\n";
	cout << "\n\n";
	cout << "Tree Data : \n\n";
}

void menu_utama(){
	struct node* root_node = NULL;
	int data = 0;
	int input_user;

	BackMenu:
	system("CLS");
	menu_list();
	printTree(root_node);
	cout << "\n\nYour Choice : ";
	cin >> input_user;

	if(input_user == 1){
		while(data != 100){
			fflush(stdin);
			cout << "Data : ";
			cin >> data;

			if(root_node == NULL){
				root_node = insertNode(root_node, data);
			}else{
				insertNode(root_node, data);
			}
			goto BackMenu;
		}
	}else if(input_user == 2){
		fflush(stdin);
		cout << "Data : ";
		cin >> data;
		root_node = deleteNode(root_node, data);
		goto BackMenu;
	}else if(input_user == 3){
		system("CLS");
		DelNode(root_node);
		data = NULL;
		cout << data << endl;
	}else{
		system("CLS");
		cout << "Invalid Input, Please Retry...\n";
		menu_utama();
	}
}
