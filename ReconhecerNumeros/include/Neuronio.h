#ifndef NEURONIO_H
#define NEURONIO_H

#define INPUTS 26 // colunas da matriz verdade
#define TARGETS 10 // linhas da matriz verdade


class Neuronio
{
    public:
        Neuronio();
        virtual ~Neuronio();


        //peso dos axonios e bias
        float W[TARGETS][INPUTS] = {{0}},
              b = 1;

        //matriz verdade
        float matriz[TARGETS][INPUTS] = {   { b, 0,1,1,1,0, 0,1,0,1,0, 0,1,0,1,0, 0,1,0,1,0, 0,1,1,1,0 },
                                            { b, 0,0,1,0,0, 0,1,1,0,0, 0,0,1,0,0, 0,0,1,0,0, 0,0,1,0,0 },
                                            { b, 0,1,1,1,0, 0,0,0,1,0, 0,1,1,1,0, 0,1,0,0,0, 0,1,1,1,0 },
                                            { b, 0,1,1,1,0, 0,0,0,1,0, 0,1,1,1,0, 0,0,0,1,0, 0,1,1,1,0 },
                                            { b, 0,1,0,1,0, 0,1,0,1,0, 0,1,1,1,0, 0,0,0,1,0, 0,0,0,1,0 },
                                            { b, 0,1,1,1,0, 0,1,0,0,0, 0,1,1,1,0, 0,0,0,1,0, 0,1,1,1,0 },
                                            { b, 0,1,1,1,0, 0,1,0,0,0, 0,1,1,1,0, 0,1,0,1,0, 0,1,1,1,0 },
                                            { b, 0,1,1,1,0, 0,0,0,1,0, 0,0,1,0,0, 0,1,0,0,0, 0,1,0,0,0 },
                                            { b, 0,1,1,1,0, 0,1,0,1,0, 0,1,1,1,0, 0,1,0,1,0, 0,1,1,1,0 },
                                            { b, 0,1,1,1,0, 0,1,0,1,0, 0,1,1,1,0, 0,0,0,1,0, 0,0,0,1,0 } };
        //vetor target
        float target[TARGETS][TARGETS] = {  { 1,0,0,0,0,0,0,0,0,0 },
                                            { 0,1,0,0,0,0,0,0,0,0 },
                                            { 0,0,1,0,0,0,0,0,0,0 },
                                            { 0,0,0,1,0,0,0,0,0,0 },
                                            { 0,0,0,0,1,0,0,0,0,0 },
                                            { 0,0,0,0,0,1,0,0,0,0 },
                                            { 0,0,0,0,0,0,1,0,0,0 },
                                            { 0,0,0,0,0,0,0,1,0,0 },
                                            { 0,0,0,0,0,0,0,0,1,0 },
                                            { 0,0,0,0,0,0,0,0,0,1 } };

        void Treinar(float LRate);

    private:

        float x = 0;
        float y;

        float f(float x);
        void CalibrarPesos(float y, int i, float LRate);

};

#endif // NEURONIO_H
