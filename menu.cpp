#include <iostream>
#include <stdio.h>
#include "main.h"
#include "BT_driver.h"
#include <windows.h>
#include <fstream>
using namespace std;


void menu_list(){
	cout << "------------\n";
	cout << "Menu\n";
	cout << "------------\n";
	cout << "1. Insert\n";
	cout << "2. Delete Tree\n";
	cout << "3. Delete Node\n";
	cout << "4. Min HeapSort\n";
	cout << "5. Max HeapSort\n";
	cout << "6. Check Nilai Tree\n";
	cout << "7. Randomize\n";
	cout << "\n\n";
	cout << "Tree Data : \n\n";
	
}

void menu_utama(){
	struct node* root_node = NULL;
	int data = 0;
	int inp;
	int count = 0; //jumlah total array

	int *arr;		//array
	arr = (int *) malloc(count);
	
	BackMenu:
	menu_list();
	printTree(root_node);
	cout << endl;
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
// 			printf("%d",count);
 			while(data != 100){
			cout << "Data : ";
			cin >> data ;				
			if(checkNode(root_node, data)){
				setcolor(4);
				cout << "Data sudah ada di dalam tree" << endl;
				setcolor(7);
				system("pause");
				system("cls");
				goto BackMenu;
			}else if(data == 0){
				setcolor(4);
				cout << "Data tidak boleh 0" << endl;
				setcolor(7);
				system("pause");
				system("cls");
				fflush(stdin);
				goto BackMenu;
			}else{
			count++;
			arr = (int *) realloc(arr, count);
			arr[count-1] = data;		
				if(root_node == NULL){
					root_node = insertNode(root_node, data);
				}else{
					insertNode(root_node, data);
				}
				system("CLS");
				goto BackMenu;
			}
		}
			break;
		case 2 :
			system("CLS");
			setcolor(2);		
			cout << "TREE CLEARED !! \n" << endl;
			setcolor(7);		
			data = 0;
			menu_utama();
			break;
		case 3:	
			cout << "Data : ";
			cin >> data;
			if(checkNode(root_node, data)){
				root_node = deleteNode(root_node, data);
				DeleteArray(arr,data,count);
				system("cls");				
				setcolor(2);		
				cout << "DELETE NODE " << endl;
				setcolor(7);	
				count--;
				goto BackMenu;
				break;
			}else{
				setcolor(4);
				cout << "Data tidak ada di dalam tree" << endl;
				setcolor(7);
				system("pause");
				system("cls");
				goto BackMenu;
			}

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
		case 6:

		cout << "Data : ";
			cin >> data;
			if(checkNode(root_node, data)){
				setcolor(2);
				cout << "Data ada di dalam Tree\n";
				setcolor(7);
			}else{
				setcolor(4);
				cout << "Data tidak ada di dalam Tree\n";
				setcolor(7);
			}
			system("pause");
			system("cls");
			goto BackMenu;
			break;
		case 7:{			
			int num;
			if(root_node != NULL){
				setcolor(4);
				cout << "Tree harus di kosongkan terlebih dahulu untuk melakukan randomize" << endl;
				setcolor(7);
				system("PAUSE");
				system("CLS");
				goto BackMenu;
			}else{
				randomize();
			
				ifstream myFile("temp.txt");
				if(myFile.is_open()){
					while(myFile >> num){	
						count++;				
						arr = (int *) realloc(arr, count);
						arr[count-1] = num;
						root_node = insertNode(root_node, arr[count-1]);
	
					}
				}else{
					cout << "Tidak bisa membuka file" << endl;
					system("PAUSE");
				}
				
				system("pause");
				system("cls");
				goto BackMenu;
			}

		}
			break;
		default:
			system("CLS");
			setcolor(4);
			cout << "Invalid Input, Please Retry...\n";
			setcolor(7);
			fflush(stdin);
			goto BackMenu;	
	 }
}
