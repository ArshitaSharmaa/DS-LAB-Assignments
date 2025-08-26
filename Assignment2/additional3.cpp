#include <iostream>
#include <vector>
using namespace std;

bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    vector<int> freq(26, 0);
    int n = str1.length();

    for (int i = 0; i < n; i++) {
        freq[str1[i] - 'a']++;
    }

    for (int i = 0; i < n; i++) {
        freq[str2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) return false;
    }

    return true;
}

int main() {
    string str1 = "listen";
    string str2 = "silent";

    if (areAnagrams(str1, str2))
        cout << "Anagram Pair";
    else
        cout << "Not Anagram Pair";

    return 0;
}
