#include "ring.h"

Ring ring;

void LoopRing() {
	int switcher;
	while (true) {
		printf("Choose: \n 1 - push\n 2 - push to position \n 3 - pull \n 4 - next \n 5 - prev \n 6 - find element \n 7 - clear \n 8 - exit \n");
    cin >> switcher;
		int tmp;
    int index;
		switch (switcher) {
		case 1:
			printf("Enter number: "); cin >> tmp;
			printf("Enter 1 - next; 2 - prev\n"); cin >> switcher;
			if (switcher == 1) {
				pushNext(ring, tmp);
			}
			if (switcher == 2) {
				pushPrev(ring, tmp);
			}
			break;
    case 2:
      cout << "Enter number: "; cin >> tmp;
      cout << "Enter index: "; cin >> index;
      pushToPosition(ring, tmp, index);
      break;
		case 3:
			tmp = pull(ring);
			printf("Returned number %d\n", tmp);
			break;
		case 4:
			Next(ring);
			break;
		case 5:
			Prev(ring);
			break;
		case 6:
      cout << "Enter number: ";
      cin >> tmp;
      index = findElement(ring, tmp);
      if (index == -1)
        cout << "Number doesn't found" << endl;
      else 
        cout << "Index = " << index << endl;
			break;
    case 7:
			clear(ring);
      break;
		case 8:
			clear(ring);
			exit(1);
			break;
		}
		printRing(ring);
	}
}

int main() {
	srand(time(NULL));
	LoopRing();
}
