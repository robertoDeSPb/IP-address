#include <iostream>

std::string partition (std::string address, int positionNumber) {
    int dotCount = 0;
    int lastCount = 0;
    std::string part1;
    std::string part2;
    std::string part3;
    std::string part4;
    for (int i = 0; i < address.length(); i++) {
        if (address[i] == '.') {
            dotCount++;
            if (dotCount == 1) {
                part1 = address.substr(0, i);
                lastCount = i;
            } else if (dotCount == 2) {
                part2 = address.substr(lastCount + 1, i - lastCount - 1);
                lastCount = i;
            } else if (dotCount == 3) {
                part3 = address.substr(lastCount + 1, i - lastCount -1);
                lastCount = i;
                part4 = address.substr(lastCount+1);
            }
        }
    }
    char dotCounter = 48 + dotCount;
    std::string newDotCounter;
    newDotCounter  += dotCounter;
    if (positionNumber == 0) return part1;
    if (positionNumber == 1) return part2;
    if (positionNumber == 2) return part3;
    if (positionNumber == 3) return part4;
    if (positionNumber == 4) return newDotCounter;
}

bool correctAddress(std::string address) {
    bool correct = true;
    std::string part;

    if (partition(address, 4)[0] != 51) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        part = partition(address, i);
        if (part.length() == 0) {;
            return false;
        }
        for (int j = 0; j < part.length(); j++) {
            if (part.length() == 1) {
                if (!(part[j] >= '0' && part[j] <= '9')) {
                    return false;
                }
            } else if (part.length() == 2) {
                if (j == 0 && !(part[j] > '0' && part[j] <= '9')) {
                    return false;
                } else if (j != 0 && !(part[j] >= '0' && part[j] <= '9')) {
                    return false;
                }
            } else if (part.length() == 3) {
                if (j == 0 && !(part[j] == '1' || part[j] == '2')) {
                    return false;
                } else if (j == 1) {
                    if (part[0] == '2' && !(part[j] >= '0' && part[j] <= '5')) {
                        return false;
                    } else if (part[0] == '1' && !(part[j] >= '0' && part[j] <= '9')) {
                        return false;
                    }
                } else if (j == 2) {
                    if (part[0] == '2' && part[1] == '5' && !(part[j] >= '0' && part[j] <= '5')) {
                        return false;
                    } else if (part[0] != '2' && !(part[j] >= '0' && part[j] <= '9')) {
                        return false;
                    }
                }
            }
        }
    }
    return correct;
}

int main() {
    std::string address;
    std::cout << "Input IP-address: \n";
    std::cin >> address;

    correctAddress(address)? std::cout << "Yes\n" : std::cout << "No\n";
}