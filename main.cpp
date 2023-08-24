#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <deque>
#include <list>

int main()
{
    ;
    std::list<std::string> file;
    bool isFileContents = true;
    std::string temp_line, buffer;
    auto iter = file.begin();
    while (std::getline(std::cin, temp_line))
    {
        if (isFileContents)
        {

            if (temp_line.empty())
            {
                isFileContents = false;
                iter = file.begin();
                continue;
            }
            file.push_back(temp_line);
        }
        else
        {
            if (temp_line == "Down")
            {
                if (iter != file.end())
                {
                    ++iter;
                }
                continue;
            }
            else if (temp_line == "Up")
            {
                if (iter == file.begin())
                {
                    continue;
                }
                --iter;
            }
            else if (temp_line == "Ctrl+X")
            {
                if (iter == file.end())
                    continue;
                buffer = *iter;
                iter = file.erase(iter);
            }
            else if (temp_line == "Ctrl+V")
            {
                if (buffer.empty())
                    continue;
                file.insert(iter, buffer);
            }
        }
    }
    for (std::string &s : file)
    {
        std::cout << s << '\n';
    }
    return 0;
}
