#include <stdio.h>
#include <stdlib.h>
#include "library.h"

struct tree {
	int data;
	int h;              //height
	struct tree *left;
	struct tree *right;
};

int getData(struct tree *leaf) { return leaf->data; }

void order(struct tree* x)   //Display elements in ascending order
{
    if (!x) return;
    order(x->left);
    printf("%d\n", x->data);
    order(x->right);
}

int hR_sub_hL(struct tree* x)
{
	int hR = 0, hL = 0;
	if (x->right) hR = x->right->h;
	if (x->left) hL = x->left->h;
	return hR - hL;
}

void height(struct tree* x)
{
	int hL = 0, hR = 0;
	if (x->left) hL = x->left->h;
	if (x->right) hR = x->right->h;
	if (hL > hR) x->h = hL + 1;
	else x->h = hR + 1;
}

struct tree * rot_r(struct tree* x)
{
	struct tree* q = x->left;
	x->left = q->right;
	q->right = x;
	height(x);
	height(q);
	return q;
}

struct tree * rot_l(struct tree* x)
{
	struct tree* q = x->right;
	x->right = q->left;
	q->left = x;
	height(x);
	height(q);
	return q;
}

struct tree * balance(struct tree *x)
{
	height(x);
	if (hR_sub_hL(x) == 2)
	{
		if (hR_sub_hL(x->right) < 0)
			x->right = rot_r(x->right);
        return rot_l(x);
	}
	if (hR_sub_hL(x) == -2)
	{
		if (hR_sub_hL(x->left) > 0)
			x->left = rot_l(x->left);
		return rot_r(x);
	}
	return x;
}

void addElement(struct tree** root, int v) {
	if (*root == NULL) {
		*root = (struct tree*)malloc(sizeof(struct tree));
		(*root)->data = v;
		(*root)->h = 1;
        (*root)->right = NULL;
		(*root)->left = NULL;
		printf("Element %d added\n", v);
		return;
	}
	else {
        if (v == (*root)->data){
                printf("Element %d already exists\n", v);                //I've add balancing
	}
	else if (v > (*root)->data){
                addElement(&(*root)->right, v);
                *root = balance(*root);                  //I've add balancing
	}
	else{
                addElement(&(*root)->left, v);
                *root = balance(*root);                  //I've add balancing
	}
	}
	return;
}

struct tree * findElement(struct tree* root, int v) {
	if (getData(root) == v) { printf("Element %d found!\n", v); return root; }
	else if (getData(root) < v && root->right != NULL) return findElement(root->right, v);
	else if (getData(root) > v && root->left != NULL) return findElement(root->left, v);
	else { printf("Element %d not found!\n", v); 	return NULL; }
}

void deleteElement(struct tree** root, int v){
    if (*root == NULL) {
		printf("Element %d not found!\n", v);
	}
	else {
        if (v == (*root)->data && (*root)->left == NULL && (*root)->right == NULL){
                free(*root);
                *root = NULL;
                printf("Element deleted\n");
		}
		else if (v == (*root)->data){
                if(hR_sub_hL >= 0){
                    (*root)->data = (*root)->right->data;
                    deleteElement(&(*root)->right, (*root)->right->data);
                }
                else{
                    (*root)->data = (*root)->left->data;
                    deleteElement(&(*root)->left, (*root)->left->data);
                }
                *root = balance(*root);
		}
		else if (v > (*root)->data){
                deleteElement(&(*root)->right, v);
                *root = balance(*root);                  //I've added balancing
		}
		else if (v < (*root)->data) {
                deleteElement(&(*root)->left, v);
                *root = balance(*root);                  //I've added balancing
		}
	}
	return;
}

void deleteTree(struct tree** root){
    if(*root == NULL) return;
    deleteTree(&(*root)->left);
    deleteTree(&(*root)->right);
    free(*root);
    *root = NULL;
}

