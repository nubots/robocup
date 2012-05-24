#ifndef VISIONCONSTANTS_H
#define VISIONCONSTANTS_H

#include <string>

class VisionConstants
{
public:
    //! For the Goals
    static unsigned int GOAL_WIDTH;
    static unsigned int DISTANCE_BETWEEN_POSTS;

    static int BALL_EDGE_THRESHOLD;
    static int BALL_ORANGE_TOLERANCE;
    
    static void loadFromFile(std::string filename);
    
private:
    VisionConstants();  //so noone can make an object of this type
};

#endif // VISIONCONSTANTS_H
