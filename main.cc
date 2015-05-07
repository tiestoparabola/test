#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Simple code demonstrating c++ exception usage
*/
class Object 
{
    friend ostream & operator<<(ostream &os, const Object &obj);
public:
    Object();
    Object(int x, int y);

private:
    int _x, _y;
};

void func();

int main () 
{
    srand(time(NULL));

    try 
    {
        func();
    } catch (exception &ex) 
    {
        cout << ex.what() << endl;
    }
}

ostream & operator<<(ostream &os, const Object &obj)
{
    cout << obj._x << ' ' << obj._y;
}

Object::Object()
{
    _x = _y = 0;
}

Object::Object(int x, int y) 
{
    _x = x; _y = y;
    if (rand() % 2 == 0) throw invalid_argument( "received negative value");
}

void func() 
{
    Object obj(1, 2);
    cout << obj << endl;
}
