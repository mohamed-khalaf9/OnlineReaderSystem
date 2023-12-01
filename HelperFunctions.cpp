#include "HelperFunctions.h"
#include <iostream>
#include <vector>


int HelperFunctions::ReadInt(int low,int high){
    std::cout << "\nEnter number in range " << low << " - " << high << ": ";
    int value;

    std::cin >> value;

    if (low <= value && value <= high)
	   return value;

    std::cout << "ERROR: invalid number...Try again\n";
    return ReadInt(low, high);
}
int HelperFunctions::ShowReadMenu(std::vector<std::string>choices){
    std::cout << "\nMenu:\n";
    for (int ch = 0; ch < (int) choices.size(); ++ch) {
	std::cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
    }
    return ReadInt(1,choices.size());
}
std::string HelperFunctions::GetCurrentTimeDate(){
   // Get the current time in seconds since epoch
auto now = std::chrono::system_clock::now();
auto in_time_t = std::chrono::system_clock::to_time_t(now);

// Initialize a struct tm object to store the local time
std::tm timeInfo;

// Use localtime_s for a safer version of localtime
if (localtime_s(&timeInfo, &in_time_t) != 0) {
	// Handle error, e.g., throw an exception or return an error string
	return "Error getting local time";
}

// Format the time using strftime
const int bufferSize = 20;  // Size for "%Y-%m-%d %X" format
char buffer[bufferSize];
if (strftime(buffer, bufferSize, "%Y-%m-%d %X", &timeInfo) == 0) {
	// Handle error, e.g., throw an exception or return an error string
	return "Error formatting time";
}

return buffer;  // Convert C-style string to std::string
}
