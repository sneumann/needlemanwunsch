#include "needleman_wunsch.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EQ(a, b) (fabs((a)-(b)) < 1e-6)

void test_typical_case() {
    const char* seq1 = "ACGT";
    const char* seq2 = "ACCT";
    double score = needleman_wunsch(seq1, 4, seq2, 4, 2.0, -1.0, -2.0);
    // match, match, mismatch, match: 2+2-1+2 = 5
    assert(EQ(score, 5.0));
}

void test_empty_sequences() {
    const char* seq1 = "";
    const char* seq2 = "";
    double score = needleman_wunsch(seq1, 0, seq2, 0, 2.0, -1.0, -2.0);
    assert(EQ(score, 0.0));
}

void test_one_empty() {
    const char* seq1 = "AC";
    const char* seq2 = "";
    double score = needleman_wunsch(seq1, 2, seq2, 0, 2.0, -1.0, -2.0);
    // Zwei Gaps: -2 + -2 = -4
    assert(EQ(score, -4.0));
}

void test_all_mismatch() {
    const char* seq1 = "AA";
    const char* seq2 = "CC";
    double score = needleman_wunsch(seq1, 2, seq2, 2, 2.0, -1.0, -2.0);
    // Zwei Mismatches: -1 + -1 = -2
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
