class Solution {
public:
    struct worker_s {
        int quality;
        int wage;
        worker_s(int q, int w): quality(q), wage(w){}
        double getRate() {
            return (1.0 * wage)/ quality;
        }
    };
    using worker = struct worker_s;
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<worker> workerList;
        for(int i = 0; i< quality.size(); i++) {
            workerList.push_back(worker(quality[i], wage[i]));
        }
        sort(workerList.begin(), workerList.end(), [](auto e1, auto e2){
            return e1.getRate() < e2.getRate();
        });
        
        double currentRate = workerList[k-1].getRate();
        long long currentQuality = 0;
        priority_queue<int> maxHeap;
        
        for(int i = 0 ; i< k; i++) {
            currentQuality += workerList[i].quality;
            maxHeap.push(workerList[i].quality);
        }
        
        double ans = currentQuality * currentRate;
        
        for(int i = k; i<workerList.size(); i++) {
            currentRate = workerList[i].getRate();
            if(maxHeap.top() > workerList[i].quality) {
                currentQuality += workerList[i].quality - maxHeap.top();
                maxHeap.pop();
                maxHeap.push(workerList[i].quality);
            }
            ans = min(ans, currentRate * currentQuality);
        }
        return ans;
    }
};