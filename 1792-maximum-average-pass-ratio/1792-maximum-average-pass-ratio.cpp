class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int es) {
       //first we will sort or basically store the classes which will show more growth when 1 is added to their ratio
        //2 ways for above method:1.custom comparartor2.pq<growtj,pair>so pq will automatically sort on the basis of growth
        
        priority_queue<pair<double,pair<int,int>>>pq;
        //loop to store them growth wise
        for(auto d:c){
            double pass=d[0];
            double tot=d[1];
            
            double growth=(pass+1)/(tot+1)-pass/tot;
            pq.push({growth,{d[0],d[1]}});
        }
        //now assigning extra students/
        //note:it is not necessary the one at the top will take all the students
        // maybe after showing +1 growth,it may not show that drastic growth after +2
        //some other class may show that,so we will pop again to see which class is leading in growth now and give the extra student to that class
        
        while(es--){
            auto cl=pq.top();
            pq.pop();
            int pass=cl.second.first;
            int tot=cl.second.second;
            //***********this part needs revision **********************
            pass++;
            tot++;
            double growth=(double)(pass+1)/(tot+1)-(double)pass/tot;
            pq.push({growth,{pass,tot}});
        }
        
        double ans=0;
        while(pq.size()){
            auto st=pq.top();
            pq.pop();
            ans+=(double)(st.second.first)/(st.second.second);
        }
        
        return (double)(ans)/(c.size());
    }
};

