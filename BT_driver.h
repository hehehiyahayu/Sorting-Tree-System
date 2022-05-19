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
void printArray(int *arr, int n);
void heapifyAscending(int arr[], int n, int i) ;
void heapSortAscending(int arr[], int n);
void heapSortDesending(int arr[], int n);
void heapifyDesending(int arr[], int n, int i);
void swap(int *a, int *b);

void DeleteArray(int *arr,int data,int count);


struct node* deleteNode(struct node* root, int key);
struct node* minValueNode(struct node* node);
void setcolor(unsigned short color);
bool checkNode(struct node *root, int key);

#endif
