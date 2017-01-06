#include <iostream>
using namespace std;

struct ListNode{

char info;
ListNode *next;
ListNode(char new_info, ListNode *new_next) : info(new_info), next(new_next){}
};
class SetList
{
ListNode *head;


public:
	SetList() : head(nullptr){}
	void enter(char c){head=new ListNode(c, head);}
	void print(ostream & out)
	{
	for(ListNode*p=head; p;p=p->next)
		out<<p->next<<" ";
	}
	int find(char c)
	{
		int cnt=0;
		for(ListNode *p=head; p;p=p->next)
		{
			cnt++;
			if(p->info==c)
				return cnt;
		}
	}
~SetList()
	{
	ListNode *temp;
	for(ListNode *p=head; p;)
		{
		temp=p;
		p=p->next;
		delete temp;
		}
	}
};
ostream & operator<<(ostream &out, SetList &s)
{
	s.print(out);
	return out;
}


























