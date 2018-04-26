#include<iostream>
#include<stack>
using namespace std;
int main()
{

    stack<int> mystack;
    int in;
    int temp =0;
    while(temp <=10)
    {
        cout << "Enter a number to be pushed to stack" << endl;
        cin >> in;
        mystack.push(in);
        temp++;
    }

    while(!mystack.empty())
    {

        cout << mystack.top() << endl;
        mystack.pop();
    }
}
