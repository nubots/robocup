#ifndef CENTRECIRCLE_H
#define CENTRECIRCLE_H

#include "visionfieldobject.h"
#include "Tools/Math/Circle.h"

class CentreCircle  : public VisionFieldObject
{
public:
    CentreCircle();
    CentreCircle(GroundPoint centre, double ground_radius, Vector2<double> screen_size);
    ~CentreCircle();

    virtual bool addToExternalFieldObjects(FieldObjects* fieldobjects, float timestamp) const;

    //! @brief Stream output for labelling purposes
    virtual void printLabel(ostream& out) const;

    //! @brief Calculation of error for optimisation
    virtual double findScreenError(VisionFieldObject* other) const;
    virtual double findGroundError(VisionFieldObject* other) const;

    double getGroundRadius() const {return m_ground_radius;}

    //! @brief output stream operator.
    friend ostream& operator<< (ostream& output, const CentreCircle& c);
    //! @brief output stream operator for a vector of CentreCircles.
    friend ostream& operator<< (ostream& output, const vector<CentreCircle>& c);

private:
    double m_ground_radius;
};

#endif // CENTRECIRCLE_H
