#include "TLoan.h"
#include "TLibrary.h"
#include "TPerson.h"
using namespace std;
class TLibraryPool  {
public:
    typedef struct {
        int startpos;
        int endpos;
    } pos;
private:
    string Name;
    TPerson * Chairman;
    vector<TLibrary *> LibraryList;
    vector<TPerson *> Customers;
    vector<TLoan *> LoanList;
    string parseLine(string line, pos * position);
public:

    TLibraryPool(string Name, TPerson * Chairman);
    TLibraryPool(char * filename);
    ~TLibraryPool();
    void add(TPerson * Customer);
    void add(TLibrary * Library);
    TPerson * get_Chairman();
    void set_Chairman(TPerson Chairman);
    vector<TPerson*>  get_Customers();
    vector<TLibrary*>  get_LibraryList();
    void print();
    void load( ifstream& file);

};
