#include<bits/stdc++.h>
using namespace std;

void flip(vector<int>& pancakes, int k) {
    reverse(pancakes.begin(), pancakes.begin() + k);
}


bool isSorted(const vector<int>& pancakes) {
    for (int i = 1; i < pancakes.size(); ++i) {
        if (pancakes[i - 1] > pancakes[i]) {
            return false;
        }
    }
    return true;
}



int main() {

    std::map<vector<int>, int> visited;
    vector<int> pancakes = {3, 2,1,5,0};
    vector<int> original=pancakes;

    int flag=0;
    queue<pair<vector<int>, vector<int>>> q;
    q.push({pancakes, {}});

    while (!q.empty()) {
        auto currentState = q.front();
        q.pop();

        if (isSorted(currentState.first)) {
            
            cout << "Minimum Flips to Sort: " << currentState.second.size() << endl;

             cout << "Original    : ";
            for(j : original)cout << " " << j;
                cout << endl;

            for (int i : currentState.second) {
                cout <<"flipped "<<  i << "   :  ";
                flip(original,i);
                for(j : original)cout << " " << j;
                cout << endl;
            }
            cout << endl;
            break;
            
        }

        int n = currentState.first.size();
        for (int i = 2; i <= n; ++i) {
            vector<int> flippedStack = currentState.first;
            flip(flippedStack, i);
            vector<int> flips = currentState.second;

            if(!visited[flippedStack])
            {
            flips.push_back(i);

            q.push({flippedStack, flips});
            visited[flippedStack]=1;
            }


        }
    }


    return 0;
}
