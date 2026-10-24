class Solution {
public:
    int convert(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        int total = 0;

        // Add the days in all previous months
        for (int i = 0; i < month - 1; i++) {
            total += days[i];
        }

        // Add the current day
        total += day;

        return total;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int a1 = convert(arriveAlice);
        int a2 = convert(leaveAlice);
        int b1 = convert(arriveBob);
        int b2 = convert(leaveBob);

        // Find the overlapping interval
        int start = max(a1, b1);
        int end = min(a2, b2);

        // No overlap
        if (start > end) {
            return 0;
        }

        // Both arrival and leaving days are included
        return end - start + 1;
    }
};