#include <iostream>
#include <cstdlib>
#include <ctime>
#include<stdio.h>

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

// A Node struct that represents a sparse matrix
struct Node {
    int value; // the value
    int rowp; // the row position
    int colp; // the column position
    struct Node *next; // next Node
};

// a function that is called when a new Node struct is created
void create_new_Node(struct Node** start, int non_zero_element, int row, int column){
    struct Node *temp, *r;
    temp = *start;
    if (temp == NULL){
        // create new Node dynamically
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

        // create new Node dynamically
        r = (struct Node *) malloc (sizeof(struct Node));
        r->value = non_zero_element;
        r->rowp = row;
        r->colp = column;
        r->next = NULL;
        temp->next = r;
    }
}

// this function prints the objects of the linked-list
void PrintList(struct Node* start){
    struct Node *temp; //create a new struct of Node type
    temp = start;// insert the value that i passed through the function

    printf("row_position: ");
    while(temp != NULL){//for all objects print the row

        printf("%d ", temp->rowp);
        temp = temp->next;// go to next
    }
    printf("\n");

    temp = start;//insert the value passed through the funcation
    printf("column_postion: ");
    while(temp != NULL){//for all objects print the column
        printf("%d ", temp->colp);
        temp = temp->next;// go to next
    }
    printf("\n");

    temp = start;//insert the value passed through the funcation
    printf("Value: ");
    while(temp != NULL){//for all objects print the value
        printf("%d ", temp->value);
        temp = temp->next;// go to next
    }
    printf("\n");
}

//function that is called by main to find array that is the result of the addition of values of two linked-lists
void add_arrays(struct Node* A, struct Node* B, int r, int c){ //
    int S[r][c]; //initialize an array with same dimensions as the arrays passed through the funcation
    std::fill(S[0], S[0] + r * c, 0); //insert zero values
    struct Node *temp1;//create new struct of Node type
    struct Node *temp2;//create new struct of Node type
    temp1 = A;//insert values to the structs
    temp2 = B;
    while (temp1 != NULL){//for all objects inside the first struct of Node type
        S[temp1->rowp][temp1->colp] += temp1->value;//add to the S array the values
        temp1 = temp1->next;
    }
    while (temp2 != NULL){//for all objects inside the second struct of Node type
        S[temp2->rowp][temp2->colp] += temp2->value;//add to the S array the values
        temp2 = temp2->next;
    }

    print_array((int*)S, r, c); //pass the value of the list-sum corresponding to the referral address in the print_array method
}

//function that is called by main to find sub array of the linked-list passed through the function
void find_subarray(struct Node* A, int r, int c, int s){
    int B[2][2];// this will be the array that saves the data of each 2X2 table of our original table
    std::fill(B[0], B[0] + 2 * 2, 0); //fill with zero values
    int sr = r - 1;// every array with dimensions rXc contains (r-1)X(c-1) sub arrays of 2Χ2 dimensions
    int sc = c - 1;
    int S[sr][sc];// this will be the array that saves the sum of each element of each 2x2 sub array of the original array
    std::fill(S[0], S[0] + sr * sc, 0); //fill with zeros
    struct Node *temp;/
    temp = A;
    for (int i = 0; i < sr; i++){//for every value inside the S array
        for (int j = 0; j < sc; j++){
            temp = A;
            std::fill(B[0], B[0] + 2 * 2, 0); //fill with zeros
            while (temp != NULL){//for all objects inside the struct of Node type
                if(temp->rowp == i && temp->colp == j){//if column and row are the same as the value's location
                    B[0][0] = temp->value;//we start building the sub 2X2 array
                    S[i][j] += temp->value;//add the value at the S array
                }//we do the same for all 4 elements of the 2X2 sub array
                else if (temp->rowp == i && temp->colp == j + 1){
                    B[0][1] = temp->value;
                    S[i][j] += temp->value;
                }
                else if (temp->rowp == i + 1 && temp->colp == j){
                    B[1][0] = temp->value;
                    S[i][j] += temp->value;
                }
                else if (temp->rowp == i +1 && temp->colp == j + 1){
                    B[1][1] = temp->value;
                    S[i][j] += temp->value;
                }
                temp = temp->next;//go to next struct
            }
            if (S[i][j] > s){//if the sum saved inside the S array is greater than c then we print the sub array
                cout<<"This sub-array's elements have a sum bigger than c:"<<endl;
                print_array((int*)B, 2, 2);
            }
        }
    }
}

