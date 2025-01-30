#include <iostream>
#include<regex>
#include<string>
#include<fstream>
#include<chrono>
#include<random>
#include<algorithm>
using namespace std;


void Merge(int arr[], int p, int q,int r) {
    int n_1=q-p+1;//length of the first segment
    int n_2=r-q;//length of the second segment 
    int *left = new int[n_1];// create left array
    int *right = new int[n_2];//create right array
    for(int i=0;i<n_1;i++){//assigning elements to the left array from array passed to merge function
        left[i]=arr[p+i];
    }
    for(int i=0;i<n_2;i++){//assigning elements to the right array from array passed to merge function
        right[i]=arr[q+i+1];
    }
    int i=0,j=0;
    for(int k=p;k<=r;k++){
        if ((j>=n_2) || (i<n_1 && left[i]<= right[j])){
            arr[k]=left[i];
            i=i+1;
        }
        else{
            arr[k]=right[j];
            j=j+1;
        }
    }
    delete[] left;
    delete[] right;
}


void MergeSort(int arr[],int p, int r){
    if(p>=r){
        return;
    }
    int mid=(p+r)/2;
    MergeSort(arr,p,mid);
    MergeSort(arr,mid+1,r);
    Merge(arr,p,mid,r);
}

int main(){
    fstream myfile;
    myfile.open("data.txt",ios::in);//opening the data.txt file inn which random array exist of different sizes
    if(myfile.is_open()){
        string line;
        int count=1;
        while(getline(myfile,line)){
            regex del(",");
            sregex_token_iterator it(line.begin(), line.end(), del, -1);//using regex to read each integer separately which are separated by the del(',')
            sregex_token_iterator end;
            int i =0;
            int *arr = new int[count];//initialising the array with size count that is current array size as it is increasing order we add one to count each time the loop runs to automatically create new array of increasing size
            while (it != end) {
                string token = *it;//converting string type casted integer into integer
                arr[i]=std::stoi(token);// giving each array element a integer 
                i++;
                ++it;
            }
            chrono::duration<double> total_duration = chrono::seconds(0); // initializing with zero second
            int *tempArr= new int[count];
            for(int i=0;i<100;i++){//same array run multiple times for better time average 
                copy(arr,arr+count,tempArr);//copying the original array data in temp array as same array is to be run multiple times
                auto start=chrono::high_resolution_clock::now();
                MergeSort(tempArr,0,count-1);
                auto stop=chrono::high_resolution_clock::now();
                chrono::duration<double> duration=stop-start;
                total_duration+=duration; // adding to total duration every time the for loop runs
            }

            fstream myfile;
            myfile.open("Merge_time.txt",ios::app);//opening the file and writing the time and size in the text file 
            if(myfile.is_open()){
                myfile<<"time="<<total_duration.count()/100<<" ";
                myfile<<"size="<<count<<endl;
                myfile.close(); // closing the file in which the time and size is being stored
            }            
            count++; //increasing the size to accommodate for the next coming array 
            delete[] arr;           //deleting the array to free the memory and also a new array of different size needs to be created everytime the loop runs
        }
        myfile.close();    //closing the txt file from which the data is being read
    }
    return 0;  
}
