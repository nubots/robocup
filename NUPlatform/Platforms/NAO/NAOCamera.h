/*! @file NAOCamera.h
    @brief Declaration of NAO camera class

    @author Jason Kulk
 
    @class NAOCamera
    @brief A NAO camera
 
    @author Jason Kulk
 
  Copyright (c) 2009 Jason Kulk
 
    This file is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with NUbot.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NAOCAMERA_H
#define NAOCAMERA_H

#include "NUPlatform/NUCamera.h"
#include "NUPlatform/NUCamera/CameraSettings.h"
#include "Tools/Image/NUimage.h"

class NAOCamera : public NUCamera
{
public:
    NAOCamera();
    ~NAOCamera();
    NUimage* grabNewImage();
    void setSettings(const CameraSettings& newset);

private:
  enum 
  {
    frameBufferCount = 3, //!< Number of available frame buffers.
    WIDTH = 640,
    HEIGHT = 480,
    SIZE = WIDTH * HEIGHT * 2
  };

    bool setControlSetting(unsigned int settingID, int value);
    int getControlSetting(unsigned int id);

    int fd; //!< The file descriptor for the video device.
    void* mem[frameBufferCount]; //!< Frame buffer addresses.
    int memLength[frameBufferCount]; //!< The length of each frame buffer.
    struct v4l2_buffer* buf; //!< Reusable parameter struct for some ioctl calls.
    struct v4l2_buffer* currentBuf; //!< The last dequeued frame buffer.
    double timeStamp, //!< Timestamp of the last captured image.
           storedTimeStamp; //!< Timestamp when the next image recording starts.
    bool capturedNew();
    const unsigned char* getImage() const;
    double getTimeStamp() const;
    NUimage currentBufferedImage;

};

#endif

