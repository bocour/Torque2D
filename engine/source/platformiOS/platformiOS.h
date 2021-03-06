//-----------------------------------------------------------------------------
// Copyright (c) 2013 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#ifndef _PLATFORMIOS_H_
#define _PLATFORMIOS_H_

#import "UIKit/UIKit.h"


#include "platform/platform.h"
#include "math/mMath.h"
#include "platformiOS/iOSEvents.h"

#include "platformiOS/iOSOGLVideo.h"

#include "platformiOS/T2DView.h"
#include "platformiOS/T2DViewController.h"

class iOSPlatState
{
public:
    bool              captureDisplay;
    bool              fadeWindows;

    id				 appID;
    UIView			 *Window;
    char              appWindowTitle[256];
    bool              quit;
    T2DView           *ctx;
    T2DViewController *viewController;
    bool              ctxNeedsUpdate;

    bool			portrait;

    S32               desktopBitsPixel;
    S32               desktopWidth;
    S32               desktopHeight;
    U32               currentTime;
    bool				 fullscreen;

    U32               osVersion;

    bool              tsmActive;

    U32               firstThreadId;
    U32               torqueThreadId;

    void*             alertSemaphore;
    S32               alertHit;
    //   DialogRef         alertDlg;
    //   EventQueueRef     mainEventQueue;

    RandomLCG        platRandom;

    bool              mouseLocked;
    bool              backgrounded;
    bool              minimized;

    S32               sleepTicks;
    S32               lastTimeTick;

    Point2I           windowSize;

    U32               appReturn;

    U32               argc;
    const char**      argv;


    StringTableEntry  mainDotCsDir;

    NSTimer			 *mainLoopTimer;
    NSTimeInterval	 timerInterval;
    UIApplication	*application;
    //-Mat
    bool		multipleTouchesEnabled;

    iOSPlatState();
};

/// Global singleton that encapsulates a lot of mac platform state & globals.
extern iOSPlatState platState;

/// @name Misc Mac Plat Functions
/// Functions that are used by multiple files in the mac plat, but too trivial
/// to require their own header file.
/// @{
/// Fills gGLState with info about this gl renderer's capabilities.
void getGLCapabilities(void);


/// Display a file dialog.
/// calls FileDialog::Execute() on \p dialog
/// @param dialog The FileDialog object to Execute. A void* is used to cut down on header dependencies.
/// @see platform/nativeDialogs/fileDialog.h
void iOSShowDialog(void* dialog);

/// Translates a Mac keycode to a Torque keycode
U8 TranslateOSKeyCode(U8 vcode);
/// @}

/// @name Misc Mac Plat constants
/// @{

/// earlier versions of OSX don't have these convinience macros, so manually stick them here.
#ifndef IntToFixed
#define IntToFixed(a)    ((Fixed)(a) <<16)
#define FixedToInt(a)   ((short)(((Fixed)(a) + fixed1/2) >> 16))
#endif

/// mouse wheel sensitivity factor
const S32 kTMouseWheelMagnificationFactor = 25;

/// @}



#endif //_PLATFORMIOS_H_

