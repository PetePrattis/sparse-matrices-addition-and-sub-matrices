#include <iostream>
#include <cstdlib>
#include <ctime>
#include<stdio.h>

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

// ��� ����������� Node � ������ �������������� ��� ����� �����
struct Node {
    int value; // � ����
    int rowp; // � ���� ���� ������
    int colp; // � ���� ���� ������
    struct Node *next; // �������
};

// ��� ������� � ����� ���� �������� ���������� ��� ��� ����������� Node
void create_new_Node(struct Node** start, int non_zero_element, int row, int column){
    struct Node *temp, *r;
    temp = *start;
    if (temp == NULL){
        // ��������� ��� ��� Node ��������
        temp = (struct Node *) malloc (sizeof(struct Node));
        temp->value = non_zero_element;
        temp->rowp = row;
        temp->colp = column;
        temp->next = NULL;
        *start = temp;
    }
    else{
        while (temp->next != NULL)
            temp = temp->next;

        // ��������� ��� ��� Node ��������
        r = (struct Node *) malloc (sizeof(struct Node));
        r->value = non_zero_element;
        r->rowp = row;
        r->colp = column;
        r->next = NULL;
        temp->next = r;
    }
}

//���� � ������� ��������� �� ����������� ��� ��������������� ������
void PrintList(struct Node* start){
    struct Node *temp; //��������� ��� ��� ����������� ����� Node
    temp = start;//�� ���������� �� �� ����������� ��� ������ ���� ���� ������

    printf("row_position: ");
    while(temp != NULL){//��� ��� ��� ������ ��� ������������ �������� ��� ������

        printf("%d ", temp->rowp);
        temp = temp->next;// ��� ��� �������
    }
    printf("\n");

    temp = start;//���� ���������� �� ����������� ��� �� �� ����������� ��� ������ ���� ������
    printf("column_postion: ");
    while(temp != NULL){//��� ��� ��� ������ ��� ������������ �������� ��� ������
        printf("%d ", temp->colp);
        temp = temp->next;// ��� ��� �������
    }
    printf("\n");

    temp = start;//���� ���������� �� ����������� ��� �� �� ����������� ��� ������ ���� ������
    printf("Value: ");
    while(temp != NULL){//��� ��� ��� ������ ��� ������������ �������� ��� �����
        printf("%d ", temp->value);
        temp = temp->next;// ��� ��� �������
    }
    printf("\n");
}

//��� ������� � ����� �������� ��� ��� main ��� ��� ������ ��� ������ ��� ����� �� ���������� ��� ����������� 2 ����� ������ ��� ����������� ���� ������
void add_arrays(struct Node* A, struct Node* B, int r, int c){ //
    int S[r][c]; //������������ ���� ������ ��� ���� ����� ���������� �� ��� ������ ��� ������� � ������� �� ������
    std::fill(S[0], S[0] + r * c, 0); //��� ������ �� ��������
    struct Node *temp1;//��������� ��� ��� ����������� ����� Node
    struct Node *temp2;//��������� ��� ��� ����������� ����� Node
    temp1 = A;//�� ���������� �� �� ����������� ��� ������ ���� ���� ������ ����������
    temp2 = B;
    while (temp1 != NULL){//��� ���� ����������� ���� ��� ����� ����������� ����� Node
        S[temp1->rowp][temp1->colp] += temp1->value;//�������� ���� �������� ����� ��� ��� �����
        temp1 = temp1->next;
    }
    while (temp2 != NULL){//��� ���� ����������� ���� ��� ������� ����������� ����� Node
        S[temp2->rowp][temp2->colp] += temp2->value;//�������� ���� �������� ����� ��� ��� �����
        temp2 = temp2->next;
    }

    print_array((int*)S, r, c); //������ ��� ����  ��� ������-�������� ��� ����������� ���� ��������� ����������, ���� ���� ������ print_array
}

