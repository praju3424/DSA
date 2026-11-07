
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // {weight, index}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> available;

        // {finishTime, weight, index}
        priority_queue<tuple<long long,int,int>,
                       vector<tuple<long long,int,int>>,
                       greater<tuple<long long,int,int>>> busy;

        int n = servers.size();

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;
        long long curTime = 0;

        for(int i = 0; i < tasks.size(); i++) {

            // Maintain current time
            curTime = max(curTime, (long long)i);

            // Release completed servers
            while(!busy.empty() && get<0>(busy.top()) <= curTime) {

                auto [finish, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available, wait
            if(available.empty()) {

                curTime = get<0>(busy.top());

                while(!busy.empty() && get<0>(busy.top()) <= curTime) {

                    auto [finish, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select the best server
            auto [weight, index] = available.top();
            available.pop();

            ans.push_back(index);

            // Assign task
            busy.push({curTime + tasks[i], weight, index});
        }

        return ans;
    }
};
