/*
 * INCOMPLETE
 */

#include <vector>
#include <unordered_map>
#include <priority_queue>
#include <climits>

#include "helper.h"

using namespace std;

#define NUM_NODES 10

class compare
{
public:

    bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        return lhs.second < rhs.second;
    }
};

void initialize(priority_queue< pair<int,int> > &dist, int num_nodes)
{
    for (int i=0; i < num_nodes; i++)
        dist.push_back( pair<int, int>(i, INT_MAX);
}

void dijikstra(vector< vector<int> > &adjmat, 
               priority_queue< pair<int, int> > &dist,
               bool *visited,
               int src,
               int dst
              )
{

    while (dist.empty() == false)
    {
         

    }

}

int main()
{

    vector< vector<int> > adjmat(NUM_NODES, vector<int>(NUM_NODES, 0));
    bool visited[NUM_NODES] = {false};
    // first int is the node number. second int is the distance from src
    priority_queue<pair<int,int> > dist(compare());
    int src=0, dst = 6; 
    
    graphgen(adjmat);
    print(adjmat);

    initialize(dist, NUM_NODES);
    int shortest_dist = dijkstra(adjmat, dist, src, dst);
    
    cout << "shortest dist from src " << src << " to destination " << dst;
    cout << " is: " << shortest_dist << enld;

    return 0;
}
