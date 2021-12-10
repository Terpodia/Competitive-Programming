#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
 
using namespace std;
 
long long binarySearch(vector <long long> &vec1, vector <long long> &vec2, long long &ans)
{
    long long greater = vec1.size() - 1, less = 0, medium, aux;
    pair <long long, long long> bestValue;
    bestValue.first = 0; bestValue.second = 0;
 
    while(greater >= less)
    {
        aux = 0;
        medium = (greater + less)/2;
        for(int i = 0; i < (int)vec2.size(); i++)
        {
            if(vec1[medium] >= vec2[i]) continue;
            else aux += vec2[i] - vec1[medium];
 
            //if(aux > ans) break;
        }
 
        if(aux == ans)
        {
            if(abs(ans - aux)  < abs(ans - bestValue.first))
            {
                bestValue.first = aux;
                bestValue.second = vec1[medium];
            }
            
            return bestValue.second;
        }
        else if(aux > ans)
        {
            less = medium + 1;
            if(abs(ans - aux)  < abs(ans - bestValue.first))
            {
                bestValue.first = aux;
                bestValue.second = vec1[medium];
            }
        }
        else
        {
            greater = medium - 1;
        }
    }
 
    return bestValue.second;
}
 
int main()
{
 
    long long N, M, answer;
 
    scanf("%lli %lli", &N, &M);
    vector <long long> trees(N);
 
    for(int i = 0; i < N; i++) scanf("%lli", &trees[i]);
 
    sort(trees.begin(), trees.end());
    
    if(M == 0) printf("%lli", trees[N - 1]);
    
    else
    {
        vector <long long> search(trees[N - 1]);
        iota(search.begin(), search.end(), 1);
 
        answer = binarySearch(search, trees, M);
 
        printf("%lli", answer);   
    }
 
    return 0;
} 

