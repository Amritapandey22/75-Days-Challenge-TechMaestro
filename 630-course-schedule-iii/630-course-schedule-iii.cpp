class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int time=0;
        priority_queue<int>pq;
         sort(courses.begin(), courses.end(), [](auto &a, auto &b) {return a[1] < b[1];});
        for(auto d:courses){
            int dur=d[0],endDate=d[1];
            if(dur<=endDate){
                if(dur+time<=endDate){
                    pq.push(dur);
                    time+=dur;
                }else{
                    if(pq.size() and pq.top()>dur){
                        time-=pq.top();
                        time+=dur;
                        pq.pop();
                        pq.push(dur);
                    }
                }
            }
        }
        
        return pq.size();
    }
};