#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
} TreeNode;

//		15
//    4		20
//  1	  16   25

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root2 = &n6;

TreeNode m1 = {1, NULL, NULL};
TreeNode m2 = {4, &m1, NULL};
TreeNode m3 = {16, NULL, NULL};
TreeNode m4 = {25, NULL, NULL};
TreeNode m5 = {20, &m3, &m4};
TreeNode m6 = {15, &m2, &m5};
TreeNode *root1 = &m6;

// 중위 순회
void inorder_same(TreeNode *root1, TreeNode *root2){
	if(root1 && root2){
		inorder_same(root1 -> left, root2 -> left);
		printf("%d %d\n", root1 -> data, root2 -> data);
		if(root1 -> data != root2 -> data) {printf("False"); exit(0);}
		inorder_same(root1 -> right, root2 -> right);
	}
}

int main(){
	inorder_same(root1, root2);
	printf("True");
}