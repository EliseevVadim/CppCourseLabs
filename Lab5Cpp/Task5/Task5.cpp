#include <iostream>
#include "Cache.h"
int main()
{
    Cache<int> cache;
    cache.put(1);
    cache.put(2);
    cache.put(3);
    cache += 5;
    Cache<std::string> voc;
    voc.put("OK");
    std::cout << voc.contains("Only") << std::endl;
    std::cout << cache.contains(5) << std::endl;
}

