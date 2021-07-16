/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int Answer;
int A[200000];
int B[200000];
int n,k;

bool compare(int i, int j)
{
	return j < i;
}
int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		scanf("%d %d",&n,&k);
		
		for(int i=0;i<n;i++)
		    scanf("%d",&A[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&B[i]);
		    
		sort(A,A+n);
		sort(B,B+n);
		sort(B,B+k,compare);

		for(int i=0;i<k;i++)
		{
			Answer = max(Answer, A[i]+B[i]);
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
