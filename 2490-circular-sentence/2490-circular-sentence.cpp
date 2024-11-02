class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        string s = "";
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] != ' ') {
                s += sentence[i];
            } else {
                words.push_back(s);
                s = "";
            }
        }
        words.push_back(s);
        for (int i = 0; i < words.size(); i++) {
            string currentWord = words[i];
            if (i != words.size() - 1) {
                string nextWord = words[i + 1];
                if (tolower(currentWord[currentWord.size() - 1]) !=
                    tolower(nextWord[0])) {
                    return false;
                }
            } else {
                string nextWord = words[0];
                if (tolower(currentWord[currentWord.size() - 1]) !=
                    tolower(nextWord[0])) {
                    return false;
                }
            }
        }
        return true;
    }
};