#ifndef BT_Process_h
#define BT_Process_h

struct node{
	int data;
	struct node* left;
	struct node* right;
};

void printTab(int numTab);
void processPrint(node* root, int level);
void printTree(node* root);
void DelNode(struct node* root_node);
struct node* newNode(int value);
struct node* insertNode(struct node* srcnode, int value);

#endif
