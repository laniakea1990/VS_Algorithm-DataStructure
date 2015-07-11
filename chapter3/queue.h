/*************************************************************************
> File Name: queue.h
> Author: ma6174
> Mail: ma6174@163.com
> Created Time: Wed 19 Nov 2014 07:17:19 PM PST
************************************************************************/

#ifndef _Queue_h

struct QueueRecord;
typedef struct QueueRecord* Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
void Dequeue(Queue Q);
ElementType Front(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif /* _Queue_h */

/* Place int implementation file */
/* Queue implementation is a dynamically allocated array */
