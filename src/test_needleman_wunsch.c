#include "needleman_wunsch.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EQ(a, b) (fabs((a)-(b)) < 1e-6)

void test_typical_case() {
    double seq1[] = {1.0, 2.0, 3.0};
    double seq2[] = {1.0, 2.0, 4.0};
    double score = needleman_wunsch(seq1, 3, seq2, 3, 2.0, -1.0, -2.0);
    assert(EQ(score, 3.0));
}

void test_empty_sequences() {
    double seq1[] = {};
    double seq2[] = {};
    double score = needleman_wunsch(seq1, 0, seq2, 0, 2.0, -1.0, -2.0);
    assert(EQ(score, 0.0));
}

void test_one_empty() {
    double seq1[] = {1.0, 2.0};
    double seq2[] = {};
    double score = needleman_wunsch(seq1, 2, seq2, 0, 2.0, -1.0, -2.0);
    assert(EQ(score, -4.0));
}

void test_all_mismatch() {
    double seq1[] = {1.0, 2.0};
    double seq2[] = {3.0, 4.0};
    double score = needleman_wunsch(seq1, 2, seq2, 2, 2.0, -1.0, -2.0);
    assert(EQ(score, -2.0));
}

int main() {
    test_typical_case();
    test_empty_sequences();
    test_one_empty();
    test_all_mismatch();
    printf("Alle Tests bestanden!\n");
    return 0;
}
