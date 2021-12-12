#include <stdio.h>
#include <stdlib.h>
// 818 367 51 232 541 180 763 835 413 802 373 4 267 265 352 840 532 78 335 60

typedef struct treeNode {
struct treeNode * left;
int key;
struct treeNode * right;
} tree;

tree* addNode(tree*, int);
tree * createTreeNode(int);

  int countLeafNode(tree** root) {
    if (*root == NULL)
    return 0;
    if ((*root) -> left == NULL && (*root) -> right == NULL) 
    return 1;
    return countLeafNode(&((*root)->left))+countLeafNode(&((*root)->right));
    }
 
  
  




void freeTree(tree** root) {
	if (*root != NULL) {
		freeTree(&((*root)->left));
		freeTree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}

void preorder(tree*root) {
    if (root != NULL) {
      printf("%d\n", root->key);
      preorder(root->left);
      preorder(root->right);
    } 
}
void inorder(tree*root) {
    if (root != NULL) {
      inorder(root->left);
      printf("%d\n", root->key);
      inorder(root->right);
      
    } 
}
void postorder(tree*root) {
    if (root != NULL) {
      postorder(root->left);
      postorder(root->right);
      printf("%d\n", root->key);
      
    }
}

int height(tree* node) {
  if (node == NULL)
    return 0;
  else {
    int lheight = height(node -> left);
    int rheight = height(node -> right);
    if (lheight > rheight)
      return (lheight + 1);
    else return (rheight + 1);
  }
}
void CurrentLevel(tree* root, int level) {
  if (root == NULL)
    return;
  if (level == 1)
    printf("%d ", root ->key);
  else if (level > 1) {
    CurrentLevel(root -> left, level - 1);
    CurrentLevel(root -> right, level - 1);
  }
}

void levelOrder(tree* root) {

  int h = height(root);
  int i;
  for (i = 1; i <= h; i++)
    CurrentLevel(root, i);
}


int main(int argc, char const *argv[]) {
  tree * root = NULL;
  root = addNode(root, 818);
  root = addNode(root, 367);
  root = addNode(root, 51);
  root = addNode(root, 232);
  root = addNode(root, 541);
  root = addNode(root, 180);
  root = addNode(root, 763);
  root = addNode(root, 835);
  root = addNode(root, 413);
  root = addNode(root, 802);
  root = addNode(root, 373);
  root = addNode(root, 4);
  root = addNode(root, 267);
  root = addNode(root, 265);
  root = addNode(root, 352);
  root = addNode(root, 840);
  root = addNode(root, 532);
  root = addNode(root, 78);
  root = addNode(root, 335);
  root = addNode(root, 60);

  countLeafNode(&root);
  printf("Quantity of leafs : %d \n", countLeafNode(&root));
  
  printf("===========preorder==============\n");
  preorder(root);
  printf("=================================\n");
  printf("===========inorder===============\n");
  inorder(root);
  printf("=================================\n");
  printf("===========postorder=============\n");
  postorder(root);
  printf("=================================\n");
  printf("==========levelOrder=============\n");
  levelOrder(root);
  printf("\n=================================\n");

  freeTree(&root);
  printf("freeTree:\n");

  printf("===========preorder==============\n");
  preorder(root);
  printf("=================================\n");
  printf("===========inorder===============\n");
  inorder(root);
  printf("=================================\n");
  printf("===========postorder=============\n");
  postorder(root);
  printf("=================================\n");
  printf("==========levelOrder=============\n");
  return 0;
}


tree* addNode(tree* root, int key) {
  if(root == NULL) {
    root = createTreeNode(key);
  } else {
      if (root->key > key) {
          root->left = addNode(root->left, key);
      } else {
          root->right = addNode(root->right, key);
      }
      }

  
  
  return root;

}

tree * createTreeNode(int key) {
  tree * newTreeNode = (tree*) malloc (sizeof(tree));
  if (newTreeNode == NULL) {
    printf("out of memory :\n");
    exit(1);
  }
  newTreeNode->key = key;
  newTreeNode->left = NULL;
  newTreeNode->right = NULL;
  return newTreeNode;
}
 


