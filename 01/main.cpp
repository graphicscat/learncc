#include<iostream>
#include<future>
using namespace std;

int main()
{
    promise<int>pro;

    thread t1([&]{
        int x = 123;
        pro.set_value(x);
    });

    future<int> f1 = pro.get_future();

    t1.join();

    cout<<f1.get()<<endl;

    return 0;
}
