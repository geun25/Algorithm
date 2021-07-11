// 힙 정렬을 구현할 때는 완전 이진 트리가 사용되었기 때문에 배열로 표현가능
// 완전 이진 트리가 아닌 이진 트리는 배열로 표현하기 어려움
// 데이터의 낭비를 최소화하기 위해 '포인터' 사용
#include <iostream>

using namespace std;



// 하나의 노드 정보를 선업합니다.
typedef struct node* treePointer;
typedef struct node
{
	int data;
	treePointer leftChild, rightChild;
} node;

//전위 순회 구현
void preorder(treePointer ptr)
{
	if (ptr)
	{
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

//증위 순회 구현
void inorder(treePointer ptr)
{
	if (ptr)
	{
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

//후위 순회 구현
void postorder(treePointer ptr)
{
	if (ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main(void)
{
	node nodes[16];
	for (int i = 1; i <= 15; i++)
	{
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for (int i = 1; i <= 15; i++)
	{
		if (i % 2 == 0)
		{
			nodes[i / 2].leftChild = &nodes[i]; // 짝수는 왼쪽 자식 연결
		}
		else 
		{
			nodes[i / 2].rightChild = &nodes[i]; // 홀수는 오른쪽 자식 연결
		}
	}
	preorder(&nodes[1]);
	//inorder(&nodes[1]);
	//postorder(&nodes[1]);
	return 0;
}

