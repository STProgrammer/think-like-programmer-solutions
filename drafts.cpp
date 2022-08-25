#include <iostream> //For cout
#include <cstring>  //For the string functions
#include <stdio.h>
#include <iomanip>
#define PRINT_TOKEN(token) printf(#token " is %d", token)

using namespace std;

//Do not run this

class TestA
{
        public:
            int val = 0;

            void test ();

};


void TestA::test()
{
    val = 15;
    cout << val << "testA";
}


class TestB : public TestA
{
        public:
           void test ();
};




void TestB::test()
{
    val = 45;
    cout << val << "testB";
}

int testFunc(int x, int y);

int testFunc(int x, int y)
{
    int z;
    if (x > y) z = x++;
    else return z = y++;
}

int main()
{


    TestA * a = new TestB;
    TestB * b = new TestB;

    b->test();
    a->test();

    int x = 11; int y = 3;

    char str[15] = "asdasd" "sedsedse";

    cout<<setfill('-')<<setw(15)<<left<<"wer"<<left<<"zxc"<<endl;
    cout << setbase(16) << 466 << " " << 64 << endl;
    cout << "Modulo operations" << endl;
    cout << (x - ((x / y) * y)) << endl;
    cout << x % y << endl;

    PRINT_TOKEN(x+y);

    int m = 5 + \
            4;

    int z = testFunc(x++, y++);

    cout << "\n" << z;
    cout << "\n" << y;
    cout << "\n" << m;


    return 0;
}
