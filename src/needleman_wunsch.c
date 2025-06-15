#include "needleman_wunsch.h"
#include <stdlib.h>
#include <math.h>

static int is_match(double a, double b) {
    return fabs(a - b) < 1e-6;
}

double needleman_wunsch(
    const double* seq1, size_t len1,
    const double* seq2, size_t len2,
    double match_score,
    double mismatch_penalty,
    double gap_penalty
) {
    double** dp = malloc((len1 + 1) * sizeof(double*));
    for (size_t i = 0; i <= len1; ++i) {
        dp[i] = malloc((len2 + 1) * sizeof(double));
    }

    dp[0][0] = 0.0;
    for (size_t i = 1; i <= len1; ++i)
        dp[i][0] = dp[i-1][0] + gap_penalty;
    for (size_t j = 1; j <= len2; ++j)
        dp[0][j] = dp[0][j-1] + gap_penalty;

    for (size_t i = 1; i <= len1; ++i) {
        for (size_t j = 1; j <= len2; ++j) {
            double score_diag = dp[i-1][j-1] + (is_match(seq1[i-1], seq2[j-1]) ? match_score : mismatch_penalty);
            double score_up   = dp[i-1][j] + gap_penalty;
            double score_left = dp[i][j-1] + gap_penalty;
            double max_score = score_diag;
            if (score_up > max_score) max_score = score_up;
            if (score_left > max_score) max_score = score_left;
            dp[i][j] = max_score;
        }
    }

    double result = dp[len1][len2];
    for (size_t i = 0; i <= len1; ++i)
        free(dp[i]);
    free(dp);
    return result;
}
