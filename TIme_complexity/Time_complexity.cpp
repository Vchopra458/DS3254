#include <iostream>
#include<regex>
#include<string>
#include<fstream>
#include<chrono>
using namespace std;

void insertion_sort(int arr[],int size){
    auto start=chrono::high_resolution_clock::now();
    for(int i =0;i<size;i++){
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
    fstream myfile;
    myfile.open("insertion_time.txt",ios::app);
    if(myfile.is_open()){
        myfile<<"time="<<duration.count()<<" ";
        myfile<<"size="<<size<<endl;
        myfile.close();
    }
}


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
    auto start=chrono::high_resolution_clock::now();
    for(int i=0;i<size;i++){
        int min_ind= getMin(arr,i,size-1);
        int temp=arr[i];
        arr[i]=arr[min_ind];
        arr[min_ind]=temp;
    }
    auto stop=chrono::high_resolution_clock::now();
    chrono::duration<double> duration=stop-start;
    fstream myfile;
    myfile.open("time_selection.txt",ios::app);
    if(myfile.is_open()){
        myfile<<"time="<<duration.count()<<" ";
        myfile<<"size="<<size<<endl;
        myfile.close();
    }
}    



int main(){
    fstream myfile;
    myfile.open("data.txt",ios::in);
    if(myfile.is_open()){
        string line;
        int count=1;
        while(getline(myfile,line)){
            regex del(",");
            sregex_token_iterator it(line.begin(), line.end(), del, -1);
            sregex_token_iterator end;
            int i =0;
            int *arr = new int[count];
            while (it != end) {
                string token = *it;
                arr[i]=std::stoi(token);
                i++;
                ++it;
            }
            insertion_sort(arr,count);
            selection_sort(arr,count);
            count++; 
            delete[] arr;           
        }
        myfile.close();    
    }
    return 0;
}
