#include <cstdio>
#include <iostream>
#include <vector>

std::vector<char> finalNumber;

int main(int argc, const char** argv)
{
	int N = 0, D = 0, i = 0;

	while(1)
	{
		/* Data input */
		scanf(" %d %d", &N, &D);
		if(D == 0){ break; }
		char number[N];
		scanf(" %s", number);
		//printf("%s\n", number);

		/* Processing */
		for(i = 0; i < N; i++)
		{
			if (finalNumber.empty()){
				finalNumber.push_back(number[i]);
			}else{
				while(D > 0 && !finalNumber.empty() && finalNumber.back() < number[i])
				{
					finalNumber.pop_back();
					--D;
				}
				finalNumber.push_back(number[i]);
			}
		}

		while(D > 0){
			finalNumber.pop_back();
			--D;
		}

		/* Data output */
		for (i = 0; i < finalNumber.size(); i++)
		{
			std::cout << finalNumber.at(i);
		}
		std::cout << std::endl;
		finalNumber.clear();
	}

	return 0;
}
