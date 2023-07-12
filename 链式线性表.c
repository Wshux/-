#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct SeqList{
    DataType element;
    struct SeqList* nextnode;
}SeqList;

SeqList* InitSeqList(SeqList* List){    //创建头结点
    List = (SeqList*)malloc(sizeof(SeqList));
    List->nextnode=NULL;
    return List;
}

void AddEle(SeqList* List, DataType element){
    SeqList* Node=List;
    while(Node->nextnode!=NULL){
        Node = Node->nextnode;
    }
    Node->nextnode=(SeqList*)malloc(sizeof(SeqList));
    Node=Node->nextnode;
    Node->nextnode=NULL;
    Node->element=element;
}

void PrintSeqList(SeqList* List){
    SeqList* Node=List;
    Node=Node->nextnode;
    while(Node!=NULL){
        printf("%d ",Node->element);
        Node = Node->nextnode;
    }
}

void DeleteEle(SeqList* List, DataType target){
    SeqList* Node=List->nextnode;
    SeqList* Last=List;
    while(Node->nextnode!=NULL){
        if(Node->element == target){
            Last->nextnode=Node->nextnode;
            free(Node);
            break;
        }
        else{
        	Node=Node->nextnode;
        	Last=Last->nextnode;
		}
    }
}

void InsertEle(SeqList* List, int target, DataType element){
	int i=1;
	SeqList* LastNode=List;
	List=List->nextnode;
	SeqList* NewNode=NULL;
	for(i;i<target;i++){
		if(List->nextnode!=NULL){	//不是表尾 
				LastNode=LastNode->nextnode;
				List=List->nextnode;
		}
		else{						//是表尾 
			break;
		}
	}
	if(i==target){
		NewNode=(SeqList*)malloc(sizeof(SeqList));
		LastNode->nextnode=NewNode;
		NewNode->element=element;
		NewNode->nextnode=List;
	}
}


int main(){
    int i=1;
    SeqList* List;
    List=InitSeqList(List);
    for(i=1; i<10; i++){
        AddEle(List,i);
    }
    SeqList* List111=List->nextnode;
    PrintSeqList(List);
    DeleteEle(List,6);
    printf("\n");
    PrintSeqList(List);
    InsertEle(List,5,999);
    printf("\n");
    PrintSeqList(List);
}