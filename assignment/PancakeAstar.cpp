#include<bits/stdc++.h>
using namespace std;



void flip(vector<int>& pancakes, int k) {
    reverse(pancakes.begin(), pancakes.begin() + k);
}

bool isSorted(const vector<int>& pancakes) {
    return is_sorted(pancakes.begin(), pancakes.end());
}

int heuristic(const vector<int>& pancakes) {
    int distance = 0;
    for (int i = pancakes.size()-1; i >=0 ; i--) {
       if((pancakes[i]-i)!=1)return -i-1;
    }
    return distance;
}

int main() {
    std::map<vector<int>, int> mp;
    vector<int> pancakes = {3, 2,1,5,4};



     vector<int> original =pancakes;

    priority_queue<pair<pair<int,int>, pair<vector<int>, vector<int>>>> pq;
    pq.push({{heuristic(pancakes)+0,0}, {pancakes, {}}});


    while (!pq.empty()) {
        auto currentState = pq.top();
        pq.pop();

        int cost = currentState.first.second;
        auto state = currentState.second;
        int costt=0;

        if (isSorted(state.first)) {
           

                cout << " Flips to Sort: " << state.second.size() << endl;

             cout << "Original    : ";
            for(j : original)cout << " " << j;
                cout << endl;


            for (int i : state.second) {
                cout<< "h(n)        : " << -heuristic(original) << endl;

                cout<< "Total cost  : " << -heuristic(original)+costt << endl;
                costt++;
                
                cout <<"flipped "<<  i << "   :  ";
                flip(original,i);
                for(j : original)cout << " " << j;
                cout << endl;
            }
            cout << endl;
            break;
        }

        int n = state.first.size();
        for (int i = 2; i <= n; ++i) {

            vector<int> flippedStack = state.first;


            flip(flippedStack, i);
            if(mp[flippedStack]) cout << "1 ";
            else cout << "0 " ;

           if(!mp[flippedStack]){

                vector<int> flips = state.second;
                flips.push_back(i);

                int newCost = cost-1;

                pq.push({{newCost+heuristic(flippedStack),newCost}, {flippedStack, flips}});
                mp[flippedStack]=1;
            }
            
        }
    }


    return 0;
}
