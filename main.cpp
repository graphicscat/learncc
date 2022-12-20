#include<iostream>
#include<future>
#include<string>

using namespace std;

namespace list_46{
struct robot
{
    /* data */
    robot() = default;
    void say(int n,const string& str)
    {
        for(int i = 0;i < n;++i)
            cout << str << endl;

        type = str;
    }
    
    const string gettype()
    {
        return type;
    }
    string type = "000";
};
}
int main()
{
    list_46::robot x;
    auto f1 = async(&list_46::robot::say,&x,2,"yoruha 2b");
    f1.wait();
    auto f2 = async(launch::deferred,&list_46::robot::gettype,&x);
    
    cout<< "type: " << f2.get() << endl;
    return 0;
}