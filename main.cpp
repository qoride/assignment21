#include <iostream>
#include <limits>

using namespace std;

int main(){
    int val, inputs = 0, sum = 0;

    cout << "Enter a list of integers seperated by spaces: ";
    
    int* num = new int[20];

    while(true){
        while(cin >> val){
            if(cin.good()){
                if(inputs%20==0&&inputs!=0){
                    int* resize = new int[inputs+20];
                    for(int i = 0; i < inputs; i++){
                        resize[i] = num[i];
                    }
                    num = resize;
                    delete[] resize;
                }
                num[inputs] = val;
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
        sum += num[i];
    }

    delete[] num;

    cout << "\n\nThe sum of all the inputs is " << sum << ".";

    return 0;
}
