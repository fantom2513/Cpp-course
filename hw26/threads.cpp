#include <iostream>
#include <thread>
#include <vector>
#include <ctime>
#include <algorithm>

static int massiveSize = 150000, piecesCount = 4;
static std::vector<int> resultT;

void sum(std::vector<int>& numbers, int startIndex, int finishIndex, int& result) {
    for (int i = startIndex; i <= finishIndex; i++) {
        result += numbers.at(i);
    }
}

void sumForThreads(std::vector<int>& numbers, int startIndex, int finishIndex) {
    int res = 0;
    for (int i = startIndex; i <= finishIndex; i++) {
        res += numbers.at(i);
    }
    resultT.push_back(res);
}

void withoutThreads(std::vector<int>& numbers) {
    unsigned int start_time = clock();
    std::vector<int> results;
    int miniSize = massiveSize % piecesCount > 0 ? massiveSize / piecesCount + 1 : massiveSize / piecesCount;
    int startIndex = 0, finishIndex = miniSize - 1;
    while (startIndex < numbers.size()) {
        int result = 0;
        sum(numbers, startIndex, finishIndex, result);
        startIndex = finishIndex + 1;
        finishIndex += miniSize;
        if (finishIndex > numbers.size() - 1)
            finishIndex = numbers.size() - 1;
        results.push_back(result);
    }
    int summa = 0;
    for (int i = 0; i < results.size(); i++) {
        summa += results.at(i);
    }
    std::cout << "result = " << summa << std::endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    std::cout << "Time without threads = " << search_time << std::endl;
}

void withThreads(std::vector<int>& numbers) {
    unsigned int start_time = clock();
    int miniSize = massiveSize % piecesCount > 0 ? massiveSize / piecesCount + 1 : massiveSize / piecesCount;
    int startIndex = 0, finishIndex = miniSize - 1;
    std::vector<std::thread> threads;
    while (startIndex < numbers.size()) {
        std::thread t(sumForThreads, std::ref(numbers), startIndex, finishIndex);
        threads.push_back(std::move(t));
        startIndex = finishIndex + 1;
        finishIndex += piecesCount;
        if (finishIndex > numbers.size() - 1)
            finishIndex = numbers.size() - 1;
    }
    std::for_each(threads.begin(), threads.end(), [](std::thread& t)
        { t.join(); });
   
    int finsum = 0;
    for (int i = 0; i < resultT.size(); i++) {
        finsum += resultT.at(i);
    }
    std::cout << "thr result = " << finsum << std::endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    std::cout << "Time with threads = " << search_time << std::endl;
}

int main()
{
    std::vector<int> numbers;
    for (int i = 0; i < massiveSize; i++) {
        numbers.push_back(std::rand() % (10 + 1));
    }

    withoutThreads(numbers);
    withThreads(numbers);   

    return 0;
}