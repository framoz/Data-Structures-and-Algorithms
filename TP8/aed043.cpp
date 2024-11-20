#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, vector<int>> movieReviews;

    // Read reviews
    for (int i = 0; i < n; ++i) {
        string movie;
        int score;
        cin >> movie >> score;
        movieReviews[movie].push_back(score);
    }

    // Number of distinct movies
    int distinctMovies = movieReviews.size();

    // Variables to find the maximum reviews
    int maxReviews = 0;
    int moviesWithMaxReviews = 0;

    // Count movies with more positive than negative reviews
    int positiveReviewMovies = 0;

    for (auto& entry : movieReviews) {
        const string& movie = entry.first;
        const vector<int>& scores = entry.second;

        // Update max reviews and count movies with max reviews
        int reviewCount = scores.size();
        if (reviewCount > maxReviews) {
            maxReviews = reviewCount;
            moviesWithMaxReviews = 1;
        } else if (reviewCount == maxReviews) {
            ++moviesWithMaxReviews;
        }

        // Count positive and negative reviews
        int positive = 0, negative = 0;
        for (int score : scores) {
            if (score >= 5) {
                ++positive;
            } else {
                ++negative;
            }
        }
        if (positive > negative) {
            ++positiveReviewMovies;
        }
    }

    // Output results
    cout << distinctMovies << endl;
    cout << maxReviews << " " << moviesWithMaxReviews << endl;
    cout << positiveReviewMovies << endl;

    return 0;
}
