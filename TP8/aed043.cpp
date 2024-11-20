#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<string, vector<int>> reviews;

    // Input reading
    for (int i = 0; i < N; ++i) {
        string movie;
        int score;
        cin >> movie >> score;
        reviews[movie].push_back(score);
    }

    // 1. Number of different movies with at least one review
    int numMovies = reviews.size();

    // Variables for the maximum reviews
    int maxReviews = 0, numMaxMovies = 0;

    // Count of movies with more positive than negative reviews
    int numPositiveMovies = 0;

    for (const auto& [movie, scores] : reviews) {
        // Calculate max reviews and number of movies with max reviews
        int numScores = scores.size();
        if (numScores > maxReviews) {
            maxReviews = numScores;
            numMaxMovies = 1;
        } else if (numScores == maxReviews) {
            ++numMaxMovies;
        }

        // Calculate positive vs negative reviews
        int positiveCount = 0, negativeCount = 0;
        for (int score : scores) {
            if (score >= 5)
                ++positiveCount;
            else
                ++negativeCount;
        }
        if (positiveCount > negativeCount)
            ++numPositiveMovies;
    }

    // Output results
    cout << numMovies << endl;
    cout << maxReviews << " " << numMaxMovies << endl;
    cout << numPositiveMovies << endl;

    return 0;
}
