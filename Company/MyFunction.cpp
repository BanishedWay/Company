#include "MyFunction.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

BiTree CreatNode(TElemType ch)
{
	BiTree p = (BiTree)malloc(sizeof(BiTNode));
	if (!p)
		return p;
	p->data = ch;
	p->lchild = NULL;
	p->rchild = NULL;
	p->tempchild = NULL;
	p->parent = NULL;
	p->l = false;
	p->r = false;
	p->flag = false;
	return p;
}

void Print(BiTree& T)
{
	if (!T)
		return;
	printf("%s\n", T->data);
	Print(T->lchild);
	Print(T->rchild);
}

void AddNode(BiTree& T, TElemType employer, TElemType employee)
{
	if (!T)
		return;
	if (!strcmp(T->data, employer))
	{
		BiTree t = CreatNode(employee);
		if (!t)
			return;
		t->parent = T;
		if (!T->l)
		{
			T->lchild = t;
			T->l = true;
		}
		else if (!T->r)
		{
			T->rchild = t;
			T->r = true;
		}
		else
		{
			T->tempchild = t;
			T->flag = true;
		}
		return;
	}
	AddNode(T->lchild, employer, employee);
	AddNode(T->rchild, employer, employee);
}

void DeleteNode(BiTree& T, TElemType employer)
{
	if (!T)
		return;
	if (!strcmp(T->data, employer))
	{
		Replace(T);
	}
	DeleteNode(T->lchild, employer);
	DeleteNode(T->rchild, employer);
}

void Replace(BiTree& T)
{
	if (!T)
		return;
	else
	{
		BiTree p = T->parent;
		if (!T->l && !T->r)
		{
			if (p->lchild == T)
				p->lchild = NULL;
			else
				p->rchild = NULL;
			return;
		}
		else if (T->l && !T->r)
		{
			if (p->lchild == T)
				p->lchild = T->lchild;
			else
				p->lchild = T->lchild;
		}
		else if (!T->l && T->r)
		{
			if (p->lchild == T)
				p->lchild = T->rchild;
			else
				p->rchild = T->rchild;
		}
		else
		{
			BiTree next = getNextNode(T);
			Replace(next);
			T->data = next->data;
		}
	}
}

BiTree getNextNode(BiTree& T)
{
	if (!T)
		return NULL;
	if (T->r)
	{
		return getMinNode(T->rchild);
	}
	else
	{
		BiTree p = T->parent;
		while (p && p->rchild == T)
		{
			T = p;
			p = p->parent;
		}
		return p;
	}
}

BiTree getMinNode(BiTree& T)
{
	if (!T)
		return NULL;
	BiTree temp = T;
	while (temp->lchild != NULL)
		temp = temp->lchild;
	return temp;
}

bool get_Value_String1(char* str1, const char* str2)
{
	if (strstr(str1, str2))
	{
		return true;
	}
	return false;

}

char* get_Value_String_Employee(char* str1, const char* str2)
{
	
	char* temp = (char*)malloc(sizeof(char));
	if (!temp)
		return NULL;
	int i = get_Value_String3(str1, str2), j = 0;
	while (j < 3)
	{
		*(temp + j) = *(str1 + i);
		j++;
		i++;
	}
	*(temp + j) = 0;
	return temp;
}

int get_Value_String3(char* str1, const char* str2)
{
	int flag = 0, i, j;
	for (i = 0; i < strlen(str1); i++)
	{
		if (*(str1 + i) == *str2)
		{
			int count = 1;
			for (j = 1; j < strlen(str2); j++)
			{
				if (*(str1 + i + j) == *(str2 + j))
					count++;
			}
			if (count == strlen(str2))
				flag = i + j + 1;
		}
	}
	return flag ;
}


