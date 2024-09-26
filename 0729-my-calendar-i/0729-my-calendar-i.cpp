class MyCalendar {
    private:
    vector<pair<int,int>>booking;
public:
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        for(int i=0;i<booking.size();i++)
           if((booking[i].first<=start && booking[i].second>start)||
             (booking[i].first<end && booking[i].second>end)||(booking[i].first>=start && booking[i].second<=end))
              return false;
            else
              continue;
        
          booking.push_back({start,end});
        return true;
        
    }
};
