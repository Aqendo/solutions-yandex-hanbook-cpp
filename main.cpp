#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
    std::list<std::string> file;
    bool isFileContents = true;
    std::string temp_line;
    std::list<std::string> buffer;
    auto iter = file.begin();
    bool isShiftPressed = false;
    int shiftOffset = 0;
    while (std::getline(std::cin, temp_line)) {
        if (isFileContents) {

            if (temp_line.empty()) {
                isFileContents = false;
                iter = file.begin();
                continue;
            }
            file.push_back(temp_line);
        } else {
            if (temp_line == "Up") {
                if (iter != file.begin()) {
                    if (isShiftPressed) {
                        shiftOffset++;
                    }
                    iter--;
                }
            } else if (temp_line == "Down") {
                if (iter != file.end()) {
                    if (isShiftPressed) {
                        shiftOffset--;
                    }
                    iter++;
                }
            } else if (temp_line == "Shift") {
                isShiftPressed = !isShiftPressed;
                shiftOffset = 0;
            } else if (temp_line == "Ctrl+X") {
                buffer.clear();
                if (file.empty()) continue;
                if (isShiftPressed) {
                    auto from = iter;
                    std::advance(from, shiftOffset);
                    if (shiftOffset >= 0) {
                        buffer.splice(buffer.begin(), file, iter, from);
                    } else {
                        buffer.splice(buffer.begin(), file, from, iter);
                    }
                } else {
                    if (iter == file.end()) continue;
                    buffer.push_back(*iter);
                    iter = file.erase(iter);
                }
                isShiftPressed = false;
                shiftOffset = 0;
            } else if (temp_line == "Ctrl+V") {
                if (isShiftPressed) {
                    auto from = iter;
                    std::advance(from, shiftOffset);
                    if (shiftOffset >= 0) {
                        iter = file.erase(iter, from);
                    } else {
                        iter = file.erase(from, iter);
                    }
                    isShiftPressed = false;
                    shiftOffset = 0;
                }

                file.insert(iter, buffer.begin(), buffer.end());
            }
        }
    }
    for (std::string &s: file) {
        std::cout << s << '\n';
    }
    return 0;
}
