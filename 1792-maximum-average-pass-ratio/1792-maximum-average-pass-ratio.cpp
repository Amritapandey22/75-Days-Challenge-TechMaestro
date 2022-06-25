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

/*
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
     
        //among all classes i choose the one which will have a larger growth in the pass ratio if i add one student to the class
        
        //add one student to the each class and store the growth (difference) in the pass ratio to a max heap
        using pi=pair<double,pair<int,int>>;
        priority_queue<pair<double,pair<int,int>>> pq;
        //double is used to store the difference
        //pair.first stores the pass students in the class
        //pair.second stores the total students in the class
        for(int i=0;i<classes.size();i++)
        {
            int pass=classes[i][0];
            int total=classes[i][1];
            
            //calculate the growth
           long  double growth=(double)(pass+1)/(total+1) - (double)(pass)/(total);
            pq.push({growth,{pass,total}});
        }
        
        //now i have not added any students to any class and the number of students still remains the same
        //i have just want to know which class would have more growth if i add one 
        //so i pushed all the classes growth to max heap
        
        while(extraStudents)
        {
            pi top= pq.top();
            pq.pop();
            extraStudents--;
            //calculate the growth again if i add one student to the class at the top
            int pass=top.second.first;
            int total=top.second.second;
            pass++;
            total++;
            long double growth=(double)(pass+1)/(total+1) - (double)(pass)/(total);
            pq.push({growth,{pass,total}});
        }
        
        //now pop out the elements from pq and calculate the pass ratio
        double res=0;
        while(!pq.empty())
        {
            //calculate the pass/total;
            res+=(double)(pq.top().second.first)/(pq.top().second.second);
            pq.pop();
        }
        return (double)res/(classes.size());
        
    }
};*/