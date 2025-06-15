#ifndef NEEDLEMAN_WUNSCH_H
#define NEEDLEMAN_WUNSCH_H

#include <stddef.h>

double needleman_wunsch(
    const char* seq1, size_t len1,
    const char* seq2, size_t len2,
    double match_score,
    double mismatch_penalty,
    double gap_penalty
);

#endif // NEEDLEMAN_WUNSCH_H
