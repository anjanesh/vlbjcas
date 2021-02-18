// Stack
// Simple Stack Operations

#include<iostream.h>
#include<conio.h>

const int MAX = 1000;

class Stack
 {
        private:
         int sarray[MAX];
         int top;
        public:

         Stack()
          { top=0; }

         void push(int);
         int pop();
         void list();
 };

void Stack::push(int n)
 {
        if (top == MAX) {cout << "Stack full !";return;}
        sarray[top++] = n;
        cout << "Pushed " << n << '\n';
 }

int Stack::pop()
 {
        if (top == 0) { cout << "Stack empty !"; return -1; }
        cout << "Popped " << sarray[top - 1] << '\n';
        return sarray[top--];
 }

void Stack::list()
 {
        cout << "Current Stack : ";
        for (int i = 0; i < top; i++)
         cout << sarray[i] << '\t';
        cout << '\n';
 }

int main()
 {
        Stack s;
        s.push(5);
        s.push(6);
        s.push(1);
        s.push(2);
        s.list();
        s.pop();
        s.pop();
        s.list();
        getch();

        return 0;
 }