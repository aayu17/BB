#include<iostream>
#include<vector>
using namespace std;


//Max Heapify
void maxHeapify(vector<int>& arr,int& pos,int &heap_length)
{
    int left_pos=2*pos;
    int right_pos=2*pos+1;
    int largest=pos;
    
    if(left_pos<heap_length && arr[pos]<arr[left_pos])
    {
        largest=left_pos;
    }
    
    if(right_pos<heap_length && arr[largest]<arr[right_pos])
    {    
        largest=right_pos;
    }

    int temp=arr[pos];
    arr[pos]=arr[largest];
    arr[largest]=temp;

    if(largest !=pos)
    {
        maxHeapify(arr,largest,heap_length);
    }
}


//Insert Element 
void insert(vector<int>& arr,int& heap_length)
{
    int element;
    cout<<"\nENTER VALUE TO INSERT: ";
    cin>>element;
    cout<<endl;
    heap_length++;
    arr[heap_length]=element;

        int position=heap_length;
        int parent=position/2;   //Parent Position
        
        while(position>1 & arr[parent]<arr[position])
        {
            //Swap the values
            int temp=arr[parent];
            arr[parent]=arr[position];
            arr[position]=temp;
            position=parent;
            parent=position/2;
        }
}


//Maximum Element in the heap
int heap_maximum(vector<int>& arr)
{
    return arr[1];
}


//Remove Max
int extract_max(vector<int>& arr,int& heap_length)
{
    if(heap_length<1)
    {
        cout<<"EMPTY HEAP"<<endl;
    }
    else
    {
        //Swap the first and last element
        int max=arr[1];
        arr[1]=arr[heap_length];
        arr[heap_length]=max;
        heap_length--;

        int pos=1;
        maxHeapify(arr,pos,heap_length);
        return max;
    }
}


//Increase Key
void increase_key(vector<int>& arr,int& heap_length,int &pos,int& key)
{
    if(pos<=heap_length)
    {
        if(key>arr[pos])
        {
            arr[pos]=key;
            int parent=pos/2;
            while(pos>1 and arr[parent]<arr[pos])
            {
                //Swap the values
                int temp=arr[parent];
                arr[parent]=arr[pos];
                arr[pos]=temp;
                pos=parent;
                parent=pos/2;
            }
        }
        else
        {
            cout<<"\nKEY VALUE LESS THAN CURRENT VALUE"<<endl;
        }
    }
    else
    {
        cout<<"\nPOSITION DOESN'T EXIST"<<endl;
    }
}


//Display Heap
void display(vector<int>& arr,int& heap_length)
{
    for(int i=1;i<=heap_length;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


//Main Function
int main()
{
    vector<int> arr;
    int heap_length=0;
    arr.push_back(0);

    bool flag=true;

    while(flag)
    {
        cout<<"\n1 INSERT A KEY"<<endl;
        cout<<"2 FIND MAX KEY"<<endl;
        cout<<"3 EXTRACT MAX"<<endl;
        cout<<"4 INCREASE KEY"<<endl;
        cout<<"5 TERMINATE"<<endl;   

        int ch;
        cout<<"\nENTER CHOICE: ";
        cin>>ch;

        if(ch==1)
        {
            insert(arr,heap_length);
            display(arr,heap_length);
        }
        else if(ch==2)
        {
            if(heap_length>=1)
                cout<<heap_maximum(arr)<<endl;
            else
                cout<<"EMPTY HEAP"<<endl;
        }
        else if(ch==3)
        {   
            if(heap_length>=1)
            {
                cout<<extract_max(arr,heap_length)<<endl;
                display(arr,heap_length);
            }
            else
                cout<<"EMPTY HEAP"<<endl;
        }
        else if(ch==4)
        {
            cout<<"ENTER THE POSITION"<<endl;
            int pos;
            cin>>pos;
            cout<<"ENTER INCREASE VALUE"<<endl;
            int key;
            cin>>key;
            increase_key(arr,heap_length,pos,key);
            display(arr,heap_length);
        }
        else if(ch==5)
        {
            flag=false;
            break;
        }
    }
    return 0;
}