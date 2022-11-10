#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

int main()
{
	int array[5], buffer[5];
	char ch = ' '; 
	int size = 0, buff = 0, digits = 0, no_equal = 0;
	int bulls = 0, cows = 0;

	setlocale(LC_ALL, "Rus");
	do {
		printf("Enter digit number (from 2 to 5): ");
		scanf_s("%d", &size);
	} while (size < 2 || size > 5);

	srand((unsigned int)time(NULL));
	array[0] = 1 + rand() % 9;
//	printf("%d\n", array[0]);
	digits++;
	while (digits < size) {
		buff = rand() % 10;
//		printf("buff=%d, digits=%d\n", buff, digits);
		no_equal = digits;
		for(int i = 0; i < digits; i++)
			if (buff != array[i]) no_equal--;
		if (no_equal == 0) {
			array[digits] = buff;
			digits++;
		}
	}
	for(int i = 0; i < size; i++)
 	    printf("%d", array[i]);
	printf("\n");

	digits = no_equal =  0;
	printf("Enter %d digits or q for exit: \n", size);
	while (ch != 'q' && ch != 'Q') {
		ch = _getch();
		if (isdigit(ch)) {
			buff = (int)(ch - 48);
			if (digits == 0 && buff == 0)
				continue;
			buffer[digits] = buff;
			no_equal = digits;
			for (int i = 0; i < digits; i++)
				if (buff != buffer[i]) no_equal--;
			if (no_equal == 0) {
				printf("%d", buff);
				for (int i = 0; i < size; i++)
					if (array[i] == buff)
						if (i == digits)
							bulls++;
						else
							cows++;
				digits++;
				if (digits == size) {
					printf("\tbulls = %d, cows = %d\n", bulls, cows);
					if (bulls == size) {
						printf("YOU WON!");
						break;
					}
					digits = bulls = cows = 0;
				}
			}
		}
	}
	return 0;
}