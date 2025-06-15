#include <stdio.h>
#include "needleman_wunsch.h"

int main() {
    double seq1[] = {1.0, 2.0, 3.0};
    double seq2[] = {1.0, 2.0, 4.0};
    double score = needleman_wunsch(seq1, 3, seq2, 3, 2.0, -1.0, -2.0);
    printf("Needleman-Wunsch Score: %.2f\n", score);
    return 0;
}