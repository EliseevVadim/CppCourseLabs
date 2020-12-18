#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
void print(std::pair<std::string, int> pair) {
    if(pair.first.length()>3&&pair.second>=7)
        std::cout << pair.first << " " << pair.second<<std::endl;
}
int main()
{
    std::map<std::string, int> map;
    std::ifstream fin;
    fin.open("Example.txt", std::ios::app);
    while (fin.peek()!= EOF)
    {
        const size_t MAXLEN = 1000;
        char text[MAXLEN];
        fin.getline(text, MAXLEN);
        char* substr = std::strtok(text, ".,:!;? ");
        while (substr != 0) {
            std::string word = substr;
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            auto founded = map.find(word);
            if (founded == map.cend()) {
                map.insert(std::make_pair(word, 1));
            }
            else
            {
                map[word]++;
            }
            substr = std::strtok(NULL, ".,:!;? ");
        }
    }
    std::for_each(map.begin(), map.end(), print);
}