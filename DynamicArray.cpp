#include<iostream>
using namespace std;
class DynArray
{
    int capacity;
    int lastindex;
    int *ptr;

public:
        DynArray(int);
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void Delete(int);
        bool isFull();
        int get(int);
        int count();
        int find(int);
        ~DynArray();
        void doubleArray();
        void halfArray();
        int size();


};

//Delete function to delete data of given index
void DynArray::Delete(int index)
{
    int i;
    if(lastindex==-1)
        cout<<endl<<"Array is empty";
    else if(index<0 || index>lastindex)
        cout<<endl<<"Invalid index";

    else
    {
        for(i=index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;
        if(capacity/2>=lastindex+1 && capacity>1)
            halfArray();

    }
}

//insert function to insert data at given index
void DynArray::insert(int index,int data)
{
    int i;
    if(index<0 || index>lastindex+1)
        cout<<endl<<"Invalid index";
    else
    {
        if(isFull())
            doubleArray();
        for(i=lastindex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastindex++;

    }
}

//append function to add data just after last filled block
void DynArray::append(int data)
{
    if(isFull())
        doubleArray();
    lastindex++;
    ptr[lastindex]=data;
}

//size function to check total capacity of array
int DynArray::size()
{
    return capacity;
}

//doubleArray to increase capacity of array twice by its size when array is full and we need to append or insert data
void DynArray::doubleArray()
{
    int *temp=new int[capacity*2];
    for(int i=0;i<=lastindex;i++)
        temp[i]=ptr[i];
    delete[]ptr;
    ptr=temp;
    capacity*=2;
}

//halfArray for to reduce capacity of array half
void DynArray::halfArray()
{
    int *temp=new int[capacity/2];
    for(int i=0;i<=lastindex;i++)
        temp[i]=ptr[i];
    delete[]ptr;
    ptr=temp;
    capacity/=2;
}

//constructor
DynArray::DynArray(int cap)
{
    capacity=cap;
    lastindex= -1;
    ptr=new int[capacity];
}

//isEmpty to check whether array is empty or not
bool DynArray::isEmpty()
{
    return lastindex==-1;
}

//edit to change data at given index
void DynArray::edit(int index,int data)
{
    if(index>=0&&index<=lastindex)
        ptr[index]=data;
}

//isFull to check whether array is full or not
bool DynArray::isFull()
{
    return lastindex==capacity-1;
}

//get function is for to get data of given index
int DynArray::get(int index)
{
    if(index>=0&&index<=lastindex)
        return ptr[index];
    cout<<endl<<"Invalid index or empty";
    return -1;
}

//count function to know how many element present in the array
int DynArray::count()
{
    return lastindex+1;
}

//destructor
DynArray::~DynArray()
{
    delete[]ptr;
}

//find to know that given data is present in the array or not
int DynArray::find(int data)
{
    int i;
    for(i=0;i<=lastindex;i++)
        if(ptr[i]==data)
            return i;
    return -1;
}

//main block
int main()
{

    DynArray obj(5);
    obj.append(10);
    obj.append(20);
    obj.append(30);
    obj.append(40);
    obj.append(50);
    obj.insert(2,60);
    obj.edit(0,12);
    obj.edit(5,14);

    obj.Delete(4);

    cout<<"Elements in the Array is/are"<<endl;
    for(int i=0;i<obj.count();i++)
        cout<<obj.get(i)<<" ";
    cout<<endl<<"Total Element in the Array is = "<<obj.count();

    cout<<endl;
    return 0;
    return 0;
}

