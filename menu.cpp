#include <iostream>
#include "main.h"
#include "BT_driver.h"
#include <windows.h>
using namespace std;

void setcolor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

void menu_list(){
	cout << "------------\n";
	cout << "Menu\n";
	cout << "------------\n";
	cout << "1. Insert\n";
	cout << "2. Delete Tree\n";
	cout << "2. Delete Node\n";
	cout << "\n\n";
	cout << "Tree Data : \n\n";
}

void menu_utama(){
	struct node* root_node = NULL;
	int data = 0;
	int input_user;

	BackMenu:	
	menu_list();
	printTree(root_node);
	cout << "\n\nYour Choice : ";
	cin >> input_user;

	if(input_user == 1){
		while(data != 100){
			cout << "Data : ";
			cin >> data;

			if(root_node == NULL){
				root_node = insertNode(root_node, data);
			}else{
				insertNode(root_node, data);
			}
			system("CLS");
			goto BackMenu;
		}
	}else if(input_user == 2){
		system("CLS");
		setcolor(2);		
		cout << "TREE CLEARED !! \n" << endl;
		setcolor(7);		
		data = NULL;
//		cout << data << endl;
		menu_utama();
	}else if(input_user == 3){
//		system("CLS");
//		DelNode(root_node);
//		data = NULL;
//		cout << data << endl;
//		menu_utama();
		cout << "Jalan" << endl;
	}else{	
		system("CLS");
		cout << "Invalid Input, Please Retry...\n";
		menu_utama();
	}
}
