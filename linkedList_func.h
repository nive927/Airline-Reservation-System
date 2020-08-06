#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

typedef struct Node
{
	struct flight flight;

	struct Node* next;

} node;

typedef node linkedList;

node* create()
{
	node* hd;
	hd=malloc(sizeof(node));
	hd->next=NULL;
	return hd;
}

void ins_end(struct flight f, node* hd)
{
	node* t;
	t=hd;
	while(t->next!=NULL)
	{
		t=t->next;
	}

	node* new=malloc(sizeof(node));
	new->flight=f;
	new->next=NULL;
	t->next=new;
	
}