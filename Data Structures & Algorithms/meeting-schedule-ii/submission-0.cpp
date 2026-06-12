/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;

        vector<int> start(n), end(n);

        // Extract start and end times
        for(int i = 0; i < n; i++){
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0;
        int rooms = 0, maxRooms = 0;

        while(i < n){
            if(start[i] < end[j]){   // meeting starts before another ends
                rooms++;
                i++;
            } else {                 // meeting ended, free a room
                rooms--;
                j++;
            }
            maxRooms = max(maxRooms, rooms);
        }

        return maxRooms;
    }
};
