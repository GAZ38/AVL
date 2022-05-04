#ifndef __LIBRARY_H__
#define __LIBRARY_H__

struct tree;

void order(struct tree*);
int hR_sub_hL(struct tree*);
void height(struct tree*);
struct tree* rot_r(struct tree*);
struct tree* rot_l(struct tree*);
struct tree* balance(struct tree*);
void addElement(struct tree**, int);
struct tree* findElement(struct tree*, int);
int getData(struct tree*);
void deleteElement(struct tree**,int);
void deleteTree(struct tree**);
void help();

#endif
