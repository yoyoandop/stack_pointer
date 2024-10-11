#include <iostream>
using namespace std;

// �`�I���c��
struct Node {
    int data;     // �`�I�s�x���ƾ�
    Node* next;   // ���V�U�@�Ӹ`�I������
};

// Stack ���O
class Stack {
private:
    Node* top;    // ���V���|����������

public:
    // �c�y��ơG��l�� Stack
    Stack() {
        top = nullptr;  // ��l�Ƭ���
    }

    // �P�_ Stack �O�_����
    bool isEmpty() {
        return top == nullptr;
    }

    // push �ާ@�G�V Stack �K�[����
    void push(int value) {
        Node* newNode = new Node();  // ���t�s�`�I
        newNode->data = value;       // �`�I�s�J�ƾ�
        newNode->next = top;         // �N�s�`�I���V��e������
        top = newNode;               // ��s�������s�`�I
        cout << value << " pushed onto stack." << endl;
    }

    // pop �ާ@�G�q Stack ��������������
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;  // �Ȧs�����`�I
        top = top->next;   // �N�������w���ܤU�@�Ӹ`�I
        cout << temp->data << " popped from stack." << endl;
        delete temp;       // ���񳻳��`�I���O����
    }

    // peek �ާ@�G�d�� Stack ����������
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;  // �N��� Stack
        }
        return top->data;  // ��^�����`�I���ƾ�
    }

    // �Ѻc��ơG����Ҧ��`�I�O����
    ~Stack() {
        while (!isEmpty()) {
            pop();  // �v�@ pop ������O����
        }
    }
};

// ���� Stack ����@
int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element is " << stack.peek() << endl;

    stack.pop();
    stack.pop();  // ���ժŰ��|�� pop �ާ@

    return 0;
}
