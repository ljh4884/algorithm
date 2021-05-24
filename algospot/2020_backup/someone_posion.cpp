#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

 

//마법의 약 레시피와 이미 넣은 재료의 양이 주어질 때, 더 넣을 재료의 양을 구한다

//직관적인 방법

/*

vector<int> solveSimulation(const vector<int> &recipe, vector<int> put)

{

        int n = recipe.size();

        vector<int> result(n);

        //각 재료를 최소한 recipe에 적힌만큼을 넣어야한다

        for (int i = 0; i < n; i++)

        {

               result[i] = max(recipe[i] - put[i], 0);

               put[i] += result[i];

        }

        while (1)

        {

               //냄비에 재료를 더 넣지 않아도 될 때까지 반복

               bool ok = true;

               for(int i=0; i<n; i++)

                       for (int j = 0; j < n; j++)

                       {

                              //i번째 재료에 의하면 모든 재료는 (put[i]/recipe[i])배 이상은 넣어야 한다

                              //따라서 put[j]는 recipe[j]*(put[i]/recipe[i]) 이상의 정수가 되어야 한다

                              //(recipe[i]-1)을 더해주는 이유는 올림을 위해

                              int required = (put[i] * recipe[j] + (recipe[i] - 1)) / recipe[i];

                              //더 넣어야하는가?

                              if (required > put[j])

                              {

                                      result[j] += required - put[j];

                                      put[j] = required;

                                      ok = false;

                              }

                       }

               if (ok)

                       break;

        }

        return result;

}

*/

 

int gcd(int a, int b) //최대공약수

{

        if (b == 0)

               return a;

        return gcd(b, a%b);

}

 

//분수 (a/b)보다 큰 최소의 자연수 반환

int ceil(int a, int b)

{

        return (a + b - 1) / b;

}

 

vector<int> solve(const vector<int> &recipe, const vector<int> &put)

{

        int n = recipe.size();

        //모든 recipe[]의 최대공약수를 구한다

        int b = recipe[0];

        for (int i = 1; i < n; i++)

               b = gcd(b, recipe[i]);

        //최소한 (b/b=1)배는 만들어야 하므로, a의 초기 값을 b로 둔다

        int a = b;

        //put[i]/recipe[i]를 직접 구하는 대신 ceil(put[i]*b, recipe[i])의 최대값을 구한다

        for (int i = 0; i < n; i++)

               a = max(a, ceil(put[i] * b, recipe[i]));

        //(a/b)배 분량을 만들면 된다

        vector<int> result(n);

        for (int i = 0; i < n; i++)

               result[i] = (recipe[i] * a / b) - put[i];

        return result;

}

 

int main(void)

{

        int test_case;

        cin >> test_case;

        if (test_case < 1 || test_case>50)

               exit(-1);

 

        for (int i = 0; i < test_case; i++)

        {

               int ingredientNum;

               vector<int> recipe, put;

               cin >> ingredientNum;

               if (ingredientNum < 1 || ingredientNum>200)

                       exit(-1);

 

               for (int j = 0; j < ingredientNum; j++)

               {

                       int temp;

                       cin >> temp;

                       recipe.push_back(temp);

               }

               for (int j = 0; j < ingredientNum; j++)

               {

                       int temp;

                       cin >> temp;

                       put.push_back(temp);

               }

               //vector<int> result = solveSimulation(recipe, put);

               vector<int> result = solve(recipe, put);

               for (int j = 0; j < result.size(); j++)

                       cout << result[j] << " ";

               cout << endl;

        }

        return 0;

}