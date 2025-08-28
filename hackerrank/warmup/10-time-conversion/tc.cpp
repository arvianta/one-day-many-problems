#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string hour = s.substr(0, 2);
    string min = s.substr(3, 2);
    string sec = s.substr(6, 2);
    string ampm = s.substr(8, 2);
    
    if (ampm == "AM") {
        if (hour == "12") {
            hour = "00";
        }
    } else {
        if (hour != "12") {
            int h = stoi(hour);
            h += 12;
            hour = to_string(h);
        }
    }
    
    return hour + ":" + min + ":" + sec;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