//��� ������� � ����� �������� ��� ��� main ��� ��� ������ ���-������ ��� ������ ���� ����� ��� ������� � ������� �� ������
void find_subarray(struct Node* A, int r, int c, int s){
    int B[2][2];// ���� �� ����� � ����� ��� �� ����� �� �������� ���� 2�2 ������ ��� ������� ��� ������
    std::fill(B[0], B[0] + 2 * 2, 0); //��� ������ �� ��������
    int sr = r - 1;// ���� ����� rXc �������� (r-1)X(c-1) ��������� 2�2
    int sc = c - 1;
    int S[sr][sc];// ���� �� ����� � ����� ��� �� ����� �� �������� ���� ��������� ���� ��������� 2�2 ��� ������� ������
    std::fill(S[0], S[0] + sr * sc, 0); //��� ������ �� ��������
    struct Node *temp;//��������� ��� ��� ����������� ����� Node
    temp = A;//�� ���������� �� �� ����������� ��� ������ ���� ���� ������
    for (int i = 0; i < sr; i++){//��� ���� �������� ��� ������ S
        for (int j = 0; j < sc; j++){
            temp = A;//���� ���������� �� ����������� ��� �� �� ����������� ��� ������ ���� ���� ������
            std::fill(B[0], B[0] + 2 * 2, 0); //��� ������ �� ��������
            while (temp != NULL){//��� ���� ����������� ���� ��� ����������� ��� ����� Node
                if(temp->rowp == i && temp->colp == j){//�� � ����� ��� � ����� ��� ����� ����� ����� �� ��� ���� ��� ��������� ��� ������ S
                    B[0][0] = temp->value;//���� � ���� ������� �� ����� ��� ���� ��� 2�2 ������
                    S[i][j] += temp->value;//�������� ��� ���� ��� �������� ��� ������ S
                }
                else if (temp->rowp == i && temp->colp == j + 1){//�� � ����� ����� ���� ��� � ����� ����� + 1 �� ��� ���� ��� ��������� ��� ������ S
                    B[0][1] = temp->value;//���� � ���� ������� �� ����� ��� ���� ��� 2�2 ������
                    S[i][j] += temp->value;//�������� ��� ���� ��� �������� ��� ������ S
                }
                else if (temp->rowp == i + 1 && temp->colp == j){//�� � ����� ����� + 1 ��� � ����� ����� ���� �� ��� ���� ��� ��������� ��� ������ S
                    B[1][0] = temp->value;//���� � ���� ������� �� ����� ��� ���� ��� 2�2 ������
                    S[i][j] += temp->value;//�������� ��� ���� ��� �������� ��� ������ S
                }
                else if (temp->rowp == i +1 && temp->colp == j + 1){//�� � ����� ��� � ����� ��� ����� ����� +1 �� ��� ���� ��� ��������� ��� ������ S
                    B[1][1] = temp->value;//���� � ���� ������� �� ����� ��� ���� ��� 2�2 ������
                    S[i][j] += temp->value;//�������� ��� ���� ��� �������� ��� ������ S
                }
                temp = temp->next;//��� ��� ������� �����������
            }
            if (S[i][j] > s){//�� �� �������� ���� ����� ���������� ��� ��� ��������� ��� ������ ������ �� ����
                cout<<"This sub-array's elements have a sum bigger than c:"<<endl;
                print_array((int*)B, 2, 2); //������ ��� ����  ��� ���-������ ��� ����������� ���� ��������� ����������, ���� ���� ������ print_array
            }
        }
    }
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

                struct Node* A_linked = NULL;//��������� ��� ��� ����������� ����� Node
                struct Node* B_linked = NULL;//��������� ��� ��� ����������� ����� Node

                for (int x = 0; x < rows; x++){//��� ���� ���� ��� ������ ���
                    for (int y = 0; y < cols; y++){
                        if (A[x][y] != 0)//��� �� ��������� ����� ��� ��� ������ ����
                            create_new_Node(&A_linked, A[x][y], x, y);//��� ������ ���� ��� ������� create_new_Node() ��� �� ������ ��� ��� ����������� ����� Node
                    }
                }

                for (int x = 0; x < rows; x++){//��� ���� ���� ��� ������ ���
                    for (int y = 0; y < cols; y++){
                        if (B[x][y] != 0)//��� �� ��������� ����� ��� ��� ������ ����
                            create_new_Node(&B_linked, B[x][y], x, y);//��� ������ ���� ��� ������� create_new_Node() ��� �� ������ ��� ��� ����������� ����� Node
                    }
                }
                //PrintList(A_linked);
                //PrintList(B_linked);
                //���� ��� ������ add_arrays ��� ����� ��� 2 ������ ��� �� ����������
                add_arrays(A_linked,B_linked, rows, cols);

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

                struct Node* A_linked = NULL;//��������� ��� ��� ����������� ����� Node
                struct Node* B_linked = NULL;//��������� ��� ��� ����������� ����� Node

                for (int x = 0; x < rows; x++){//��� ���� ���� ��� ������ ���
                    for (int y = 0; y < cols; y++){
                        if (A[x][y] != 0)//��� �� ��������� ����� ��� ��� ������ ����
                            create_new_Node(&A_linked, A[x][y], x, y);//��� ������ ���� ��� ������� create_new_Node() ��� �� ������ ��� ��� ����������� ����� Node
                    }
                }

                for (int x = 0; x < rows; x++){//��� ���� ���� ��� ������ ���
                    for (int y = 0; y < cols; y++){
                        if (B[x][y] != 0)//��� �� ��������� ����� ��� ��� ������ ����
                            create_new_Node(&B_linked, B[x][y], x, y);//��� ������ ���� ��� ������� create_new_Node() ��� �� ������ ��� ��� ����������� ����� Node
                    }
                }
                //PrintList(A_linked);
                //PrintList(B_linked);
                //���� ��� ������ add_arrays ��� ����� ��� 2 ������ ��� �� ����������
                add_arrays(A_linked,B_linked, rows, cols);
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
                cout<<"The variable c is: "<<c<<endl;

                struct Node* A_linked = NULL;//��������� ��� ��� ����������� ����� Node

                for (int x = 0; x < rows; x++){//��� ���� ���� ��� ������ ���
                    for (int y = 0; y < cols; y++){
                        if (A[x][y] != 0)//��� �� ��������� ����� ��� ��� ������ ����
                            create_new_Node(&A_linked, A[x][y], x, y);//��� ������ ���� ��� ������� create_new_Node() ��� �� ������ ��� ��� ����������� ����� Node
                    }
                }
                //PrintList(A_linked);
                find_subarray(A_linked,rows,cols,c); //���� ��� ������ find_subarray ��� ����� ��� �������������� �����, ������ ������, ������ ������ ��� ��� ���������
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

                struct Node* A_linked = NULL;//��������� ��� ��� ����������� ����� Node

                for (int x = 0; x < rows; x++){//��� ���� ���� ��� ������ ���
                    for (int y = 0; y < cols; y++){
                        if (A[x][y] != 0)//��� �� ��������� ����� ��� ��� ������ ����
                            create_new_Node(&A_linked, A[x][y], x, y);//��� ������ ���� ��� ������� create_new_Node() ��� �� ������ ��� ��� ����������� ����� Node
                    }
                }
                //PrintList(A_linked);
                find_subarray(A_linked,rows,cols,c); //���� ��� ������ find_subarray ��� ����� ��� �������������� �����, ������ ������, ������ ������ ��� ��� ���������
            }
        }
    }while(answer != exit); //��� � ������� ��� ����� �� ������ ���� ��� ������� �� ��� ���� ��� ���������� exit, � ����� ����� � ����� 'exit'

    return 0;
}
