#include <string>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int target, vector<int> numbers, int& answer, int sum = 0, int index = 0)
{
    if (index == (numbers).size())
    {
        if (sum == target) answer++;
        return;
    }
    dfs(target, numbers, answer, sum + (numbers)[index], index + 1);
    dfs(target, numbers, answer, sum - (numbers)[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(target, numbers, answer);

    return answer;
}

int main(void)
{
    vector<int> list;
    int target_number = 3;

    list.push_back(1);
    list.push_back(1);
    list.push_back(1);
    list.push_back(1);
    list.push_back(1);

    cout << solution(list, target_number) << endl;

    return 0;
}