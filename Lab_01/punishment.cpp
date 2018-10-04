#include <iostream>
#include <string>

using namespace std;

main()
{
    int x;
    string phrase;
    
    while(x >= 0)
    {
    	cout << "Enter the phrase: ";
	cin.ignore();
    	getline(cin, phrase);
    	cout << "Enter the number of times to repeat the phrase: ";
    	cin >> x;
    	if(x < 0) {
            cout << "You entered an incorrect value for the number of repetitions";
	}  
   	else {
	    for(int y = x; y > 0; y--) {
                cout << phrase << endl;
    	    }
	}
	cout << endl;
    }
    return 0;
}
