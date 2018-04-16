#include <iostream>

using namespace std;
class marks
{
    private:
        int a1;
        int a2;
    public :
        marks ()
        {
            a1 =0;
            a2 =0;
        }
        void get_mark()
        {
            cout << "enter marks " << endl;
            cin >> a1;
            cin >> a2; 

        }
        void print_mark()
        {
            cout << "a1 :" << a1 << "a2:" << a2 << endl;
        }
        void operator += (marks m1)
        {

            a1 += m1.a1;
            a2 += m1.a2;
        }

};


int main()
{

    marks m1 , m2;

    m1.get_mark();
    m2.get_mark();

    cout << "M1 mark" << endl;
    m1.print_mark();

    cout << "M2 mark" << endl;
    m2.print_mark();

    m1 += m2;
    cout << "M1 mark after" << endl;
    m1.print_mark();




    return 0;

}