int main() // main μέθοδος, εδώ ξεκινάει η εκτέλεση του προγράμματος
{
    //εκτυπώνω οδηγίες για το πως ο χρήστης μπορεί να διαχειριστεί την εφαρμογή
    cout<<"This program will execute two functions on sparse matrices."<<endl;
    cout<<"The first function is addition of two sparse matrices."<<endl;
    cout<<"The second function will return a sub-matrix 2x2 of a sparse matrix, with sum of its elements greater than a variable."<<endl;
    string answer = ""; //μεταβλητή η οποία θα αποθηκεύει την απάντηση του χρήστη
    const string exit = "exit"; //μια constant (σταθερή) μεταβλητή που αποθηκεύει την τιμή 'exit'
    const string y = "y"; //μια constant (σταθερή) μεταβλητή που αποθηκεύει την τιμή 'y'
    const string n = "n"; //μια constant (σταθερή) μεταβλητή που αποθηκεύει την τιμή 'n'
    do{ //το πρόγραμμα θα τρέχει μέσα σε μια επανάληψη που τερματίζει αν ο χρήστης γράψει την λέξει 'exit'
        cout<<"Type 'a' or 'b' to choose between the two functions or 'exit' to terminate program."<<endl;
        cin>>answer; //διαβάζω την απάντηση του χρήστη
        if(answer == "a"){ //αν απάντησε 'a' τότε εκτελώ το 1ο ερώτημα της εργασίας
            cout<<"Do you want two random sparse matrices to be generated?";
            string answer3 = ""; //μεταβλητή που αποθηκεύει την απάντηση του χρήστη σχετικά με το αν θέλει να δημιουργήσει χειροκίνητα τις 2 μήτρες ή όχι
            do{ //επανάληψη που ελέγχει αν ο χρήστης έδωσε σωστή είσοδο και τερματίζει αν η είσοδος είναι 'y' ή 'n'
                cout<<" y/n ?"<<endl;
                cin>>answer3;
            }while(answer3 != y && answer3 != n);

            if(answer3 == y){ //αν ο χρήστης επέλεξε να φτιαχτούν οι μήτρες τυχαία
                int rows = (rand()%10) + 1; //τυχαίος αριθμός για σειρές
                int cols = (rand()%10) + 1; //τυχαίος αριθμός για στήλες
                int A[rows][cols]; //αρχικοποίηση των 2 μητρών
                int B[rows][cols];
                std::fill(A[0], A[0] + rows * cols, 0); //τις γεμίζω με μηδενικά
                std::fill(B[0], B[0] + rows * cols, 0);
                int p1, p2; //δυο μεταβλητές που θα αποθηκεύουν έναν τυχαίο αριθμό
                for (int i = 0; i < rows; i++){ //για κάθε γραμμή
                    for (int j = 0; j < cols; j++){ //για κάθε στήλη
                        p1 = rand()%100; //ένας τυχαίος αριθμός μέχρι 100
                        p2 = rand()%100;
                        if(p1 > 75){ //αν είναι πάνω απο 75, δλαδή 25% πιθανότητα
                            int number = (rand()%50) + 1; //το στοιχείο της λίστας θα είναι ένας άλλος τυχαίος αριθμός
                            A[i][j] = number;
                        }
                        if(p2 > 75){
                            int number = (rand()%50) + 1;
                            B[i][j] = number;
                        }
                    }
                }
                //εκτυπώνω τις 2 μήτρες μέσω της μεθόδου print_array περνόντας την τιμή της λίστας που αντιστοιχεί στην διεύθυνση παραπομπής της και αριθμό σειρών, στηλών
                cout<<"The two matrices."<<endl;
                print_array((int*)A, rows, cols);
                cout<<"+"<<endl;
                print_array((int*)B, rows, cols);
                cout<<"="<<endl;

                struct Node* A_linked = NULL;//δημιουργώ ένα νέο αντικείμενο τύπου Node
                struct Node* B_linked = NULL;//δημιουργώ ένα νέο αντικείμενο τύπου Node

                for (int x = 0; x < rows; x++){//για κάθε τιμή της μήτρας μου
                    for (int y = 0; y < cols; y++){
                        if (A[x][y] != 0)//τις μη μηδενικές τιμές και τις θέσεις τους
                            create_new_Node(&A_linked, A[x][y], x, y);//τις περνάω μέσω της μεθόδου create_new_Node() για να φτιάξω ένα νέο αντικείμενο τύπου Node
                    }
                }

                for (int x = 0; x < rows; x++){//για κάθε τιμή της μήτρας μου
                    for (int y = 0; y < cols; y++){
                        if (B[x][y] != 0)//τις μη μηδενικές τιμές και τις θέσεις τους
                            create_new_Node(&B_linked, B[x][y], x, y);//τις περνάω μέσω της μεθόδου create_new_Node() για να φτιάξω ένα νέο αντικείμενο τύπου Node
                    }
                }
                //PrintList(A_linked);
                //PrintList(B_linked);
                //καλώ την μέθοδο add_arrays και περνώ τις 2 μήτρες για να προστεθούν
                add_arrays(A_linked,B_linked, rows, cols);

            }

            else if(answer3 == n){ //αν ο χρήστης επέλεξε να φτιάξει της μήτρες χειροκίνητα
                cout<<"You will create and fill two matrices manually."<<endl;
                cout<<"Choose number of rows."<<endl; //διαλέγει αριθμό σειρών (κοινός και στις 2 μήτρες)
                int rows;
                do{ //επανάληψη που ελέγχει οτι ο χρήστης θα δώσει σωστή είσοδο
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>rows;
                }while(rows <= 0 && rows > 20);

                cout<<"Choose number of columns."<<endl; //διαλέγει αριθμό στηλων (κοινός και στις 2 μήτρες)
                int cols;
                do{ //επανάληψη που ελέγχει οτι ο χρήστης θα δώσει σωστή είσοδο
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>cols;
                }while(cols <= 0 && cols > 20);

                int A[rows][cols]; //αρχικοποιώ τις 2 μήτρες
                int B[rows][cols];
                cout<<"Fill your first matrix with numbers"<<endl;
                for(int i = 0; i < rows; i++){ //για κάθε γραμμή
                    for(int j = 0; j < cols; j++){ //για κάθε στήλη
                        int num;
                        cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl; //εμφανίζεται η θέση του στοιχείου στην μήτρα
                        cin>>num;
                        while(cin.fail()){ //επανάληψη που ελέγχει οτι ο χρήστης θα δώσει σωστή είσοδο
                            cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl;
                            cin.clear();
                            cin.ignore(256,'\n');
                            cin>>num;
                        }
                        A[i][j] = num; //θέτω το στοιχείο με την είσοδο του χρήστη
                    }
                }
                cout<<"Fill your second matrix with numbers"<<endl;
                for(int i = 0; i < rows; i++){ //για κάθε γραμμή
                    for(int j = 0; j < cols; j++){ //για κάθε στήλη
                        int num;
                        cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl; //εμφανίζεται η θέση του στοιχείου στην μήτρα
                        cin>>num;
                        while(cin.fail()){
                            cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl; //επανάληψη που ελέγχει οτι ο χρήστης θα δώσει σωστή είσοδο
                            cin.clear();
                            cin.ignore(256,'\n');
                            cin>>num;
                        }
                        B[i][j] = num; //θέτω το στοιχείο με την είσοδο του χρήστη
                    }
                }
                //εκτυπώνω τις 2 μήτρες μέσω της μεθόδου print_array περνόντας την τιμή της λίστας που αντιστοιχεί στην διεύθυνση παραπομπής της και αριθμό σειρών, στηλών
                cout<<"The two matrices."<<endl;
                print_array((int*)A, rows, cols);
                cout<<"+"<<endl;
                print_array((int*)B, rows, cols);
                cout<<"="<<endl;

                struct Node* A_linked = NULL;//δημιουργώ ένα νέο αντικείμενο τύπου Node
                struct Node* B_linked = NULL;//δημιουργώ ένα νέο αντικείμενο τύπου Node

                for (int x = 0; x < rows; x++){//για κάθε τιμή της μήτρας μου
                    for (int y = 0; y < cols; y++){
                        if (A[x][y] != 0)//τις μη μηδενικές τιμές και τις θέσεις τους
                            create_new_Node(&A_linked, A[x][y], x, y);//τις περνάω μέσω της μεθόδου create_new_Node() για να φτιάξω ένα νέο αντικείμενο τύπου Node
                    }
                }

                for (int x = 0; x < rows; x++){//για κάθε τιμή της μήτρας μου
                    for (int y = 0; y < cols; y++){
                        if (B[x][y] != 0)//τις μη μηδενικές τιμές και τις θέσεις τους
                            create_new_Node(&B_linked, B[x][y], x, y);//τις περνάω μέσω της μεθόδου create_new_Node() για να φτιάξω ένα νέο αντικείμενο τύπου Node
                    }
                }
                //PrintList(A_linked);
                //PrintList(B_linked);
                //καλώ την μέθοδο add_arrays και περνώ τις 2 μήτρες για να προστεθούν
                add_arrays(A_linked,B_linked, rows, cols);
            }
        }
        else if(answer == "b"){ //αν απάντησε 'b' τότε εκτελώ το 2ο ερώτημα της εργασίας
            cout<<"Do you want a random sparse matrix and a random variable to be generated?";
            string answer2 = "";//μεταβλητή που αποθηκεύει την απάντηση του χρήστη σχετικά με το αν θέλει να δημιουργήσει χειροκίνητα τις 2 μήτρες ή όχι
            do{ //επανάληψη που ελέγχει αν ο χρήστης έδωσε σωστή είσοδο και τερματίζει αν η είσοδος είναι 'y' ή 'n'
                cout<<" y/n ?"<<endl;
                cin>>answer2;
            }while(answer2 != y && answer2 != n);

            if(answer2 == y){ //αν ο χρήστης επέλεξε να φτιαχτούν οι μήτρες τυχαία
                int rows = (rand()%10) + 2; //τυχαίος αριθμός για σειρές
                int cols = (rand()%10) + 2; //τυχαίος αριθμός για στήλες
                int A[rows][cols]; //αρχικοποίηση της μήτρες
                std::fill(A[0], A[0] + rows * cols, 0); //την γεμίζω με μηδενικά
                int p; //μεταβλητΛη που θα αποθηκεύει έναν τυχαίο αριθμό
                for (int i = 0; i < rows; i++){ //για κάθε γραμμή
                    for (int j = 0; j < cols; j++){ //για κάθε στήλη
                        p = rand()%100; //ένας τυχαίος αριθμός μέχρι 100
                        if(p > 75){ //αν είναι πάνω απο 75, δλαδή 25% πιθανότητα
                            int number = (rand()%50) + 1;
                            A[i][j] = number;
                        }
                    }
                }
                int c = (rand() % 100) + 1; //η μεταβλητή την οποία το άθροισμα των στοιχείων της υπομήτρας πρεέπει να είναι μεγαλύτερο
                print_array((int*)A, rows, cols); //καλώ την μέθοδο prinjt_array και περνάω την μήτρα για να την εκτυπώσω
                cout<<"The variable c is: "<<c<<endl;

                struct Node* A_linked = NULL;//δημιουργώ ένα νέο αντικείμενο τύπου Node

                for (int x = 0; x < rows; x++){//για κάθε τιμή της μήτρας μου
                    for (int y = 0; y < cols; y++){
                        if (A[x][y] != 0)//τις μη μηδενικές τιμές και τις θέσεις τους
                            create_new_Node(&A_linked, A[x][y], x, y);//τις περνάω μέσω της μεθόδου create_new_Node() για να φτιάξω ένα νέο αντικείμενο τύπου Node
                    }
                }
                //PrintList(A_linked);
                find_subarray(A_linked,rows,cols,c); //καλώ την μέθοδο find_subarray και περνώ την διασυνδεδεμένη λίστα, αριθμό σειρών, αριθμό στηλών και την μεταβλητή
            }
            else if(answer2 == n){ //αν ο χρήστης επέλεξε να φτιάξει την μήτρα χειροκίνητα
                cout<<"You will create and fill a matrix manually."<<endl;
                cout<<"Choose number of rows."<<endl;
                int rows;
                do{ //επανάληψη που ελέγχει οτι ο χρήστης θα δώσει σωστή είσοδο
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>rows;
                }while(rows <= 0 && rows > 20);

                cout<<"Choose number of columns."<<endl;
                int cols;
                do{ //επανάληψη που ελέγχει οτι ο χρήστης θα δώσει σωστή είσοδο
                    cout<<"Number must be no greater than 20."<<endl;
                    cin>>cols;
                }while(cols <= 0 && cols > 20);

                int A[rows][cols]; //αρχικοποίηση της μήτρας
                cout<<"Fill your matrix with numbers"<<endl;
                for(int i = 0; i < rows; i++){ //για κάθε σειρά
                    for(int j = 0; j < cols; j++){ //για κάθε στήλη
                        int num;
                        cout<<"Insert number for index: ["<<i<<"]["<<j<<"]"<<endl;
                        cin>>num;
                        while(cin.fail()){ //επανάληψη που ελέγχει οτι ο χρήστης θα δώσει σωστή είσοδο
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
                do{ //επανάληψη που ελέγχει οτι ο χρήστης θα δώσει σωστή είσοδο
                    cout<<"Number must be no greater than 100."<<endl;
                    cin>>c;
                }while(c <= 0 && c > 100);

                print_array((int*)A, rows, cols); //καλώ την μέθοδο prinjt_array και περνάω την μήτρα για να την εκτυπώσω
                cout<<"The variable is: "<<c<<endl; //εμφανίζω τη μεταβλητή την οποία το άθροισμα των στοιχείων της υπομήτρας πρεέπει να είναι μεγαλύτερο

                struct Node* A_linked = NULL;//δημιουργώ ένα νέο αντικείμενο τύπου Node

                for (int x = 0; x < rows; x++){//για κάθε τιμή της μήτρας μου
                    for (int y = 0; y < cols; y++){
                        if (A[x][y] != 0)//τις μη μηδενικές τιμές και τις θέσεις τους
                            create_new_Node(&A_linked, A[x][y], x, y);//τις περνάω μέσω της μεθόδου create_new_Node() για να φτιάξω ένα νέο αντικείμενο τύπου Node
                    }
                }
                //PrintList(A_linked);
                find_subarray(A_linked,rows,cols,c); //καλώ την μέθοδο find_subarray και περνώ την διασυνδεδεμένη λίστα, αριθμό σειρών, αριθμό στηλών και την μεταβλητή
            }
        }
    }while(answer != exit); //όσο ο χρήστης δεν δίνει ως είσοδο τιμή που ισούται με την τιμή της μεταβλητής exit, η οποία είναι η λέξεη 'exit'

    return 0;
}
