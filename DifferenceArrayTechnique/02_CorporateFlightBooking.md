# LeetCode 1109. Corporate Flight Bookings

Visualization with diff array technique
```
Index:    0    1    2    3    4
----------------------------------------
+5 (1→3)  +5         -5
+10(2→4)       +10        -10
+3 (3→5)            +3          -3

diff =   [5,  10,   3,  -10,  -3]
```

We just add the tickets and nullify their effect on end + 1
Iterate over the bookings and add the ticket on start index and nullify the effect on end + 1. 
```cpp
 vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        //diff array technique
        vector<int> temp(n,0);
        for(int i = 0 ; i < bookings.size();i++){
            int start = bookings[i][0] - 1; //for 0 based indexing
            int end = bookings[i][1] - 1; //for 0 based indexing
            temp[start] += bookings[i][2];
            if(end +1 < n) temp[end+1] -= bookings[i][2];
        }
        int sum = 0;
        for(int i = 0 ; i < temp.size();i++){
            sum += temp[i];
            temp[i] = sum;
        }
        return temp;
    }
```
