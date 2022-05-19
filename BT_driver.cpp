#include <iostream>
#include "BT_driver.h"
#include <windows.h>
#include <stdio.h>

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


// Function to swap the the position of two elements
void swap(int *a, int *b) {

  int temp = *a;

  *a = *b;

  *b = temp;
}
void heapifyAscending(int arr[], int n, int i) {
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapifyAscending(arr, n, largest);
  }
}

// Main function to do heap sort

void heapSortAscending(int arr[], int n) {
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapifyAscending(arr, n, i);
  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);
    // Heapify root element to get highest element at root again
    heapifyAscending(arr, i, 0);
  }

}

void DeleteArray(int *arr,int data,int count){
		int *arr_tmp;
		arr_tmp = (int *) malloc(count);		
		for(int c = 0;c<count;c++){
			arr_tmp[c] = arr[c];
		}
	
			arr = (int *) realloc(arr, count);
	 for(int i=0;i<count;i++){
	    	if(arr_tmp[i] == data){			        
	    				
				        for(int c = i; c < count-1; c++){
				        arr[c] = arr_tmp[c+1];							    	
						}
						count--;				        
			}else{
				printf("");			
			}
		}       
}

void heapifyDesending(int arr[], int n, int i){
    int smallest = i; // Initialize smalles as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is smaller than root
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
 
    // If right child is smaller than smallest so far
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
 
    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
 
        // Recursively heapify the affected sub-tree
        heapifyDesending(arr, n, smallest);
    }
}

void heapSortDesending(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyDesending(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call min heapify on the reduced heap
        heapifyDesending(arr, i, 0);
    }
}
 



//for printing the array

void printArray(int *arr, int count) {

  for (int i = 0; i < count; i++){
  	printf("%d ", arr[i]);
  }

  printf("\n");

}

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


bool checkNode(struct node *root, int key){
	if(root == NULL) return false;
	
	if(root->data == key) return true;
	
	bool res1 = checkNode(root->left, key);
	
	if(res1) return true;
	
	bool res2 = checkNode(root->right, key);
	
	return res2;
}

void setcolor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}
