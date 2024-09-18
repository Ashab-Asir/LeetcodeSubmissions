class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>str1,str2;
        for(int i=0;i<nums.size();i++){
            string num=to_string(nums[i]);
                str1.push_back(to_string(nums[i]));
        }
        sort(str1.begin(),str1.end(),[](string s1,string s2){
            return s1+s2>s2+s1?true:false;
        });
        string ans="";
        for(int i=0;i<str1.size();i++){
            ans+=str1[i];
        }
        if(str1[0]=="0"){
            return "0";
        }
        return ans;
    }
};