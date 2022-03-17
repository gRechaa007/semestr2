#pragma once

#include <stdbool.h>
#include <stddef.H>

struct Point {
	int x;
	int y;
};

struct Stack {
	Point* 
};

typedef struct Point Point;
typedef struct Stack Stack;

Stack* stackNew(void);
void stackDelete(Stack*);

errno_t stackPush(Stack*, Point*);
errno_t stackPop(Stack*);

Point stackTop(Stack*);

bool stackIsEmpty(Stack*);