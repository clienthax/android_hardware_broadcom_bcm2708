/*
 * Copyright (C) 2013 Andreas Harter - RazDroid project
 *
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _GRALLOC_BRCM_H
#define _GRALLOC_BRCM_H

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>
#include <vc_dispmanx_types.h>
static const int GRALLOC_PRIV_TYPE_MM_RESOURCE = 0;
static const int GRALLOC_PRIV_TYPE_GL_RESOURCE = 1;

static const int GRALLOC_MAGICS_HAL_PIXEL_FORMAT_OPAQUE = 0;

typedef struct gralloc_private_handle_t {

    EGLImageKHR egl_image;
    DISPMANX_DISPLAY_HANDLE_T dispman_display;
    DISPMANX_RESOURCE_HANDLE_T dispman_resource;
    EGL_DISPMANX_WINDOW_T window;
    //GRALLOC_PRIV_TYPE_GL_RESOURCE or GRALLOC_PRIV_TYPE_MM_RESOURCE
    int res_type;
    int gl_format;
    int stride;
    int pixelformat;

} gralloc_private_handle_t;



#ifdef __cplusplus
extern "C" {
#endif

EGL_DISPMANX_WINDOW_T* gralloc_private_handle_from_native_window(EGLNativeWindowType window);

gralloc_private_handle_t* gralloc_private_handle_from_client_buffer(EGLClientBuffer buffer);

uint32_t gralloc_private_handle_get_res_type(gralloc_private_handle_t* private_handle);

uint32_t gralloc_private_handle_get_vc_handle(gralloc_private_handle_t *private_handle);

uint32_t gralloc_private_handle_get_egl_image(gralloc_private_handle_t *private_handle);

void gralloc_set_egl_image(gralloc_private_handle_t *private_handle, EGLImageKHR image);

#ifdef __cplusplus
};
#endif

#endif //_GRALLOC_BRCM_H
