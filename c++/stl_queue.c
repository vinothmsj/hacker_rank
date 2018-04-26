#include<iostream>
#include<queue>
using namespace std;
int main()
{

    int in;
    queue<int> myq;
    int temp = 0;

    while(temp <=10)
    {
        cout << "Enter number to place in queue" << endl;
        cin >> in;
        myq.push(in);
        temp++;
    }

    while(!myq.empty())
    {
        cout << myq.front() << endl;
        myq.pop();
    }
    return 0;

}
