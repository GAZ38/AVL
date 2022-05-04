#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

void help(){
	printf("\nFunctions that can be used:\norder\naddElement\nfindElement\ndeleteElement\ndeleteTree\nstop\n");
}

int main() {
	struct tree* root = NULL;
	char s[20];
	char ord[6]="order",sub[10]="hR_sub_hL",add[11]="addElement",find[12]="findElement",delE[14]="deleteElement",delT[11]="deleteTree",hp[5]="help",stop[5]="stop";
	int elem;
	while(scanf("%s",s)!=EOF){
	if(strcmp(s,ord)==0){
		printf("Tree elements in ascending order:\n");
		order(root);
	}
	else if(strcmp(s,sub)==0){
		printf("The height difference of the subtrees is:\n");
		printf("%d",hR_sub_hL(root));
	}
	else if(strcmp(s,add)==0){
		scanf("%d",&elem);
		addElement(&root,elem);
	}
	else if(strcmp(s,find)==0){
		scanf("%d",&elem);
		findElement(root,elem);
	}
	else if(strcmp(s,delE)==0){
		scanf("%d",&elem);
		deleteElement(&root,elem);
	}
	else if(strcmp(s,delT)==0)deleteTree(&root);
	else if(strcmp(s,stop)==0) return 0;
	else if(strcmp(s,hp)==0)help();
	else help();
	}
	return 0;
}
