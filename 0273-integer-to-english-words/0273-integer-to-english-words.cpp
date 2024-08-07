class Solution {
public:
    string get_string(int n) {
        map<int, string> ones_map = {
            {1, "One"},       {2, "Two"},        {3, "Three"},
            {4, "Four"},      {5, "Five"},       {6, "Six"},
            {7, "Seven"},     {8, "Eight"},      {9, "Nine"},
            {10, "Ten"},      {11, "Eleven"},    {12, "Twelve"},
            {13, "Thirteen"}, {14, "Fourteen"},  {15, "Fifteen"},
            {16, "Sixteen"},  {17, "Seventeen"}, {18, "Eighteen"},
            {19, "Nineteen"}};

        map<int, string> tens_map = {
            {20, "Twenty"}, {30, "Thirty"},  {40, "Forty"},  {50, "Fifty"},
            {60, "Sixty"},  {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};
        vector<string> res;
        int hundreds = n / 100;
        if (hundreds) {
            res.push_back(ones_map[hundreds] + " Hundred");
        }
        int last_2 = n % 100;
        if (last_2 >= 20) {
            int tens = last_2 / 10;
            int ones = last_2 % 10;
            res.push_back(tens_map[tens * 10]);
            if (ones) {
                res.push_back(ones_map[ones]);
            }
        } else if (last_2) {
            res.push_back(ones_map[last_2]);
        }
        string result;
        for (auto str : res) {
            if (!result.empty()) {
                result += " ";
            }
            result += str;
        }
        return result;
    }
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        vector<string> postfix = {"", " Thousand", " Million", " Billion"};
        int i = 0;
        vector<string> res;
        while (num) {
            int digits = num % 1000;
            string s = get_string(digits);
            if (!s.empty()) {
                res.push_back(s+postfix[i]);
            }
            num = num / 1000;
            i++;
        }
        reverse(res.begin(), res.end());
        string final_result;
        for (auto& str : res) {
            if (!final_result.empty()) {
                final_result += " ";
            }
            final_result += str;
        }
        return final_result;
    }
};