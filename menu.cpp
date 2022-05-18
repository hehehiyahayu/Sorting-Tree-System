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
	int inp;
	int count = 0; //jumlah total array
	int arr[3]={5,8,9};		//array

	BackMenu:
	menu_list();
	printTree(root_node);
//	fflush(stdin); 
			  heapSortAscending(arr, count);
			  setcolor(2);
			  printf("MIN HEAP SORT : ");
			  printArray(arr, count);
			  setcolor(7);
			  heapSortDesending(arr, count);
			  setcolor(2);
			  printf("MAX HEAP SORT : ");
			  printArray(arr, count);
			  setcolor(7);
			  
	cout << "\n\nYour Choice : ";		
	scanf("%d",&inp);
//	fflush(stdin);
 	switch(inp){
 		case 1:
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
			break;
		case 2 :
			system("CLS");
			setcolor(2);		
			cout << "TREE CLEARED !! \n" << endl;
			setcolor(7);		
			data = NULL;
			menu_utama();
			break;
		case 3:
//			fflush(stdin);
			cout << "Data : ";
			cin >> data;
			root_node = deleteNode(root_node, data);
			DeleteArray(arr,data,count);
//			system("cls");
			system("pause");
			setcolor(2);		
			cout << "DELETE NODE " << endl;
			setcolor(7);	
			goto BackMenu;
			break;
		case 5:
			  heapSortDesending(arr, count);
			  setcolor(2);
			  printf("MAX HEAP SORT : ");
			  printArray(arr, count);
			  setcolor(7);
			  system("pause");
			  system("cls");
			  goto BackMenu;
			  break;
		case 4:
			  heapSortAscending(arr, count);
			  setcolor(2);
			  printf("MIN HEAP SORT : ");
			  printArray(arr, count);
			  setcolor(7);
			  system("pause");
			  system("cls");
			  goto BackMenu;
			  break;
		default:
			system("CLS");
			setcolor(4);
			cout << "Invalid Input, Please Retry...\n";
			setcolor(7);
//			fflush(stdin);
			goto BackMenu;	
	 }
}