#include <iostream>
#include <stdlib.h>
using namespace std;

//�����
class Node {
public:
	int data;
	Node *pNext;
};

//����������
class LinkList {
public:
	LinkList() {
		//ͷ��㲻�������
		head = new Node;
		head->data = 0;
		head->pNext = NULL;
	}
	~LinkList() { delete head; }
	void CreateLinkList(int n);				//��������
	void InsertNode(int position, int d);	//��ָ��λ�ò�����
	void TraverseLinkList();				//��������
	bool IsEmpty();							//�ж������Ƿ�Ϊ��
	int GetLength();						//������
	void DeleteNode(int position);			//ɾ��ָ��λ�ý��
	void DeleteLinkList();					//ɾ����������
private:
	Node *head;
};

void LinkList::CreateLinkList(int n) {
	if (n < 0) {
		cout << "�������������" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Node *pnew, *ptemp;
		ptemp = head;
		int i = n;
		while (n-- > 0) {
			pnew = new Node;
			cout << "�����" << i - n << "�����ֵ��";
			cin >> pnew->data;
			pnew->pNext = NULL;
			ptemp->pNext = pnew;
			ptemp = pnew;
		}
	}
}
//postion��1��ʼ�������������ȼ�1������ͷ����Ľ���Ϊ��һ�����
void LinkList::InsertNode(int position, int d) {
	if (position < 0 || position > GetLength() + 1) {
		cout << "����λ�ô���" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Node *pnew, *ptemp;
		ptemp = head;
		pnew = new Node;
		pnew->data = d;
		pnew->pNext = NULL;

		while (position-- > 1)
			ptemp = ptemp->pNext;
		pnew->pNext = ptemp->pNext;
		ptemp->pNext = pnew;
	}
}

void LinkList::TraverseLinkList() {
	Node *p = head->pNext;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << endl;
}

bool LinkList::IsEmpty() {
	if (head->pNext == NULL)
		return true;
	else
		return false;
}

int LinkList::GetLength() {
	Node *p = head->pNext;
	int n = 0;
	while (p != NULL) {
		n++;
		p = p->pNext;
	}
	return n;
}
//positionֻ�ܴ�1��ʼ�������Ƚ���
void LinkList::DeleteNode(int position) {
	if (position < 0 || position > GetLength()) {
		cout << "����λ�ô���" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Node *ptemp = head, *pdelete;
		while (position-- > 1)
			ptemp = ptemp->pNext;
		pdelete = ptemp->pNext;
		ptemp->pNext = pdelete->pNext;
		delete pdelete;
		pdelete = NULL;
	}
}

void LinkList::DeleteLinkList() {
	Node *pdelete = head->pNext, *ptemp;
	while (pdelete != NULL) {
		ptemp = pdelete->pNext;
		head->pNext = ptemp;
		delete pdelete;
		pdelete = ptemp;
	}
}

void liyuan()
{

}

//���Ժ���
int main() {
	LinkList l;
	int position = 0, value = 0, n = 0;
	bool flag = false;

	cout << "��������Ҫ������������Ľ�������";
	cin >> n;
	l.CreateLinkList(n);

	cout << "��ӡ����ֵ���£�";
	l.TraverseLinkList();

	cout << "������������λ�ú�ֵ��";
	cin >> position >> value;
	l.InsertNode(position, value);

	cout << "��ӡ����ֵ���£�";
	l.TraverseLinkList();

	cout << "������Ҫɾ������λ�ã�";
	cin >> position;
	l.DeleteNode(position);

	cout << "��ӡ����ֵ���£�";
	l.TraverseLinkList();

	l.DeleteLinkList();
	flag = l.IsEmpty();
	if (flag)
		cout << "ɾ������ɹ���" << endl;
	else
		cout << "ɾ������ʧ�ܣ�" << endl;
	
	return 0;
}
