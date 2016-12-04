/*
 (11,LL)(7,LLL)(8,R)(5,)(4,L)(13,RL)(2,LLR)(1,RRR)(4,RR)()
 (3,L)(4,R)()
 
 
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h> 
#include <queue>
using namespace std;

typedef struct node{
	int value;
	struct node *left,*right;
}Node;


Node *create_node();
void append_node(Node *root,char *option);
void create_tree(Node *root,char *position,int value);
void enqueue_tree(Node *root,queue<Node *> *que);

int main()
{
	char s[3000];
	scanf("%s",s);

	Node *root=create_node();

	append_node(root,s);
	
	queue<Node *> q;
	enqueue_tree(root,&q);

	while(!q.empty())
	{
		printf("%d ",((Node *)(q.front()))->value);
		q.pop();
	}
	
	int program_end;
	scanf("%d",&program_end);
	return 0;
}

Node *create_node()
{
	Node *n=(Node *)malloc(sizeof(Node));
	if(n!=NULL)
	{
		n->value=-1;
		n->left=n->right=NULL;
	}
	return n;
}

void append_node(Node *root,char *option)
{
	int value;

	for(int i=0;option[i]!='\0';i++)
	{
		if(option[i]=='(' && option[i+1]==')') return;

		if(option[i]=='(') sscanf(&option[i+1],"%d",&value);

		if(option[i]==',') 
		{
			if(option[i+1]==')') root->value=value;
			else create_tree(root,&option[i+1],value);
		}
	}
	
}

void create_tree(Node *root,char *position,int value)
{
	if(position[0]==')') return;

	if(position[0]=='L') 
	{
		if(root->left==NULL) root->left=create_node();
		if(position[1]==')') root->left->value=value;
		create_tree(root->left,&position[1],value);
	}
	else if(position[0]=='R')
	{
		if(root->right==NULL) root->right=create_node();
		if(position[1]==')') root->right->value=value;
		create_tree(root->right,&position[1],value);
	}
}

void enqueue_tree(Node *root,queue<Node *> *que)
{
	queue<Node *> temp;

	temp.push(root);
	(*que).push(root);

	while(!temp.empty())
	{
		Node *l=(temp.front())->left,*r=(temp.front())->right;
		if(l!=NULL){ temp.push(l);(*que).push(l);}
		if(r!=NULL){ temp.push(r);(*que).push(r);}

		temp.pop();
	}
}