#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//��� ������� � ����� �������� ��� ��� main ��� ��� �������� ������
void print_array(int *arr, int r, int c){ //������� �� ������ ��� ���� ��� ������ ��� ����������� ���� ��������� ���������� ��� ������ �� ����� pointer
    for(int i = 0; i < r; i++){ //��� ���� ������
        for(int j = 0; j < c; j++){ //��� ���� �����
            cout<<"["<<*(arr+i*c+j)<<"]"; //�������� ��� ���� ��� ������ ��� �������� ������
        }
        cout<<endl;
    }
}

//��� ������� � ����� �������� ��� ��� main ��� ��� ������ ���-������ ��� ������ ���� ����� ��� ������� � ������� �� ������
void find_subarray(int *arr, int r, int c, int s){
    for (int i = 0; i < r - 1; i++){ //��� ���� ������ ������������ ��� ���������
        for (int j = 0; j < c - 1; j++){ //��� ���� ����� ������������ ��� ���������
            //������ �� �������� ��� ����� ��� ������ ��� ������������ �� �������� ���
            //�����, ���� ��� �������� ��� �� ������, ������������� ���� ��� 2x2 �����
            int sum = *(arr+i*c+j) + *(arr+i*c+(j+1)) + *(arr+(i+1)*c+j) + *(arr+(i+1)*c+(j+1));
                if (sum > s){ //�� �� �������� ���� ����� ���������� ��� ��� ��������� ��� ������ ������ �� ����
                    int B[2][2] = { //��������� ��� ����� �� ����� ��� 4 �����
                        {*(arr+i*c+j),*(arr+i*c+(j+1))},
                        {*(arr+(i+1)*c+j),*(arr+(i+1)*c+(j+1))}
                    };
                    cout<<"This sub-array's elements have a sum bigger than c:"<<endl;
                    print_array((int*)B, 2, 2); //������ ��� ����  ��� ���-������ ��� ����������� ���� ��������� ����������, ���� ���� ������ print_array
                }
        }
    }
}

//��� ������� � ����� �������� ��� ��� main ��� ��� ������ ��� ������ ��� ����� �� ���������� ��� ����������� 2 ����� ������ ��� ����������� ���� ������
void add_arrays(int *arr1, int *arr2, int r, int c){ //
    int S[r][c]; //������������ ���� ������ ��� ���� ����� ���������� �� ��� ������ ��� ������� � ������� �� ������
    for(int i = 0; i < r; i++){ //��� ���� ������
        for(int j = 0; j < c; j++){ //��� ���� �����
            if(*(arr1+i*c+j) == 0 && *(arr2+i*c+j) == 0){ // �� ��� �� ��� ����� ��� ��������� ��� ������ ����� �����
                S[i][j] = 0; //� ���� ��� ��������� ��� ������ S �� ����� 0
            }
            else if (*(arr1+i*c+j) == 0){ //�� � ���� ��� ��������� ��� 1�� ������ ����� 0
                S[i][j] = *(arr2+i*c+j); //� ���� ��� ��������� ��� ������ S �� ����� � ���� ��� ����� ������
            }
            else if (*(arr2+i*c+j) == 0){ //��� �� ����������
                S[i][j] = *(arr1+i*c+j);
            }
            else{ //������ �� ����� ��� ��� 2 ����� ��� ����� �����
                S[i][j] = *(arr1+i*c+j) + *(arr2+i*c+j); ////� ���� ��� ��������� ��� ������ S �� ����� �� ��������
            }
        }
    }
    print_array((int*)S, r, c); //������ ��� ����  ��� ������-�������� ��� ����������� ���� ��������� ����������, ���� ���� ������ print_array
}

