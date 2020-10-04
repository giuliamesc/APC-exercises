/*
 * Check sudoku matrix
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


const size_t SIZE = 9;


int basic_search(const unsigned v[], unsigned n_elements);
int check_rows(const unsigned sudoku[][SIZE]);
int check_cols(const unsigned sudoku[][SIZE]);
int check_regions(const unsigned sudoku[][SIZE]);

// Return:
//         1 if sudoku matrix complies to all Sudoku rules
//        -1 if a row violates the game rules
//        -2 if a column violates the game rules
//        -3 if a region violates the game rules
int check_sudoku(const unsigned sudoku[][SIZE]);

// Create a Sudoku matrix by Lewis' Algorithm
// (https://en.wikipedia.org/wiki/Sudoku_solving_algorithms)
void generate_sudoku(unsigned sudoku[][SIZE]);

int main()
{
    // initialize a sudoku matrix
    unsigned sudoku[SIZE][SIZE] = {
            {1,2,3,4,5,6,7,8,9},
            {2,3,4,5,6,7,8,9,1},
            {3,4,5,6,7,8,9,1,2},
            {4,5,6,7,8,9,1,2,3},
            {5,6,7,8,9,1,2,3,4},
            {6,7,8,9,1,2,3,4,5},
            {7,8,9,1,2,3,4,5,6},
            {8,9,1,2,3,4,5,6,7},
            {9,1,2,3,4,5,6,7,8}
    };

    // check
    int res = check_sudoku(sudoku);
    cout << "check_sudoku returns: " <<  res << endl;

    // initialize another sudoku matrix
    unsigned sudoku2[SIZE][SIZE];
    generate_sudoku(sudoku2);

    // check
    res = check_sudoku(sudoku2);
    cout << "check_sudoku returns: " <<  res << endl;

    return 0;
}

int search_key (const unsigned v[], unsigned n_elements, unsigned key)
{
    unsigned key_found = 0;

    for (size_t i=0; i<n_elements; ++i)
        if (v[i] == key)
            key_found = 1;

    return key_found;
}

int basic_search(const unsigned v[], unsigned n_elements){
    for (unsigned i=1; i<=SIZE; i++){
        int found= search_key(v,SIZE,i);
        if(found!=1) return 0;
    }
    return 1;
}

int check_rows(const unsigned sudoku[][SIZE]){
    for (unsigned i=0; i<SIZE; i++){
    unsigned row[SIZE]={};
        for (unsigned j=0; j<SIZE; j++){
            row[j]=sudoku[i][j];
        }
    int res=basic_search(row,SIZE);
    if (res==0) return -1;
    }
    return 0;
}

int check_cols(const unsigned sudoku[][SIZE]){
    for (unsigned i=0; i<SIZE; i++){
        unsigned col[SIZE]={};
        for (unsigned j=0; j<SIZE; j++){
            col[j]=sudoku[j][i];
        }
        int res=basic_search(col,SIZE);
        if (res==0) return -2;
    }
    return 0;
}

int check_regions(const unsigned sudoku[][SIZE]) {
            for (unsigned i : {1,4,7}) {
                for (unsigned j : {1, 4, 7}) {
                    unsigned reg[SIZE] = {sudoku[i - 1][j - 1], sudoku[i - 1][j], sudoku[i - 1][j + 1], sudoku[i][j - 1], sudoku[i][j],
                           sudoku[i][j + 1], sudoku[i + 1][j - 1], sudoku[i + 1][j], sudoku[i + 1][j + 1]};
                    int res = basic_search(reg, SIZE);
                    if (res == 0) return -3;
                }
            }
    return 0;
}

int check_sudoku(const unsigned sudoku[][SIZE])
{
   if (check_rows(sudoku)!=0) return -1;
   if (check_cols(sudoku)!=0) return -2;
   if (check_regions(sudoku)!=0) return -3;
   else return 0;
}

void generate_sudoku(unsigned sudoku[][SIZE])
{
    int x = 0;
    for (size_t i=1; i<=3; ++i)
    {
        for (size_t j=1; j<=3; ++j)
        {
            for (size_t k=1; k<=SIZE; ++k)
            {
                sudoku[3*(i-1)+j-1][k-1] = (x % SIZE) + 1;
                x++;
            }
            x += 3;
        }
        x++;
    }
}