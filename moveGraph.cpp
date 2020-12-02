#include <iostream>
using namespace std;
class Graph
{
    public:
    int size;
    int** adjMat;
    int** kadjMat;
    Graph(int size)
    {
        this->size=size;
    }
    int** multiply(int** a, int** b)
    {
        int sum=0;
        int** c = new int*[size];
        for (int i=0; i<size; i++)
            c[i] = new int[size];
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
            {
                for(int k=0; k<size; k++)
                    sum+=a[i][k]*b[k][j];
                c[i][j]=sum;
                sum=0;
            }
        return c;            
    }
    int** power(int** a, int k)
    {
        if(k==1)
            return a;
        return multiply(a, power(a, k-1));
    }
    int** inputAdjancy()
    {
        int** mat = new int*[size];
        for (int i=0; i<size; i++)
            mat[i] = new int [size];
        cout<<"Enter the elements of the adjancy matrix row-wise."<<endl;
        string row="";
        for(int i=0; i<size; i++)
        {
            cin>>row;
            for(int j=0; j<size;j++)
            {
                if(row.at(j)=='1')
                    mat[i][j]=1;
                else
                    mat[i][j]=0;
            }
        }
        return mat;
    }
    bool findPathHelper(int start, int finish, int avoid, int visited[])
    {
        visited[start]=1;
        if(start==finish)
            return true;
        else
        {
            for(int i=0; i<size; i++)
            {
                if(adjMat[start][i]==1 && kadjMat[avoid][i]==0 && visited[i]==0)
                    return findPathHelper(i, finish, avoid, visited);
            }
            return false;
        }
    }
    bool findPath(int start, int finish, int avoid)
    {
        int* visited=new int[size];
        return findPathHelper(start, finish, avoid, visited);
    }
    void DFSVISIT(int visitedDFS[], int s1, int t1, int s2, int t2)
    {
        visitedDFS[s1]=1;
        bool isPathPresent2=findPath(s2, t2, s1);
        if(isPathPresent2==false)
        {
            for(int i=0; i<size; i++)
            {
                if(adjMat[s1][i]==1 && visitedDFS[i]!=1 && kadjMat[s2][i]==0)
                    DFSVISIT(visitedDFS, i, t1, s2, t2);
            }
        }
        else
        {
            bool isPathPresent1=findPath(s1, t1, t2);
            if(isPathPresent1==true)
                cout<<"Present"<<endl;
            else
                cout<<"Not Present"<<endl;
        }
    }
    void DFS(int s1, int t1, int s2, int t2)
    {
        int* visitedDFS=new int[size];
        DFSVISIT(visitedDFS, s1, t1, s2, t2);
    }
};
int main()
{
    int size=0;
    int k=0;
    cout<<"Enter the dimensions of the adjancy matrix."<<endl;
    cin>>size;
    Graph object(size);
    object.adjMat=object.inputAdjancy();
    cout<<"Adjancy matrix for the Graph"<<endl;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
            cout<<object.adjMat[i][j];
        cout<<endl;
    }
    cout<<"\nEnter the value of k."<<endl;
    cin>>k;
    object.kadjMat=object.power(object.adjMat, k);
    int s1, s2, t1, t2;
    cout<<"Enter the start point of car1 - ";
    cin>>s1;
    cout<<"Enter the end point of car1 - ";
    cin>>t1;
    cout<<"Enter the start point of car2 - ";
    cin>>s2;
    cout<<"Enter the end point of car2 - ";
    cin>>t2;    
    object.DFS(s1, t1, s2, t2);    
}
