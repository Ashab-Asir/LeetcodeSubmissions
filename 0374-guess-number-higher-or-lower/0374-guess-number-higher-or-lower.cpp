/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=1,high=n;
        while(low<=high){
            int guess_number=high-(high-low)/2;
            int val=guess(guess_number);
            if(val==0){
                return guess_number;
            }
            else if(val==-1){
                high=guess_number-1;
            }
            else{
                low=guess_number+1;
            }
        }
        return 0;
    }
};