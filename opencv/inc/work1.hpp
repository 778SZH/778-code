#pragma once
#include "common.hpp"

namespace work1 {
    int  PictureViewer(const std::string& imgPath);
    void FlagGenerator(const std::string& saveFileName);
    int  Cutting(const std::string& imgPath);
    int  CoveredWithBlackAndWhite(const std::string& imgPath);
    int  Progression(const std::string& imgPath);
    int  RealtimeCamera(int cameraID);
}
