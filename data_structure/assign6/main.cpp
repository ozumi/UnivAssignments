
#include "wordfrequency.h"

using namespace std;

int main()
{
	WordFrequency freqChecker;
	
	freqChecker.ReadText("cat_in_the_hat.txt");
	
	cout << "# of occurence of word 'you' : " << freqChecker.GetFrequency("you") << endl;
//     freqChecker.IncreaseFrequency("you");
	
	cout << "Print all result" << endl;
	freqChecker.PrintAllFrequency();
	
//	cout << "IncreseFrequency" <<endl;


	return 0;
}