int main() // main �������, ��� �������� � �������� ��� ������������
{
    //�������� ������� ��� �� ��� � ������� ������ �� ������������ ��� ��������
    cout<<"This program will execute two functions on sparse matrices."<<endl;
    cout<<"The first function is addition of two sparse matrices."<<endl;
    cout<<"The second function will return a sub-matrix 2x2 of a sparse matrix, with sum of its elements greater than a variable."<<endl;
    string answer = ""; //��������� � ����� �� ���������� ��� �������� ��� ������
    const string exit = "exit"; //��� constant (�������) ��������� ��� ���������� ��� ���� 'exit'
    const string y = "y"; //��� constant (�������) ��������� ��� ���������� ��� ���� 'y'
    const string n = "n"; //��� constant (�������) ��������� ��� ���������� ��� ���� 'n'
    do{ //�� ��������� �� ������ ���� �� ��� ��������� ��� ���������� �� � ������� ������ ��� ����� 'exit'
        cout<<"Type 'a' or 'b' to choose between the two functions or 'exit' to terminate program."<<endl;
        cin>>answer; //������� ��� �������� ��� ������
        if(answer == "a"){ //�� �������� 'a' ���� ������ �� 1� ������� ��� ��������
            cout<<"Do you want two random sparse matrices to be generated?";
            string answer3 = ""; //��������� ��� ���������� ��� �������� ��� ������ ������� �� �� �� ����� �� ������������ ����������� ��� 2 ������ � ���
            do{ //��������� ��� ������� �� � ������� ����� ����� ������ ��� ���������� �� � ������� ����� 'y' � 'n'
                cout<<" y/n ?"<<endl;
                cin>>answer3;
            }while(answer3 != y && answer3 != n);

            if(answer3 == y){ //�� � ������� ������� �� ��������� �� ������ ������
                int rows = (rand()%10) + 1; //������� ������� ��� ������
                int cols = (rand()%10) + 1; //������� ������� ��� ������
                int A[rows][cols]; //������������ ��� 2 ������
                int B[rows][cols];
                std::fill(A[0], A[0] + rows * cols, 0); //��� ������ �� ��������
                std::fill(B[0], B[0] + rows * cols, 0);
                int p1, p2; //��� ���������� ��� �� ����������� ���� ������ ������
                for (int i = 0; i < rows; i++){ //��� ���� ������
                    for (int j = 0; j < cols; j++){ //��� ���� �����
                        p1 = rand()%100; //���� ������� ������� ����� 100
                        p2 = rand()%100;
                        if(p1 > 75){ //�� ����� ���� ��� 75, ����� 25% ����������
                            int number = (rand()%50) + 1; //�� �������� ��� ������ �� ����� ���� ����� ������� �������
                            A[i][j] = number;
                        }
                        if(p2 > 75){
                            int number = (rand()%50) + 1;
                            B[i][j] = number;
                        }
                    }
                }
                //�������� ��� 2 ������ ���� ��� ������� print_array ��������� ��� ���� ��� ������ ��� ����������� ���� ��������� ���������� ��� ��� ������ ������, ������
                cout<<"The two matrices."<<endl;
                print_array((int*)A, rows, cols);
                cout<<"+"<<endl;
                print_array((int*)B, rows, cols);
                cout<<"="<<endl;
                //���� ��� ������ add_arrays ��� ����� ��� 2 ������ ��� �� ����������
                add_arrays((int*)A,(int*)B, rows, cols);
            }

            else if(answer3 == n){ //�� � ������� ������� �� ������� ��� ������ �����������
                cout<<"You will create and fill two matrices manually."<<endl;
                cout<<"Choose number of rows."<<endl; //�������� ������ ������ (������ ��� ���� 2 ������)
                int rows;
                do{ //��������� ��� ������� ��� � ������� �� ����� ����� ������
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>rows;
                }while(rows <= 0 && rows > 20);

                cout<<"Choose number of columns."<<endl; //�������� ������ ������ (������ ��� ���� 2 ������)
                int cols;
                do{ //��������� ��� ������� ��� � ������� �� ����� ����� ������
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>cols;
                }while(cols <= 0 && cols > 20);

                int A[rows][cols]; //���������� ��� 2 ������
                int B[rows][cols];
                cout<<"Fill your first matrix with numbers"<<endl;
                for(int i = 0; i < rows; i++){ //��� ���� ������
                    for(int j = 0; j < cols; j++){ //��� ���� �����
                        int num;
                        cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl; //����������� � ���� ��� ��������� ���� �����
                        cin>>num;
                        while(cin.fail()){ //��������� ��� ������� ��� � ������� �� ����� ����� ������
                            cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl;
                            cin.clear();
                            cin.ignore(256,'\n');
                            cin>>num;
                        }
                        A[i][j] = num; //���� �� �������� �� ��� ������ ��� ������
                    }
                }
                cout<<"Fill your second matrix with numbers"<<endl;
                for(int i = 0; i < rows; i++){ //��� ���� ������
                    for(int j = 0; j < cols; j++){ //��� ���� �����
                        int num;
                        cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl; //����������� � ���� ��� ��������� ���� �����
                        cin>>num;
                        while(cin.fail()){
                            cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl; //��������� ��� ������� ��� � ������� �� ����� ����� ������
                            cin.clear();
                            cin.ignore(256,'\n');
                            cin>>num;
                        }
                        B[i][j] = num; //���� �� �������� �� ��� ������ ��� ������
                    }
                }
                //�������� ��� 2 ������ ���� ��� ������� print_array ��������� ��� ���� ��� ������ ��� ����������� ���� ��������� ���������� ��� ��� ������ ������, ������
                cout<<"The two matrices."<<endl;
                print_array((int*)A, rows, cols);
                cout<<"+"<<endl;
                print_array((int*)B, rows, cols);
                cout<<"="<<endl;
                //���� ��� ������ add_arrays ��� ����� ��� 2 ������ ��� �� ����������
                add_arrays((int*)A,(int*)B, rows, cols);
            }
        }
        else if(answer == "b"){ //�� �������� 'b' ���� ������ �� 2� ������� ��� ��������
            cout<<"Do you want a random sparse matrix and a random variable to be generated?";
            string answer2 = "";//��������� ��� ���������� ��� �������� ��� ������ ������� �� �� �� ����� �� ������������ ����������� ��� 2 ������ � ���
            do{ //��������� ��� ������� �� � ������� ����� ����� ������ ��� ���������� �� � ������� ����� 'y' � 'n'
                cout<<" y/n ?"<<endl;
                cin>>answer2;
            }while(answer2 != y && answer2 != n);

            if(answer2 == y){ //�� � ������� ������� �� ��������� �� ������ ������
                int rows = (rand()%10) + 2; //������� ������� ��� ������
                int cols = (rand()%10) + 2; //������� ������� ��� ������
                int A[rows][cols]; //������������ ��� ������
                std::fill(A[0], A[0] + rows * cols, 0); //��� ������ �� ��������
                int p; //���������� ��� �� ���������� ���� ������ ������
                for (int i = 0; i < rows; i++){ //��� ���� ������
                    for (int j = 0; j < cols; j++){ //��� ���� �����
                        p = rand()%100; //���� ������� ������� ����� 100
                        if(p > 75){ //�� ����� ���� ��� 75, ����� 25% ����������
                            int number = (rand()%50) + 1;
                            A[i][j] = number;
                        }
                    }
                }
                int c = (rand() % 100) + 1; //� ��������� ��� ����� �� �������� ��� ��������� ��� ��������� ������� �� ����� ����������
                print_array((int*)A, rows, cols); //���� ��� ������ prinjt_array ��� ������ ��� ����� ��� �� ��� ��������
                cout<<"The variable is: "<<c<<endl;
                find_subarray((int*)A,rows,cols,c); //���� ��� ������ find_subarray ��� ����� ��� �����, ������ ������, ������ ������ ��� ��� ���������
            }
            else if(answer2 == n){ //�� � ������� ������� �� ������� ��� ����� �����������
                cout<<"You will create and fill a matrix manually."<<endl;
                cout<<"Choose number of rows."<<endl;
                int rows;
                do{ //��������� ��� ������� ��� � ������� �� ����� ����� ������
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>rows;
                }while(rows <= 0 && rows > 20);

                cout<<"Choose number of columns."<<endl;
                int cols;
                do{ //��������� ��� ������� ��� � ������� �� ����� ����� ������
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>cols;
                }while(cols <= 0 && cols > 20);

                int A[rows][cols]; //������������ ��� ������
                cout<<"Fill your matrix with numbers"<<endl;
                for(int i = 0; i < rows; i++){ //��� ���� �����
                    for(int j = 0; j < cols; j++){ //��� ���� �����
                        int num;
                        cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl;
                        cin>>num;
                        while(cin.fail()){ //��������� ��� ������� ��� � ������� �� ����� ����� ������
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
                do{ //��������� ��� ������� ��� � ������� �� ����� ����� ������
                    cout<<"Number must be no greater than 100."<<endl;
                    cin>>c;
                }while(c <= 0 && c > 100);

                print_array((int*)A, rows, cols); //���� ��� ������ prinjt_array ��� ������ ��� ����� ��� �� ��� ��������
                cout<<"The variable is: "<<c<<endl; //�������� �� ��������� ��� ����� �� �������� ��� ��������� ��� ��������� ������� �� ����� ����������
                find_subarray((int*)A,rows,cols,c); //���� ��� ������ find_subarray ��� ����� ��� �����, ������ ������, ������ ������ ��� ��� ���������

            }
        }
    }while(answer != exit); //��� � ������� ��� ����� �� ������ ���� ��� ������� �� ��� ���� ��� ���������� exit, � ����� ����� � ����� 'exit'

    return 0;
}
