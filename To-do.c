#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char note[15][255];
int a = 0;

void allList()
{
	int i;
	printf(" All List: \n");

	if (a == 0)
	{
		printf("\n ---- Nothing to do ---- \n");
	}
	for (i =  1; i <= a; i++)
	{
		printf(" %d) %s\n", i, note[i]);
	}
}
void add()
{
	system("cls");
	printf(" New Task\n\n");
	printf(" What is to be done?\n");
	printf("   >> ");
	fgets(note[a], 255, stdin);
	note[a][strlen(note[a]) - 1] = 0;
	if (strlen(note[a]) > 255)
	{
		while (getchar() != '\n');
	}
}
void rem()
{
	int j, position;
	printf(" Enter the number you want to remove: ");
	scanf("%d", &position);

	if (position > 0 && position <= a)
	{
		for (j = 1; j <= a; j++)
		{
			if (position < j)
			{
				strcpy(note[j - 1], note[j]);
			}
		}
	}
	else if (position <= 0 && position > a)
	{
		a++;
		printf(" Invalid! Press any key to continue.");
		getch();
	}
	else
	{
		a++;
		printf(" Invalid! Press any key to continue.");
		while (getchar() != '\n');
		getch();
	}
}
void clear()
{
	int l;
	for (l = 0; l <= a; l++)
	{
		note[l][0] = '\0';
	}
	a = 0;
}

int main()
{
	char choice[10];
	int ctr = 0;

	while (ctr == 0)
	{
		system("cls");
		printf(" ============\n");
		printf("  To-do list\n");
		printf(" ============\n\n");
		allList();
		printf("\n What do you want to do (Add/Remove/Clear)? ");
		fgets(choice, 9, stdin);

		if (sscanf(choice, "%d", &ctr) == 1)
		{
			ctr = 0;
			printf(" Invalid Input! Press any key to continue.");
			getch();
			while (getchar() != '\n');
			continue;
		}
		if (sscanf(choice, "%s", choice) == 1)
		{
			if (strcmp(choice, "Add") == 0)
			{
				a++;
				if (a > 15)
				{
					printf(" Maximmum number of entry reached. Please remove a task to add again.");
					getch();
					a--;
					continue;
				}
				else
				{
					add();
					continue;
				}
			}
			else if (strcmp(choice, "Remove") == 0)
			{
				rem();
				a--;
				continue;
			}
			else if (strcmp(choice, "Clear") == 0)
			{
				clear();
				continue;
			}
			else
			{
				printf(" Invalid Entry! Press any key to continue.");
				getch();
				while (getchar() != '\n');
				continue;
			}
		}
	}
}