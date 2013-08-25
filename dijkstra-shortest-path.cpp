#include <vector>
#include <unordered_map>

#include "helper.h"

using namespace std;

int main()
{

    vector< vector<int> > adjmat(5, vector<int>(5, 0));

    graphgen(adjmat);
    print(adjmat);

    return 0;
}
