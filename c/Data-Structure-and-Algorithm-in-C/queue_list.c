#include <stdlib.h>
#include <stdio.h>
#include "fatal.h"

typedef int ElementType;
struct Node;
struct Queue;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef struct Queue *Qlink;

struct Node
{
    ElementType Element;
    Position    Next;
};

struct Queue
{
    int   size;
    Position head;
    Position rear;
};

int IsEmpty( Qlink q )
{
    return q->size == 0;
}

Qlink createQueue(void){
    Qlink q;
    q = malloc(sizeof( struct Queue ));
    if( q == NULL )
        FatalError( "Out of memory!" );
    q->head = q->rear= NULL;
    q->size = 0;
    return q;
}

void  RPush(ElementType X, Qlink q){
    Position TmpCell;
    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of space!!!" );
    TmpCell->Element = X;
    TmpCell->Next = NULL;
    if (IsEmpty(q))
       q->head =  TmpCell;
    else
       q->rear->Next = TmpCell;
    q->rear = TmpCell;
    q->size ++;
}

ElementType LPop(Qlink q){
    if(IsEmpty(q))
        return 0;
    ElementType x;
    Position top = q->head;
    x = top->Element;
    q->size--;
    if(q->size==0)
        q->rear = NULL;
    else
        q->head=top->Next;
    free(top);
    return x;
}

main(){
    Qlink q;
    int i,j;
    q = createQueue();
    /*
    for(i=1;i<10;i++)
        RPush(i,q);
    for(j = 1;j<5;j++)
        printf("pop Element is %d\n",LPop(q));
    */
    RPush(1,q);
    printf("%d\n",LPop(q));
    printf("%d\n",q->size);
    printf("%d\n",LPop(q));

}
