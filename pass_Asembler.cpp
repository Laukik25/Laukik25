#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char *code[9][4] = {
        {"PRG1", "START", "", ""},
        {"", "USING", "*", "15"},
        {"L", "1", "FOUR", ""},
        {"A", "1", "FIVE", ""},
        {"ST", "1", "TEMP", ""},
        {"FOUR", "DC", "F", "4"},
        {"FIVE", "DC", "F", "5"},
        {"TEMP", "DS", "1F", ""},
        {"", "END", "", ""}
    };

    char av[2], avail[16];
    int lc[9] = {0}, loc = 0;
    int i, j, k;

    // Initialize register availability
    for (i = 0; i < 16; i++)
        avail[i] = 'N';

    cout << "------------------------------------------------------\n";
    cout << "LABEL\tOPCODE\tOPERAND1\tOPERAND2\n";
    cout << "------------------------------------------------------\n";

    // Display the code matrix
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            cout << code[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n------------------------------------------------------\n";
    cout << "PASS 1: INTERMEDIATE PROCESSING\n";
    cout << "------------------------------------------------------\n";

    // Location counter calculation
    for (i = 0; i < 9; i++) {
        if (strcmp(code[i][1], "START") == 0)
            lc[i] = 0;
        else if (strcmp(code[i][1], "DC") == 0)
            lc[i] = loc += 4;
        else if (strcmp(code[i][1], "DS") == 0)
            lc[i] = loc += 4;
        else if (strcmp(code[i][1], "USING") == 0)
            lc[i] = loc;
        else if (strcmp(code[i][1], "END") == 0)
            lc[i] = loc;
        else
            lc[i] = loc += 4;
    }

    cout << "\nLABEL\tLC\n";
    cout << "-----------------\n";
    for (i = 0; i < 9; i++) {
        cout << code[i][0] << "\t" << lc[i] << endl;
    }

    cout << "\n------------------------------------------------------\n";
    cout << "SYMBOL TABLE\n";
    cout << "------------------------------------------------------\n";
    cout << "SYMBOL\tVALUE\n";
    cout << "-----------------\n";
    for (i = 0; i < 9; i++) {
        if (strcmp(code[i][0], "") != 0)
            cout << code[i][0] << "\t" << lc[i] << endl;
    }

    cout << "\n------------------------------------------------------\n";
    cout << "BASE TABLE\n";
    cout << "------------------------------------------------------\n";
    cout << "REG NO\tAVAILABILITY\n";
    cout << "-----------------\n";
    for (i = 0; i < 16; i++) {
        cout << i << "\t" << avail[i] << endl;
    }

    cout << "\n------------------------------------------------------\n";
    cout << "PASS 2: FINAL ASSEMBLER OUTPUT\n";
    cout << "------------------------------------------------------\n";
    cout << "LABEL\tOPCODE\tOPERAND1\tOPERAND2\tLC\n";
    cout << "------------------------------------------------------\n";

    for (i = 0; i < 9; i++) {
        cout << code[i][0] << "\t" << code[i][1] << "\t" << code[i][2] << "\t" << code[i][3] << "\t" << lc[i] << endl;
    }

    cout << "------------------------------------------------------\n";
    return 0;
}
