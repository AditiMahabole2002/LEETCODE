// LINERA SEARCH WILL GIVE TLE
class Solution {
public:
    bool can_solve_in_given_time(vector<int>& bugs, int h,int i){
        
        long long time_taken = 0;
        for(int bug:bugs ){
            time_taken+=(long long)(bug-1)/i + 1; // ceil value
        }
        return time_taken<=h;
    }
    int minEatingSpeed(vector<int>& bugs, int h) {
        // minimum bug to be solved is atleast 1
        int mini_bugs = 1;

        // maximum bugs can be solved is max bugs present in bugs array
        int max_bugs = 0;
        for(auto bug:bugs) max_bugs = max(max_bugs,bug);


        int ans = 0;

        for(int i=mini_bugs;i<=max_bugs;i++){
            // i is bugs
            if(can_solve_in_given_time(bugs,h,i)){
                ans = i;
                break;
            }

        }
        return ans;
        
    }
};

// ----------------------------------------------------------------------------------

// NOW USING BINARY SEARCH 


class Solution {
public:
    bool can_solve_in_given_time(vector<int>& bugs, int h,int i){

        long long time_taken = 0;
        for(int bug:bugs ){
            time_taken+=(long long)(bug-1)/i + 1; // ceil value
        }
        return time_taken<=h;
    }
    int minEatingSpeed(vector<int>& bugs, int h) {
        // minimum bug to be solved is atleast 1
        int mini_bugs = 1;

        // maximum bugs can be solved is max bugs present in bugs array
        int max_bugs = 0;
        for(auto bug:bugs) max_bugs = max(max_bugs,bug);


        int ans = -1;

        // for(int i=mini_bugs;i<=max_bugs;i++){
        //     // i is bugs
        //     if(can_solve_in_given_time(bugs,h,i)){
        //         ans = i;
        //         break;
        //     }

        // }
        
        int low = mini_bugs; // mini bugs
        int high = max_bugs; // max bugs

        while(low<=high){
            int mid = low+(high-low)/2; // bugs taken to check

            if(can_solve_in_given_time(bugs,h,mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
            
        }
        return ans; 
    }
};
