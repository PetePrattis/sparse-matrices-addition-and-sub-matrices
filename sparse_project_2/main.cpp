#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//function that prints 2d arrays properly
void print_array(int *arr, int r, int c){ //accepts as input the array value corresponding to the array reference address using pointer
    for(int i = 0; i < r; i++){ //for every line
        for(int j = 0; j < c; j++){ //for every column
            cout<<"["<<*(arr+i*c+j)<<"]"; //print the array's value at each point
        }
        cout<<endl;
    }
}

//function that finds a 2z2 sub array from the array passed through the function
void find_subarray(int *arr, int r, int c, int s){
    for (int i = 0; i < r - 1; i++){ 
        for (int j = 0; j < c - 1; j++){ 
            //get the sum of the four values that a 2z2 array consists of
            int sum = *(arr+i*c+j) + *(arr+i*c+(j+1)) + *(arr+(i+1)*c+j) + *(arr+(i+1)*c+(j+1));
                if (sum > s){ //check if the sum is bigger than variable c
                    int B[2][2] = { //create the 2x2 array 
                        {*(arr+i*c+j),*(arr+i*c+(j+1))},
                        {*(arr+(i+1)*c+j),*(arr+(i+1)*c+(j+1))}
                    };
                    cout<<"This sub-array's elements have a sum bigger than c:"<<endl;
                    print_array((int*)B, 2, 2); //pass the value of the sub array corresponding to the referral address in the print_array method
                }
        }
    }
}

//a method called by main to find the matrix that is the result of the sum of 2 other lists passed to the method
void add_arrays(int *arr1, int *arr2, int r, int c){ //
    int S[r][c];
    for(int i = 0; i < r; i++){ 
        for(int j = 0; j < c; j++){ /
            if(*(arr1+i*c+j) == 0 && *(arr2+i*c+j) == 0){ // check if the any of the values is zero to avoid extra additions
                S[i][j] = 0; 
            }
            else if (*(arr1+i*c+j) == 0){ 
                S[i][j] = *(arr2+i*c+j);
            }
            else if (*(arr2+i*c+j) == 0){ 
                S[i][j] = *(arr1+i*c+j);
            }
            else{ 
                S[i][j] = *(arr1+i*c+j) + *(arr2+i*c+j); 
            }
        }
    }
    print_array((int*)S, r, c); //pass the value of the sub array corresponding to the referral address in the print_array method
}

