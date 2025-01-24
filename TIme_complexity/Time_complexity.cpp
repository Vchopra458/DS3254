#include <iostream>
#include<regex>
#include<string>
#include<fstream>
#include<chrono>
#include<random>
#include<algorithm>
using namespace std;

void insertion_sort(int arr[],int size){
    chrono::duration<double> total_duration = chrono::seconds(0); // initializing with zero second
    for(int x=0;x<10;x++){   //running the same array 10 times for better average     
        auto start=chrono::high_resolution_clock::now();
        for(int i =0;i<size;i++){ //Insertion sort
            int key=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j=j-1;
            }    
            arr[j+1]=key;    
        }
        auto stop=chrono::high_resolution_clock::now();
        chrono::duration<double> duration=stop-start;
        total_duration+=duration; // adding to total duration every time the for loop runs
    }
    fstream myfile;
    myfile.open("insertion_time.txt",ios::app);//opening the file and writing the time and size in the text file 
    if(myfile.is_open()){
        myfile<<"time="<<total_duration.count()/10<<" ";
        myfile<<"size="<<size<<endl;
        myfile.close(); // closing the file in which the time and size is being stored
    }
}

// get minimum elemnet index
int getMin(int arr[], int i, int j) {
int min_idx = i;
for(int k = i + 1; k <= j; k++) {
    if (arr[k] < arr[min_idx]) {
        min_idx = k;
        }
    }
    return min_idx;
}


void selection_sort(int arr[],int size){
    chrono::duration<double> total_duration = chrono::seconds(0); //initializing with zero time
    for(int x=0;x<10;x++){ //running the same array 10 times for better time average
        auto start=chrono::high_resolution_clock::now();
        for(int i=0;i<size;i++){
            int min_ind= getMin(arr,i,size-1);
            int temp=arr[i];
            arr[i]=arr[min_ind];
            arr[min_ind]=temp;
        }
        auto stop=chrono::high_resolution_clock::now();
        chrono::duration<double> duration=stop-start;
        total_duration+=duration;// adding to total duration every time the for loop runs
    }
    fstream myfile;
    myfile.open("time_selection.txt",ios::app);
    if(myfile.is_open()){
        myfile<<"time="<<total_duration.count()/10<<" ";//opening the file and writing the time and size in the text file
        myfile<<"size="<<size<<endl;
        myfile.close(); // closing the file in which the time and size is being stored
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
                string token = *it;//converting string type casted integer into integer
                arr[i]=std::stoi(token);// giving each array element a integer 
                i++;
                ++it;
            }
            insertion_sort(arr,count); //function to call insertion sort
            selection_sort(arr,count); // function to call selection sort
            count++; 
            delete[] arr;           //deleting the array to free the memory and also a new array of different size needs to be created everytime the loop runs
        }
        myfile.close();    //closing the txt file from which the data is being read
    }
    return 0;
}
