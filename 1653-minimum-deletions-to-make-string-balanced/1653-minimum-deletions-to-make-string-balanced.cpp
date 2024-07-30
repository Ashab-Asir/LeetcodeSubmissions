class Solution {
public:
	int minimumDeletions(string s) {
		vector<int> preSum(s.size(), 0);
		vector<int> sufSum(s.size(), 0);

		if (s[0] == 'a') preSum[0] = 1;
		if (s[s.size()-1] == 'b') sufSum[s.size()-1] = 1;

		for (int i=1; i<s.size(); i++){
			if (s[i] == 'a') preSum[i] += 1 + preSum[i-1];

			else{preSum[i] = preSum[i-1];}

			if (s[s.size()-i-1] == 'b') sufSum[s.size()-i-1] += 1 + sufSum[s.size()-i];

			else{sufSum[s.size()-i-1] += sufSum[s.size()-i];}
		}

		int maxStringLen = 0;

		for (int i=0; i<s.size(); i++){
			if (preSum[i] + sufSum[i] > maxStringLen) maxStringLen = preSum[i] + sufSum[i];
		}

		return s.size() - maxStringLen;
	}
};