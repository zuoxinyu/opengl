/*

    WGL loader generated by glad 0.1.28 on Sun Oct 21 18:21:13 2018.

    Language/Generator: C/C++
    Specification: wgl
    APIs: wgl=1.0
    Profile: -
    Extensions:
        
    Loader: True
    Local files: True
    Omit khrplatform: False
    Reproducible: False

    Commandline:
        --api="wgl=1.0" --generator="c" --spec="wgl" --local-files --extensions=""
    Online:
        http://glad.dav1d.de/#language=c&specification=wgl&loader=on&api=wgl%3D1.0
*/


#ifndef WINAPI
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
#define NOMINMAX 1
#endif
#include <windows.h>
#endif

#include "glad.h"

#ifndef __glad_wglext_h_

#ifdef __wglext_h_
#error WGL header already included, remove this include, glad already provides it
#endif

#define __glad_wglext_h_
#define __wglext_h_

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void* (* GLADloadproc)(const char *name);

#ifndef GLAPI
# if defined(GLAD_GLAPI_EXPORT)
#  if defined(_WIN32) || defined(__CYGWIN__)
#   if defined(GLAD_GLAPI_EXPORT_BUILD)
#    if defined(__GNUC__)
#     define GLAPI __attribute__ ((dllexport)) extern
#    else
#     define GLAPI __declspec(dllexport) extern
#    endif
#   else
#    if defined(__GNUC__)
#     define GLAPI __attribute__ ((dllimport)) extern
#    else
#     define GLAPI __declspec(dllimport) extern
#    endif
#   endif
#  elif defined(__GNUC__) && defined(GLAD_GLAPI_EXPORT_BUILD)
#   define GLAPI __attribute__ ((visibility ("default"))) extern
#  else
#   define GLAPI extern
#  endif
# else
#  define GLAPI extern
# endif
#endif

GLAPI int gladLoadWGL(HDC hdc);

GLAPI int gladLoadWGLLoader(GLADloadproc, HDC hdc);

struct _GPU_DEVICE {
    DWORD  cb;
    CHAR   DeviceName[32];
    CHAR   DeviceString[128];
    DWORD  Flags;
    RECT   rcVirtualScreen;
};
DECLARE_HANDLE(HPBUFFERARB);
DECLARE_HANDLE(HPBUFFEREXT);
DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
DECLARE_HANDLE(HPVIDEODEV);
DECLARE_HANDLE(HPGPUNV);
DECLARE_HANDLE(HGPUNV);
DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
typedef struct _GPU_DEVICE GPU_DEVICE;
typedef struct _GPU_DEVICE *PGPU_DEVICE;

#ifdef __cplusplus
}
#endif

#endif
