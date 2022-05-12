#include <iostream>
#include <stdio.h>
#include "main.h"
#include "BT_driver.h"
#include <windows.h>
using namespace std;


void menu_list(){
	cout << "------------\n";
	cout << "Menu\n";
	cout << "------------\n";
	cout << "1. Insert\n";
	cout << "2. Delete Tree\n";
	cout << "3. Delete Node\n";
	cout << "4. HeapSort\n";
	cout << "\n\n";
	cout << "Tree Data : \n\n";
}

void menu_utama(){
	struct node* root_node = NULL;
	int data = 0;
	int input_user;
	int count = 0;
	int arr[count];		

	BackMenu:
	menu_list();
	printTree(root_node);
	fflush(stdin);
	cout << "\n\nYour Choice : ";		
//	cin >> input_user;	
	scanf("%d",&input_user);
	fflush(stdin);

	if(input_user == 1){
		while(data != 100){
			cout << "Data : ";
			cin >> data ;
			arr[count] = data;
			
			count++;
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
		menu_utama();						
		
	}else if(input_user == 3){		
		fflush(stdin);
		cout << "Data : ";
		cin >> data;
		root_node = deleteNode(root_node, data);
		system("cls");
		setcolor(2);		
		cout << "DELETE NODE " << endl;
		setcolor(7);	
		goto BackMenu;
	}else if(input_user == 4){
//		  int n = sizeof(arr) / sizeof(arr[0]);
		  heapSort(arr, count);
		  setcolor(2);
		  printf("MIN HEAP SORT : ");
		  printArray(arr, count);
		  setcolor(7);
		  system("pause");
		  system("cls");
		  goto BackMenu;
	}else{	
		system("CLS");
		setcolor(4);
		cout << "Invalid Input, Please Retry...\n";
		setcolor(7);
		fflush(stdin);
		goto BackMenu;
	}
}
