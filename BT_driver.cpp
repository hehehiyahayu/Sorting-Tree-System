#include <iostream>
#include "BT_driver.h"
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




// Function to swap the the position of two elements
void swap(int *a, int *b) {

  int temp = *a;

  *a = *b;

  *b = temp;

}

void heapify(int arr[], int n, int i) {

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

    heapify(arr, n, largest);

  }

}

// Main function to do heap sort

void heapSort(int arr[], int n) {

  // Build max heap

  for (int i = n / 2 - 1; i >= 0; i--)

    heapify(arr, n, i);

  // Heap sort

  for (int i = n - 1; i >= 0; i--) {

    swap(&arr[0], &arr[i]);

    // Heapify root element to get highest element at root again

    heapify(arr, i, 0);

  }

}

//for printing the array

void printArray(int arr[], int count) {

  for (int i = 0; i < count; i++)

    printf("%d ", arr[i]);

  printf("\n");

}




