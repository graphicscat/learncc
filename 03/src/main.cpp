#include<sort.h>
#include<vector>
int main()
{
     int vec[] = {-1,1,4,2,5,3,9,6,8,7,0};
    //selectSort(vec,10);
    //quickSort(vec,0,9);
    makeHeat(vec,10);
    for(int i = 1 ;i<=10;++i)
    {
        std::cout<<vec[i];
    }


    std::cout<<std::endl;



    return 0;
}