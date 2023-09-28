/* #pragma once */
#include <iostream>
#include <time.h>

using namespace std;

struct Element {
	int data;
	Element* prev = NULL, *next = NULL;
};

struct Ring {
	Element* current = NULL;
  int length = 0;
};

void pushNext(Ring& r, int data);
void pushPrev(Ring& r, int data);
int pull(Ring& r);
void printRing(const Ring& r);
void clear(Ring& r);
void Next(Ring& r);
void Prev(Ring& r);
void cards(Ring& r); 
int findElement(Ring& r, int data);
void pushToPosition(Ring& r, int data, int position);
