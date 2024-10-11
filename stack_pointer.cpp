#include <iostream>
using namespace std;

// 節點結構體
struct Node {
    int data;     // 節點存儲的數據
    Node* next;   // 指向下一個節點的指標
};

// Stack 類別
class Stack {
private:
    Node* top;    // 指向堆疊頂部的指標

public:
    // 構造函數：初始化 Stack
    Stack() {
        top = nullptr;  // 初始化為空
    }

    // 判斷 Stack 是否為空
    bool isEmpty() {
        return top == nullptr;
    }

    // push 操作：向 Stack 添加元素
    void push(int value) {
        Node* newNode = new Node();  // 分配新節點
        newNode->data = value;       // 節點存入數據
        newNode->next = top;         // 將新節點指向當前的頂部
        top = newNode;               // 更新頂部為新節點
        cout << value << " pushed onto stack." << endl;
    }

    // pop 操作：從 Stack 中移除頂部元素
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;  // 暫存頂部節點
        top = top->next;   // 將頂部指針移至下一個節點
        cout << temp->data << " popped from stack." << endl;
        delete temp;       // 釋放頂部節點的記憶體
    }

    // peek 操作：查看 Stack 的頂部元素
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;  // 代表空 Stack
        }
        return top->data;  // 返回頂部節點的數據
    }

    // 解構函數：釋放所有節點記憶體
    ~Stack() {
        while (!isEmpty()) {
            pop();  // 逐一 pop 並釋放記憶體
        }
    }
};

// 測試 Stack 的實作
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
    stack.pop();  // 測試空堆疊的 pop 操作

    return 0;
}
