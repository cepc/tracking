#ifndef STRAIGHTLINE_H
#define STRAIGHTLINE_H

class StraightLine
{
    public :
        StraightLine();
        StraightLine(double d0, double phi,
                double omega, double z0, double tanLambda);
        ~StraightLine();

        void setParameters(double _d0, double _phi,
                double _omega, double _z0, double _tanLambda);
        static void setReferencePoint(double x_r, double y_r, double z_r);
        double* getPointAt(double s);

        double d0;
        double phi;
        double omega;
        double z0;
        double tanLambda;

    private:
        double R;
        static double x_r, y_r, z_r;
        double *p;
};

#endif
