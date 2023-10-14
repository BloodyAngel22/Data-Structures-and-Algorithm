#include "ring.h"

void pushNext(Ring& r, int data) {
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = data;
	
	if (r.current == NULL) {
		r.current = e;
		e->next = e->prev = e;
	}
	else {
		e->next = r.current->next;
		e->prev= r.current;
		r.current->next->prev = e;
		r.current->next = e;
	}
  r.length++;
}

void pushPrev(Ring& r, int data) {
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = data;

	if (r.current == NULL) {
		r.current = e;
		e->next = e->prev = e;
	}
	else {
		e->next = r.current;
		e->prev = r.current->prev;
		r.current->prev->next = e;
		r.current->prev = e;
	}
  r.length++;
}

int pull(Ring& r) {
	if (r.current == NULL) return 0;

	int d = r.current->data;
	Element* e = r.current;

	if (r.current->next == r.current) {
		r.current = NULL;
	}
	else {
		r.current->prev->next = r.current->next;
		r.current->next->prev = r.current->prev;
		r.current = r.current->next;
	}
	free(e);
  r.length--;
	return d;
}

void clear(Ring& r) {
	if (r.current == NULL) return;

	while (r.current != NULL) {
		Element* e = r.current;

		if (r.current->next == r.current) {
			r.current = NULL;
		}
		else {
			r.current->prev->next = r.current->next;
			r.current->next->prev = r.current->prev;
			r.current = r.current->next;
		}
		free(e);
	}
  r.length = 0;
}

void printRing(const Ring& r) {
	if (r.current == NULL) return;

	printf("%d", r.current->data);
	for (Element* cur = r.current->next; cur != r.current; cur = cur->next)
		printf(" <-> %d", cur->data);
	printf("\n");
}

void Next(Ring& r) {
	if (r.current == NULL) return;

	r.current = r.current->next;
}

void Prev(Ring& r) {
	if (r.current == NULL) return;

	r.current = r.current->prev;
}

int findElement(Ring& r, int data){
  if (r.current == NULL) return -1;
  int index = 0;
  if (data == r.current->data)
    return index;
  for (Element* cur = r.current->next; cur != r.current; cur = cur->next){
    index++;
    if (cur->data == data)
      return index;
  }

  return -1;
}

void pushToPosition(Ring& r, int data, int position){
  if (position > r.length){
    cout << "position > lenght ring" << endl;
    return;
  }
  if (position < 0){
    cout << "position < 0" << endl;
    return;
  }
  
  if (position == 0){
    pushPrev(r, data);
    Prev(r);
  }
  if (position == 1){
    pushNext(r,data);
  }
  if (position > 1){
    int index = 2;
    for (Element* cur = r.current->next; cur != r.current; cur = cur->next){
      if (index == position){
        Element* e = (Element*)malloc(sizeof(Element));
        e->data = data;
        e->next = cur->next;
        e->prev= cur;
        cur->next->prev = e;
        cur->next = e;
        r.length++;
        return;
      }
      index++;
    }
  }
}
