//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2014. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Jan 17. 2014
//   Author:        NewAuto video team
//================================================================================
#pragma once

#include "INvVideoFrame.h"


interface INvVideoFrameAllocator : public IUnknown
{
    virtual HRESULT __stdcall AllocateVideoFrame(
        ENvPixelFormat in_pixFmt,
        const SNvImagePosition &in_imgPos,
        const SNvRational &in_pixelAspectRatio,
        const SNvRational &in_proxyScale,
        ENvVideoRotation in_displayRotaion,
        INvVideoFrame **out_ppIVideoFrame) = 0;

    virtual HRESULT __stdcall Cleanup() = 0;

    virtual HRESULT __stdcall Shutdown() = 0;

    virtual void __stdcall PrintDebugInfo() = 0;
};