int main()
{
    //directions for user
    cout<<"This program will execute two functions on sparse matrices."<<endl;
    cout<<"The first function is addition of two sparse matrices."<<endl;
    cout<<"The second function will return a sub-matrix 2x2 of a sparse matrix, with sum of its elements greater than a variable."<<endl;
    string answer = ""; 
    const string exit = "exit";
    const string y = "y"; 
    const string n = "n"; 
    do{ //do while loop tht executes until user inputs the word 'exit'
        cout<<"Type 'a' or 'b' to choose between the two functions or 'exit' to terminate program."<<endl;
        cin>>answer; 
        if(answer == "a"){//user chose exercise 1
            cout<<"Do you want two random sparse matrices to be generated?";
            string answer3 = ""; 
            do{ 
                cout<<" y/n ?"<<endl;
                cin>>answer3;
            }while(answer3 != y && answer3 != n);

            if(answer3 == y){ //user chose matrices to be generated randomly
                int rows = (rand()%10) + 1; 
                int cols = (rand()%10) + 1; 
                int A[rows][cols]; 
                int B[rows][cols];
                std::fill(A[0], A[0] + rows * cols, 0); //fill with zero values
                std::fill(B[0], B[0] + rows * cols, 0);
                int p1, p2; 
                for (int i = 0; i < rows; i++){ 
                    for (int j = 0; j < cols; j++){ 
                        p1 = rand()%100;
                        p2 = rand()%100;
                        if(p1 > 75){ //25% chance value not to be zero to achieve sparsity
                            int number = (rand()%50) + 1; 
                            A[i][j] = number;
                        }
                        if(p2 > 75){
                            int number = (rand()%50) + 1;
                            B[i][j] = number;
                        }
                    }
                }
                
                cout<<"The two matrices."<<endl;
                print_array((int*)A, rows, cols);
                cout<<"+"<<endl;
                print_array((int*)B, rows, cols);
                cout<<"="<<endl;
                //call the function to add the two arrays
                add_arrays((int*)A,(int*)B, rows, cols);
            }

            else if(answer3 == n){ //user chose to create arrays manually
                cout<<"You will create and fill two matrices manually."<<endl;
                cout<<"Choose number of rows."<<endl;
                int rows;
                do{
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>rows;
                }while(rows <= 0 && rows > 20);

                cout<<"Choose number of columns."<<endl;
                int cols;
                do{
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>cols;
                }while(cols <= 0 && cols > 20);

                int A[rows][cols];
                int B[rows][cols];
                cout<<"Fill your first matrix with numbers"<<endl;
                for(int i = 0; i < rows; i++){
                    for(int j = 0; j < cols; j++){ 
                        int num;
                        cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl; 
                        cin>>num;
                        while(cin.fail()){ 
                            cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl;
                            cin.clear();
                            cin.ignore(256,'\n');
                            cin>>num;
                        }
                        A[i][j] = num;
                    }
                }
                cout<<"Fill your second matrix with numbers"<<endl;
                for(int i = 0; i < rows; i++){ 
                    for(int j = 0; j < cols; j++){ 
                        int num;
                        cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl; 
                        cin>>num;
                        while(cin.fail()){
                            cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl;
                            cin.clear();
                            cin.ignore(256,'\n');
                            cin>>num;
                        }
                        B[i][j] = num; 
                    }
                }
               
                
                cout<<"The two matrices."<<endl;
                print_array((int*)A, rows, cols);
                cout<<"+"<<endl;
                print_array((int*)B, rows, cols);
                cout<<"="<<endl;
                //call the function to add the two arrays
                add_arrays((int*)A,(int*)B, rows, cols);
            }
        }
        else if(answer == "b"){ //user chose exercise 2
            cout<<"Do you want a random sparse matrix and a random variable to be generated?";
            string answer2 = "";
            do{ 
                cout<<" y/n ?"<<endl;
                cin>>answer2;
            }while(answer2 != y && answer2 != n);

            if(answer2 == y){ //user chose to create array randomly
                int rows = (rand()%10) + 2; 
                int cols = (rand()%10) + 2; 
                int A[rows][cols]; 
                std::fill(A[0], A[0] + rows * cols, 0); 
                int p; 
                for (int i = 0; i < rows; i++){
                    for (int j = 0; j < cols; j++){ 
                        p = rand()%100; 
                        if(p > 75){ 
                            int number = (rand()%50) + 1;
                            A[i][j] = number;
                        }
                    }
                }
                int c = (rand() % 100) + 1;  //variable c that the sub arrays' element sum must be bigger of
                print_array((int*)A, rows, cols); 
                cout<<"The variable is: "<<c<<endl;
                find_subarray((int*)A,rows,cols,c);
            }
            else if(answer2 == n){ //user chose to create array manually
                cout<<"You will create and fill a matrix manually."<<endl;
                cout<<"Choose number of rows."<<endl;
                int rows;
                do{ 
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>rows;
                }while(rows <= 0 && rows > 20);

                cout<<"Choose number of columns."<<endl;
                int cols;
                do{ 
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>cols;
                }while(cols <= 0 && cols > 20);

                int A[rows][cols]; 
                cout<<"Fill your matrix with numbers"<<endl;
                for(int i = 0; i < rows; i++){ 
                    for(int j = 0; j < cols; j++){ 
                        int num;
                        cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl;
                        cin>>num;
                        while(cin.fail()){ 
                            cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl;
                            cin.clear();
                            cin.ignore(256,'\n');
                            cin>>num;
                        }
                        A[i][j] = num;
                    }
                }
                cout<<"Insert number for variable c."<<endl;
                int c;
                do{ 
                    cout<<"Number must be no greater than 100."<<endl;
                    cin>>c;
                }while(c <= 0 && c > 100);

                print_array((int*)A, rows, cols); 
                cout<<"The variable is: "<<c<<endl;
                find_subarray((int*)A,rows,cols,c); //call function to find all sub arrays and their individual sum

            }
        }
    }while(answer != exit);

    return 0;
}
