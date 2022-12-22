#include<iostream>

void say();

template<typename T>
void swap(T& arr,int x,int y)
{
    auto temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

template<typename T>
auto partition(T& arr, int low ,int high)
{
    int i = low;
    int j = high+1;
    auto key = arr[low];

    while(true)
    {
        while(arr[++i]<key) if(i == high) break;
        while(arr[--j]>key) if(j == low) break;

        if(i>=j) break;

        swap(arr,i,j);
    }
    swap(arr,low,j);
    return j;
}

template<typename T>
void selectSort(T& arr,int n)
{
    for(int i = 0; i < n ; ++i)
    {
        int min = i;
        for(int j = i+1; j < n ;++j)
        {
            if(arr[j]<arr[min])
                min = j;
        }
        swap(arr,i,min);
    }
}

template<typename T>
void insertSort(T& arr,int n)
{
    for(int i = 1; i < n ; ++i)
    {
        for(int j = i ; j>0 ; --j)
        {
            if(arr[j-1]>arr[j])
                swap(arr,j-1,j);
        }
    }
}

template<typename T>
void quickSort(T& arr , int low, int high)
{
    if(high<=low) return;

    int mid = partition(arr,low,high);

    quickSort(arr,low,mid-1);
    quickSort(arr, mid+1,high);

}

template<typename T>
void swim(T& arr, int k)
{
    while(k>1 && arr[k/2]<arr[k])
    {
        swap(arr,k/2,k);
        k = k/2;
    }
}

template<typename T>
void sink(T& arr, int k ,int n)
{
    while(2*k<=n)
    {
        int j = 2*k;
        if(j<n&&arr[j]<arr[j+1]) ++j;
        if(arr[k]>arr[j]) break;
        swap(arr,k,j);
        k=j;
    }
}

template<typename T>
void makeHeat(T& arr,int n)
{
    for(int i = n/2 ; i>=1; --i)
    {
        sink(arr,i,n);
    }

    while(n>1)
    {
        swap(arr,1,n--);
        sink(arr,1,n);
    }

}
