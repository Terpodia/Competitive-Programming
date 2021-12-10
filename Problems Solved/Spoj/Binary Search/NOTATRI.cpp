#include <stdio.h>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int binarySearch(vector <int> &numbers, int search_number)
{
    int menor = 0;
    int mayor = numbers.size() - 1;
    int medio;
 
    while (mayor >= menor)
    {
        medio = (mayor + menor)/2;
        
        if(numbers[medio] > search_number && numbers[medio - 1] <= search_number)
        {
            return medio;
        }
        else if(numbers[medio] > search_number)
        {
            mayor = medio - 1;
        }
 
        else
        {
            menor = medio + 1;
        }
    }
    
    return -1;
}
 
int main()
{
 
    int N, suma, itr, answer = 0;
 
    do
    {
        scanf("%i", &N);
        if(N == 0) break;
 
        vector <int> numbers(N);
 
        for(int i = 0; i < N; i++) scanf("%i", &numbers[i]);
        sort(numbers.begin(), numbers.end());
 
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                suma = numbers[i] + numbers[j];
                itr = binarySearch(numbers, suma);
                
                if(itr == -1)
                {
                    break;
                }
                else
                {
                    answer++;
                    if(itr != N - 1)
                    {
                        itr = (N - 1) - itr;
                        answer += itr;
                    }   
                }
            }
        }
 
        printf("%i\n", answer);
 
        answer = 0;
    }
    while(N != 0);
 
    return 0;
} 

