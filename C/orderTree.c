#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct TreeNode {
   int data;
   struct TreeNode *left, *right;
}TreeNode;
typedef TreeNode *element;
typedef struct QueueNode {
   element item;
   struct QueueNode *link;
}QueueNode;
typedef struct {
   QueueNode *front, *rear;
}QueueType;
void error(char *message)
{
   fprintf(stderr, "%s\n", message);
   exit(1);
}
void init(QueueType *q)
{
   q->front = q->rear = NULL;
}
int is_empty(QueueType *q)
{
   return(q->front == NULL);
}
void enqueue(QueueType *q, element item)
{
   QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
   if (temp == NULL)
      error("메모리를 할당할 수 없습니다");
   else {
      temp->item = item;
      temp->link = NULL;
      if (is_empty(q)) {
         q->front = temp;
         q->rear = temp;
      }
      else {
         q->rear->link = temp;
         q->rear = temp;
      }
   }
}
element dequeue(QueueType *q)
{
   QueueNode *temp = q->front;
   element item;
   if (is_empty(q))
      error("큐가 비어 있읍니다");
   else {
      item = temp->item;
      q->front = q->front->link;
      if (q->front == NULL)
         q->rear = NULL;
      free(temp);
      return item;
   }
}
element peek(QueueType *q)
{
   if (is_empty(q))
      error("큐가 비어 있읍니다");
   else {
      return q->front->item;
   }
}
void level_order(TreeNode *ptr)
{

   QueueType q;
   init(&q);
   if (ptr == NULL) return;
   enqueue(&q, ptr);
   while (!is_empty(&q)) {
      ptr = dequeue(&q);
      printf("%d ", ptr->data);
      if (ptr->left)
         enqueue(&q, ptr->left);
      if (ptr->right)
         enqueue(&q, ptr->right);
   }
}
TreeNode n1 = { 13,NULL,NULL };
TreeNode n2 = { 23,&n1,NULL };
TreeNode n3 = { 17,NULL,NULL };
TreeNode n4 = { 32,NULL,NULL };
TreeNode n5 = { 90,&n3,&n4 };
TreeNode n6 = { 100,&n2,&n5 };
TreeNode *root = &n6;
void main()
{
   level_order(root);
}