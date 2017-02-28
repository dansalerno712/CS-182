#include "sorting.hh"
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
    int i = 0;
    int* t1 = NULL;
    char** t2 = NULL;
    if (argc > 3)
    {
	switch (argv[1][0])
	{
	case 'i':
	    //int *a = 0;
	    int iarr[argc - 2];
	    for (i = 2; i < argc; i++)
		iarr[i - 2] = atoi(argv[i]);
	    //partial sorting test first 2 should be sorted
	    Sortings<int, intintCompare>::merge(iarr, 2); // replace with sorting you want to test
	    for (i = 0; i < argc - 2; i++)
	    {
		cout << iarr[i] << " ";
	    }
	    cout << endl;
	    //full sorting test
	    Sortings<int, intintCompare>::merge(iarr, argc - 2); // replace with sorting you want to test
	    for (i = 0; i < argc - 2; i++)
	    {
		cout << iarr[i] << " ";
	    }
	    cout << endl;
	    //null array test
	    Sortings<int, intintCompare>::merge(t1, argc - 2);
	    cout << endl;
	    //n < 2 test
	    Sortings<int, intintCompare>::merge(iarr, 1);
	    break;
	case 's':
	    char *sarr[argc - 2];
	    for (i = 2; i < argc; i++)
		sarr[i - 2] = argv[i];
	     //partial sorting test first 2 should be sorted
	    Sortings<char*, strstrCompare>::merge(sarr, 2); // replace with sorting you want to test
	    for (i = 0; i < argc - 2; i++)
	    {
		cout << sarr[i] << " ";
	    }
	    cout << endl;
	    //sorting test
	    Sortings<char*, strstrCompare>::merge(sarr, argc - 2); // replace with sorting you want to test
	    for (i = 0; i < argc - 2; i++)
	    {
		cout << sarr[i] << " ";
	    }
	    cout << endl;
	    //null array test
	    Sortings<char*, strstrCompare>::merge(t2, argc - 2);
	    cout << endl;
	    //n < 2 test
	    Sortings<char*, strstrCompare>::merge(sarr, 1);
	    break;
	default:
	    i = -1;
	    cout << "Cannot sort that" << endl;
	}
    }
    else
    {
	cout << "Use: ./mysorts {i | s} item1 [item2] [item3] ..." << endl;
    }
    return 0;
}
