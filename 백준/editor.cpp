#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct NODE
{
	struct NODE *next;
	struct NODE *back;
	char data;
};

string str;
NODE *curr;
NODE *head;
void addnode(NODE *target, char data);
void delnode(NODE *target);

int main()
{
	int n, i,len;
	char order;
	char alp;
	
	NODE *tail = (NODE*)malloc(sizeof(NODE));
	cin >> str >> n;
	
	len = str.size();
	head = tail;
	tail->next = tail->back = NULL;
	
	for (i = 0; i < len; i++)
	{
		addnode(tail, str[i]);
	}
	
	curr = tail;
	
	while (n--)
	{
		cin >> order;
		if (order == 'L')
		{
			if (curr != head)
			{
				curr = curr->back;
			}
		}
		else if (order == 'D')
		{
			if (curr != tail)
			{
				curr = curr->next;
			}
		}
		else if (order == 'B')
		{
			delnode(curr);
		}
		else
		{
			cin >> alp;
			addnode(curr, alp);
		}
	}
	
	curr = head;
	while (curr != tail)
	{
		printf("%c", curr->data);
		curr = curr->next;
	}
	printf("\n");

	return 0;
}
void addnode(NODE *target, char data)
{
	NODE *newNODE = (NODE*)malloc(sizeof(NODE));
	newNODE->next = target;
	newNODE->data = data;
	
	if (head != target)
	{
		newNODE->back = target->back;
		target->back->next = newNODE;
		target->back = newNODE;
	}
	else
	{
		head = newNODE;
		newNODE->back = NULL;
		newNODE->next = target;
		target->back = newNODE;
	}
}
void delnode(NODE *target)
{
	if (target == head)
		return;
	NODE *tmp = target->back;
	//여기부터 다시보 
	if(tmp == head){
		head = target;
		target->back = NULL;
	}
	else{
		target->back = target->back->back;
		target->back->next = target;
	}
	
	free(tmp);
}
