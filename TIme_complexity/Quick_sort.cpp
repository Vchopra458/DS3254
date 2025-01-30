#include <iostream>
#include<regex>
#include<string>
#include<fstream>
#include<chrono>
#include<random>
#include<algorithm>
using namespace std;

int Partition(int arr[],int p,int r){
    int x=arr[r];
    int i = p-1;
    for(int j=p;j<=r-1;j++){
        if(arr[j]<=x){
            i=i+1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}


void Quicksort(int arr[],int p , int r){
    if(p<r){
    std::random_device rd; // random number 
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(p, r); // define the range
        int k = distr(gen);
        swap(arr[k],arr[r]);
        int q=Partition(arr,p,r);
        Quicksort(arr,p,q-1);
        Quicksort(arr,q+1,r);
    }
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
                string token = *it;
                arr[i]=std::stoi(token);// giving each array element a integer and converting string type casted integer into integer
                i++;
                ++it;
            }
            chrono::duration<double> total_duration = chrono::seconds(0); // initializing with zero second
            int *tempArr= new int[count];
            for(int i=0;i<10;i++){//same array run 10 times for better time average
                copy(arr,arr+count,tempArr);//copying the original array data in temp array as same array is to be run multiple times
                auto start=chrono::high_resolution_clock::now();
                Quicksort(tempArr,0,count-1);
                auto stop=chrono::high_resolution_clock::now();
                chrono::duration<double> duration=stop-start;
                total_duration+=duration; // adding to total duration every time the for loop runs
            }


            fstream myfile;
            myfile.open("quick_time.txt",ios::app);//opening the file and writing the time and size in the text file 
            if(myfile.is_open()){
                myfile<<"time="<<total_duration.count()/10<<" ";
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
