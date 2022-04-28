#ifndef Header_h
#define Header_h 

struct node{
  int data;
  struct node* left;
  struct node* right;
};

// void insertNode(node ** binary_tree, int value){
//   node* tmp;
//   if(!(*binary_tree)){
//     tmp = (node*)malloc(sizeof(node));
//     tmp->left = tmp->right = NULL;
//     tmp->data = value;
//     *binary_tree = tmp;
//     return;
//   }
//   if(value < (*binary_tree)->data){
//     insertNode
//   }
// }

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

//void PrintNode(struct node* root_node);
void DelNode(struct node* root_node);
int Menu();


#endif