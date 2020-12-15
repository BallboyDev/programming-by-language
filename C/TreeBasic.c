// 링크 표현법으로 생성된 이진 트리

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef sturct TreeNode{
	int data;
	struct TreeNode *left, *rigth;
} TreeNOde;
// 생성 트리 구조
//		n1
//     / |
//	  n2 n3

int main(){
	TreeNOde *n1, *n2, *n3;
	n1 = (TreeNOde *)malloc(sizeof(TreeNode));
	n2 = (TreeNOde *)malloc(sizeof(TreeNode));
	n3 = (TreeNOde *)malloc(sizeof(TreeNode));
	n1 -> data = 10;
	n1 -> left = n2;
	n1 -> rigth = n3;	// 첫번째 노드의 설정
	
	n2 -> data = 20;
	n2 -> left = NULL;
	n2 -> rigth = NULL;	// 두번째 노드의 설정
	
	n3 -> data = 30;
	n3 -> left = NULL;
	n3 -> rigth = NULL;	// 세번쨰 노드의 설정
}