#include <bits/stdc++.h>
using namespace std;

pair<int,int> bullsAndCows(string secret, string guess) {
    int bulls = 0, cows = 0;
    unordered_map<char,int> countSecret, countGuess;
    for(int i=0; i<(int)secret.size(); i++) {
        if(secret[i] == guess[i]) bulls++;
        else {
            countSecret[secret[i]]++;
            countGuess[guess[i]]++;
        }
    }
    for(auto& p : countSecret) {
        cows += min(p.second, countGuess[p.first]);
    }
    return {bulls, cows};
}

int main() {
    auto res = bullsAndCows("1807", "7810");
    cout << "Bulls: " << res.first << ", Cows: " << res.second << '\n';
    return 0;
}
