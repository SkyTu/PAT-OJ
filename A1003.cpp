# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
struct Node{
    int des,spend;
	Node(int _des, int _spend):des(_des),spend(_spend){}
};

int main()
{
    int c_num,r_num,current,save,t_num;
    vector<int> team_num;
    scanf("%d %d %d %d",&c_num,&r_num,&current,&save);
    for(int i=0;i<c_num;i++){
        scanf("%d",&t_num);
        team_num.push_back(t_num);
    }
    vector<Node> adj_list[500];
    int begin, end, spend;
    for(int i=0;i<r_num;i++){
        scanf("%d %d %d",&begin,&end,&spend);
        Node temp_node(end,spend);
        adj_list[begin].push_back(temp_node);
    }
}