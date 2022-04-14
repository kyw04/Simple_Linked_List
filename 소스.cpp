#include <iostream>
using namespace std;

typedef struct _Node
{
	int key;
	_Node* next;
}node;

node* head, * tail;

class LinkedList
{
public:

	void init_list() // head, tail ����
	{
		head = new node;
		tail = new node;
		head->next = tail;
		head->key = NULL;
		tail->next = tail;
		tail->key = NULL;
	}

	node* insert_after(int data, node* t) // t ��� �տ� data ���� ���� ��� ����
	{
		node* s = new node;
		s->key = data;
		s->next = t->next;
		t->next = s;

		return s;
	}

	int insert_node(int key, int data) // head���� ���� ����� key ���� ���� ��� �տ� data ���� ���� ��� ����
	{
		node* p = head;
		node* s = p->next;

		while (s->key != key && s != tail)
		{
			p = p->next;
			s = p->next;
		}
		if (s != tail)
		{
			node* n = new node;
			n->key = data;
			p->next = n;
			n->next = s;
			return 1;
		}
		return 0;
	}

	node* ordered_insert(int data) // ������������ ���ĵǾ� ���� �� data ���� ���� ��ġ�� ����
	{
		node* p = head;
		node* s = p->next;

		while (s->key <= data && s != tail)
		{
			p = p->next;
			s = p->next;
		}

		node* n = new node;
		n->key = data;
		p->next = n;
		n->next = s;

		return n;
	}

	int delete_next(node* t) // t ��� ���� ��� ����
	{
		if (t->next == NULL)
			return 0;

		node* s = new node;
		s = t->next;
		t->next = t->next->next;
		delete s;
		return 1;
	}

	int delete_node(int key) // head���� ���� ����� key ���� ���� ��� ����
	{
		node* p = head;
		node* s = p->next;

		while (s->key != key && s != tail)
		{
			p = p->next;
			s = p->next;
		}
		if (s != tail)
		{
			p->next = s->next;
			delete s;
			return 1;
		}
		return 0;
	}

	node* delete_all() // ����Ʈ�� ��� ��� ����
	{
		node* t = head->next;
		node* s = t->next;

		while (t != tail)
		{
			s = t;
			t = t->next;
			delete s;
		}
		head->next = tail;
		return head;
	}
	
	node* find_node(int key) //head���� ���� ����� key ���� ���� ��� ã��
	{
		node* s = new node;
		s = head;
		while (s->key != key && s->next != tail)
			s = s->next;
		return s;
	}

	void print_list() // head ���� tail ���� ����Ʈ�� key �� ���
	{
		node* t = head->next;
		while (t != tail)
		{
			cout << t->key << endl;
			t = t->next;
		}
	}
};

int main()
{
	LinkedList lin;
	lin.init_list();

	for (int i = 10; i > 0; i--)
	{
		lin.insert_after(i, head);
	}

	lin.ordered_insert(11);

	lin.print_list();

	lin.delete_all();

	lin.print_list();

	return 0;
}