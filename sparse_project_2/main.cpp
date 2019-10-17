#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//μια μέθοδος η οποία καλείται από την main για την εκτύπωση λιστών
void print_array(int *arr, int r, int c){ //δέχεται ως είσοδο την τιμή της λίστας που αντιστοιχεί στην διεύθυνση παραπομπής της λίστας με χρήση pointer
    for(int i = 0; i < r; i++){ //για κάθε γραμμή
        for(int j = 0; j < c; j++){ //για κάθε στήλη
            cout<<"["<<*(arr+i*c+j)<<"]"; //εκτυπώνω την τιμή της λίστας στο εκάστοτε σημείο
        }
        cout<<endl;
    }
}

//μια μέθοδος η οποία καλείται από την main για την εύρεση υπο-λίστας που ανήκει στην λίστα που δέχεται η μέθοδος ως είσοδο
void find_subarray(int *arr, int r, int c, int s){
    for (int i = 0; i < r - 1; i++){ //για κάθε γραμμή αποκλείοντας την τελευταία
        for (int j = 0; j < c - 1; j++){ //για κάθε στήλη αποκλείοντας την τελευταία
            //βρίσκω το άθροισμα των τιμών της λίστας που αντιστοιχούν σε στοιχεία της
            //δεξία, κάτω και διαγώνια από το σημείο, σχηματίζοντας έτσι μια 2x2 μήτρα
            int sum = *(arr+i*c+j) + *(arr+i*c+(j+1)) + *(arr+(i+1)*c+j) + *(arr+(i+1)*c+(j+1));
                if (sum > s){ //αν το άθροισμα αυτό είναι μεγαλύτερο από την μεταβλητή που έχουμε ορίσει ως όριο
                    int B[2][2] = { //δημιουργώ μια μήτρα με αυτές τις 4 τιμές
                        {*(arr+i*c+j),*(arr+i*c+(j+1))},
                        {*(arr+(i+1)*c+j),*(arr+(i+1)*c+(j+1))}
                    };
                    cout<<"This sub-array's elements have a sum bigger than c:"<<endl;
                    print_array((int*)B, 2, 2); //περνάω την τιμή  της υπο-λίστας που αντιστοιχεί στην διεύθυνση παραπομπής, μέσα στην μέθοδο print_array
                }
        }
    }
}

//μια μέθοδος η οποία καλείται από την main για την εύρεση της μήτρας που είναι το αποτέλεσμα του αθροίσματος 2 άλλων λιστών που περνιούνται στην μέθοδο
void add_arrays(int *arr1, int *arr2, int r, int c){ //
    int S[r][c]; //αρχικοποίηση μιας μήτρας που έχει ίδιες διαστάσεις με τις μήτρες που δέχεται η μέθοδος ως είσοδο
    for(int i = 0; i < r; i++){ //για κάθε γραμμή
        for(int j = 0; j < c; j++){ //για κάθε στήλη
            if(*(arr1+i*c+j) == 0 && *(arr2+i*c+j) == 0){ // αν και οι δυο τιμές των στοιχείων της λίστας είναι μηδέν
                S[i][j] = 0; //η τιμή του στοιχείου της μήτρας S θα είναι 0
            }
            else if (*(arr1+i*c+j) == 0){ //αν η τιμή του στοιχείου της 1ης μήτρας είναι 0
                S[i][j] = *(arr2+i*c+j); //η τιμή του στοιχείου της μήτρας S θα είναι η τιμή της άλλης μήτρας
            }
            else if (*(arr2+i*c+j) == 0){ //και το αντίστροφο
                S[i][j] = *(arr1+i*c+j);
            }
            else{ //αλλιώς αν καμιά από τις 2 τιμές δεν είναι μηδέν
                S[i][j] = *(arr1+i*c+j) + *(arr2+i*c+j); ////η τιμή του στοιχείου της μήτρας S θα είναι το άθροισμα
            }
        }
    }
    print_array((int*)S, r, c); //περνάω την τιμή  της λίστας-άθροισμα που αντιστοιχεί στην διεύθυνση παραπομπής, μέσα στην μέθοδο print_array
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
                //καλώ την μέθοδο add_arrays και περνώ τις 2 μήτρες για να προστεθούν
                add_arrays((int*)A,(int*)B, rows, cols);
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
                //καλώ την μέθοδο add_arrays και περνώ τις 2 μήτρες για να προστεθούν
                add_arrays((int*)A,(int*)B, rows, cols);
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
                cout<<"The variable is: "<<c<<endl;
                find_subarray((int*)A,rows,cols,c); //καλώ την μέθοδο find_subarray και περνώ την μήτρα, αριθμό σειρών, αριθμό στηλών και την μεταβλητή
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
                find_subarray((int*)A,rows,cols,c); //καλώ την μέθοδο find_subarray και περνώ την μήτρα, αριθμό σειρών, αριθμό στηλών και την μεταβλητή

            }
        }
    }while(answer != exit); //όσο ο χρήστης δεν δίνει ως είσοδο τιμή που ισούται με την τιμή της μεταβλητής exit, η οποία είναι η λέξεη 'exit'

    return 0;
}
