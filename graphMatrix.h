#ifndef _GRAPHMATRIX_H_
#define _GRAPHMATRIX_H_
#include<vector.h>
#include"graph.h"

template<typename Tv> struct Vertex
{
    Tv data;
    int inDegree;
    int outDegree;

    VStatus status;
    int dTime,fTime;
    
    int parent;
    int priority;

    Vertex(Tv const & d):data(d),inDegree(0),outDegree(0),status(UNDISCOVERED),dTime(-1),fTime(-1),parent(-1),priority(INT_MAX){}
};


template<typename Te> struct Edge
{
    Te data;
    int weight;
    EType type;

    Edge(Te const & d,int w):data(d),weight(w),type(UNDETERMINED){}
};

template<typename Tv,typename Te> class GraphMatrix:public Graph<Tv,Te>
{
private:
    Vector<Vertex<Tv>> V;
    Vector<Vector<Edge<Te>*>> E;
public:
    GraphMatrix(){n=e=0;}
    ~GraphMatrix()
    {
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                delete E[j][k];
    }

//顶点的基本操作:查询第i个顶点(0<=i<n)

    virtual Tv & vertex(int i){return V[i].data;}    //数据
    virtual int inDeGree(int i){return V[i].inDegree;}    //入度
    virtual int outDegree(int i){return V[i].outDegree;}  //出度
    virtual int nextNbr(int i,int j) ;        //相对于顶点j的下一邻接顶点
    virtual int firstNbr(int i){return nextNbr(i,n)} //首个邻接顶点
    virtual Vstatus &status(int i){return V[i].status;}   //状态
    virtual int & dTime(int i){return V[i].dTime;}     //时间标签dTime
    virtual int & fTime(int i){return V[i].fTime;}     //时间标签fTime
    virtual int & parent(int i){return V[i].parent;}   //在遍历树中的父亲
    virtual int & priority(int i){return V[i].priority;}  //优先级数
//顶点的动态操作
    virtual int insert(Tv const & vertex);

//边的确认操作
    virtual bool exists(int i,int j)  //边(i,j)是否存在
    {return (0<=i)&&(i<n)&&(0<=j)&&(j<n)&&E[i][j]!=nullptr;}
    virtual EType & type(int i,int j){return E[i][j]->type;}
    virtual Te & edge(int i,int j){return E[i][j]->data;}
    virtual int & weight(int i,int j){return E[i][j]->weight;}
//边的动态操作
    
};
template<typename Tv,typename Te>
int GraphMatrix<Tv,Te>::nextNbr(int i,int j)
{
    while((-1<j)&&!exists(i,--j));
    return j;
}

template<typename Tv,typename Te>
int insert(Tv const & vertex)
{
    for(int j=0;j<n;j++)
        E[j].insert(nullptr);
    n++;
    E.insert(vector<Edge<Te>*>(n,n,nullptr));
    return V.insert(Vertex<Tv>(vertex));
}
#endif //_GRAPHMATRIX_H_
