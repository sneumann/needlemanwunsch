#include <stdio.h>
#include "needleman_wunsch.h"

int main() {
    const char* seq1 = "ACGT";
    const char* seq2 = "ACCT";
    double score = needleman_wunsch(seq1, 4, seq2, 4, 2.0, -1.0, -2.0);
    printf("Needleman-Wunsch Score: %.2f\n", score);
    return 0;
}