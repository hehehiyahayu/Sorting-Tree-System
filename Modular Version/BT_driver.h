#ifndef BT_Process_h
#define BT_Process_h
#include "main.h"

//struct node{
//	int data;
//	struct node* left;
//	struct node* right;
//};


void printTab(int numTab);
void processPrint(node* root, int level);
void printTree(node* root);
void DelTree(struct node* root_node);
struct node* newNode(int value);
struct node* insertNode(struct node* srcnode, int value);
void printArray(int arr[], int n);
void heapify(int arr[], int n, int i) ;
void heapSort(int arr[], int n);
void swap(int *a, int *b);
struct node* deleteNode(struct node* root, int key);
struct node* minValueNode(struct node* node);
void setcolor(unsigned short color);

#endif
