#ifndef LISTCIRCULAR_H
#define LISTCIRCULAR_H
#include<nodelist.h>
#include<disparo.h>

class List
{
    private:
        NodeList*Head;
        NodeList*IT;
        int N;
    public:
        List();
        NodeList* getIT(){return IT;}
        NodeList** getITPtPt(){return &IT;}
        void itNext();
        void resetIT(){IT=Head;}
        bool pushCircular(Disparo *Dat);
        bool removeCircular(int k);
        bool searchCircular(int k);
        int size(){return N;}
        bool empty(){return !N;}
};

#endif // LISTCIRCULAR_H
