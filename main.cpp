#include <iostream>
#include <limits>
#include <memory>

using namespace std;

int printSum(shared_ptr<int> arr[],int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += *arr[i];
    }
    return sum;
}

int main(){
    int val, inputs = 0;

    cout << "Enter a list of integers seperated by spaces: ";

    shared_ptr<int> num[20];

    while(true){
        while(cin >> val){
            if(cin.good()){
                num[inputs] = make_shared<int>(val);
                inputs++;
            }

            if(cin.peek() == '\n'){
                cout << "\nEnter more values or type a string to end input: ";
            }
        }
        if(cin.fail()){
            cin.clear();
            cout << "\nERROR: A value was not a number, ending...";
            break;
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cin.clear();
        }
    }

    cout << "\nInputs in array: ";

    for(int i = 0; i < inputs; i++){
        cout << num[i] << ((i == inputs-1)?"":", ");
    }

    cout << "\n\nThe sum of all the inputs is " << printSum(num, inputs) << ".";

    return 0;
}
