#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Event {
    int time;
    int friendIndex;
    bool isArrival;

    bool operator<(const Event& other) const {
        if (time == other.time) {
            return isArrival < other.isArrival;
        }
        return time < other.time;
    }
};

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> times(n); // store pairs of arrival and departure times
    for (int i = 0; i < n; ++i) {
        cin >> times[i].first >> times[i].second;
    }
    int targetFriendIndex;
    cin >> targetFriendIndex;

    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        events.push_back({times[i].first, i, true});  
        events.push_back({times[i].second, i, false}); 
    }

    
    sort(events.begin(), events.end());

    set<int> freeChairs;
    vector<int> friendToChair(n, -1);
    int nextChair = 0;

    for (const auto& event : events) {
        if (event.isArrival) {
            int chair;
            if (!freeChairs.empty()) {
                chair = *freeChairs.begin();
                freeChairs.erase(freeChairs.begin());
            } else {
                chair = nextChair++;
            }
            friendToChair[event.friendIndex] = chair;

            if (event.friendIndex == targetFriendIndex) {
                cout << chair << endl;
                return 0;
            }
        } else {
            int chair = friendToChair[event.friendIndex];
            freeChairs.insert(chair);
        }
    }

    return 0;
}
