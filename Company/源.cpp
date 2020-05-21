#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MyFunction.h"

int main()
{
	char* CEO = (char*)malloc(sizeof(char) * MAXN);
	if (!CEO)
		exit(0);
	scanf("%s", CEO);
	getchar();
	BiTree Company = CreatNode(CEO);
	char* temp = (char*)malloc(sizeof(char) * MAXN);
	while (1)
	{
		scanf("%[^\n]", temp);
		getchar();
		if (get_Value_String1(temp, "hires"))
		{
			char* employee = get_Value_String_Employee(temp, "hires");
			char employer[5] = { 0 };
			strncpy(employer, temp, 3);
			AddNode(Company, employer, employee);
		}
		else if (get_Value_String1(temp, "fire"))
		{
			char* employee = get_Value_String_Employee(temp, "fire");
			DeleteNode(Company, employee);
		}
		else if (get_Value_String1(temp, "print"))
		{
			Print(Company);
			printf("\n------------------------\n");
		}
		
	}
	return 0;
}