// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/cpptoc/frame_cpptoc.h"
#include "libcef_dll/ctocpp/client_ctocpp.h"
#include "libcef_dll/transfer_util.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT int cef_browser_create(cef_window_info_t* windowInfo,
    struct _cef_client_t* client, const cef_string_t* url,
    const struct _cef_browser_settings_t* settings)
{
  DCHECK(windowInfo);
  if (!windowInfo)
    return 0;

  CefRefPtr<CefClient> clientPtr;
  CefWindowInfo windowInfoObj;
  CefBrowserSettings browserSettingsObj;
  
  windowInfoObj.Set(*windowInfo, false);
  if(client)
    clientPtr = CefClientCToCpp::Wrap(client);
  if (settings)
    browserSettingsObj.Set(*settings, false);
 
  return CefBrowser::CreateBrowser(windowInfoObj, clientPtr, CefString(url),
      browserSettingsObj);
}

CEF_EXPORT cef_browser_t* cef_browser_create_sync(cef_window_info_t* windowInfo,
    struct _cef_client_t* client, const cef_string_t* url,
    const struct _cef_browser_settings_t* settings)
{
  DCHECK(windowInfo);
  if (!windowInfo)
    return NULL;

  CefRefPtr<CefClient> clientPtr;
  CefWindowInfo windowInfoObj;
  CefBrowserSettings browserSettingsObj;
  
  windowInfoObj.Set(*windowInfo, false);
  if(client)
    clientPtr = CefClientCToCpp::Wrap(client);
  if (settings)
    browserSettingsObj.Set(*settings, false);
  
  CefRefPtr<CefBrowser> browserPtr(
      CefBrowser::CreateBrowserSync(windowInfoObj, clientPtr, CefString(url),
                                    browserSettingsObj));
  if(browserPtr.get())
    return CefBrowserCppToC::Wrap(browserPtr);
  return NULL;
}


// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK browser_parent_window_will_close(struct _cef_browser_t* self)
{
  DCHECK(self);
  if (!self)
    return;

  CefBrowserCppToC::Get(self)->ParentWindowWillClose();
}

void CEF_CALLBACK browser_close_browser(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->CloseBrowser();
}

int CEF_CALLBACK browser_can_go_back(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefBrowserCppToC::Get(self)->CanGoBack();
}

void CEF_CALLBACK browser_go_back(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->GoBack();
}

int CEF_CALLBACK browser_can_go_forward(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefBrowserCppToC::Get(self)->CanGoForward();
}

void CEF_CALLBACK browser_go_forward(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->GoForward();
}

void CEF_CALLBACK browser_reload(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->Reload();
}

void CEF_CALLBACK browser_reload_ignore_cache(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->ReloadIgnoreCache();
}

void CEF_CALLBACK browser_stop_load(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->StopLoad();
}

void CEF_CALLBACK browser_set_focus(struct _cef_browser_t* self, int enable)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->SetFocus(enable ? true : false);
}

cef_window_handle_t CEF_CALLBACK browser_get_window_handle(
    struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return NULL;

  return CefBrowserCppToC::Get(self)->GetWindowHandle();
}

cef_window_handle_t CEF_CALLBACK browser_get_opener_window_handle(
    struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return NULL;

  return CefBrowserCppToC::Get(self)->GetOpenerWindowHandle();
}

int CEF_CALLBACK browser_is_popup(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefBrowserCppToC::Get(self)->IsPopup();
}

int CEF_CALLBACK browser_has_document(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefBrowserCppToC::Get(self)->HasDocument();
}

struct _cef_client_t* CEF_CALLBACK browser_get_client(
    struct _cef_browser_t* self)
{
  DCHECK(self);
  if (!self)
    return NULL;

  CefRefPtr<CefClient> clientPtr = CefBrowserCppToC::Get(self)->GetClient();
  if(clientPtr.get())
    return CefClientCToCpp::Unwrap(clientPtr);

  return NULL;
}

struct _cef_frame_t* CEF_CALLBACK browser_get_main_frame(
    struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return NULL;

  CefRefPtr<CefBrowser> browserPtr = CefBrowserCppToC::Get(self);
  CefRefPtr<CefFrame> framePtr = browserPtr->GetMainFrame();
  if(framePtr.get())
    return CefFrameCppToC::Wrap(framePtr);
  return NULL;    
}

struct _cef_frame_t* CEF_CALLBACK browser_get_focused_frame(
    struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return NULL;

  CefRefPtr<CefBrowser> browserPtr = CefBrowserCppToC::Get(self);
  CefRefPtr<CefFrame> framePtr = browserPtr->GetFocusedFrame();
  if(framePtr.get())
    return CefFrameCppToC::Wrap(framePtr);
  return NULL; 
}

struct _cef_frame_t* CEF_CALLBACK browser_get_frame(struct _cef_browser_t* self,
    const cef_string_t* name)
{
  DCHECK(self);
  if(!self)
    return NULL;

  CefRefPtr<CefBrowser> browserPtr = CefBrowserCppToC::Get(self);
  CefRefPtr<CefFrame> framePtr = browserPtr->GetFrame(CefString(name));
  if(framePtr.get())
    return CefFrameCppToC::Wrap(framePtr);
  return NULL;
}

void CEF_CALLBACK browser_get_frame_names(struct _cef_browser_t* self,
    cef_string_list_t names)
{
  DCHECK(self);
  DCHECK(names);
  if(!self || !names)
    return;

  CefRefPtr<CefBrowser> browserPtr = CefBrowserCppToC::Get(self);
  std::vector<CefString> stringList;
  browserPtr->GetFrameNames(stringList);
  transfer_string_list_contents(stringList, names);
}

void CEF_CALLBACK browser_find(struct _cef_browser_t* self, int identifier,
    const cef_string_t* searchText, int forward, int matchCase, int findNext)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->Find(identifier, CefString(searchText),
      forward?true:false, matchCase?true:false, findNext?true:false);
}

void CEF_CALLBACK browser_stop_finding(struct _cef_browser_t* self,
    int clearSelection)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->StopFinding(clearSelection?true:false);
}

double CEF_CALLBACK browser_get_zoom_level(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return 0.0;

  return CefBrowserCppToC::Get(self)->GetZoomLevel();
}

void CEF_CALLBACK browser_set_zoom_level(struct _cef_browser_t* self,
    double zoomLevel)
{
  DCHECK(self);
  if(!self)
    return;

  return CefBrowserCppToC::Get(self)->SetZoomLevel(zoomLevel);
}

void CEF_CALLBACK browser_show_dev_tools(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return;


  CefBrowserCppToC::Get(self)->ShowDevTools();
}

void CEF_CALLBACK browser_close_dev_tools(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->CloseDevTools();
}

int CEF_CALLBACK browser_is_window_rendering_disabled(
    struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefBrowserCppToC::Get(self)->IsWindowRenderingDisabled();
}

int CEF_CALLBACK browser_get_size(struct _cef_browser_t* self,
    enum cef_paint_element_type_t type, int* width, int* height)
{
  DCHECK(self);
  DCHECK(width);
  DCHECK(height);
  if(!self || !width || !height)
    return 0;

  return CefBrowserCppToC::Get(self)->GetSize(type, *width, *height);
}

void CEF_CALLBACK browser_set_size(struct _cef_browser_t* self,
    enum cef_paint_element_type_t type, int width, int height)
{
  DCHECK(self);
  if(!self)
    return;

  return CefBrowserCppToC::Get(self)->SetSize(type, width, height);
}

int CEF_CALLBACK browser_is_popup_visible(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefBrowserCppToC::Get(self)->IsPopupVisible();
}

void CEF_CALLBACK browser_hide_popup(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->HidePopup();
}

void CEF_CALLBACK browser_invalidate(struct _cef_browser_t* self,
    const cef_rect_t* dirtyRect)
{
  DCHECK(self);
  DCHECK(dirtyRect);
  if(!self || !dirtyRect)
    return;

  CefRect rect(*dirtyRect);
  CefBrowserCppToC::Get(self)->Invalidate(rect);
}

int CEF_CALLBACK browser_get_image(struct _cef_browser_t* self,
    enum cef_paint_element_type_t type, int width, int height, void* buffer)
{
  DCHECK(self);
  DCHECK(buffer);
  if(!self || !buffer)
    return 0;

  return CefBrowserCppToC::Get(self)->GetImage(type, width, height, buffer);
}

void CEF_CALLBACK browser_send_key_event(struct _cef_browser_t* self,
    enum cef_key_type_t type, int key, int modifiers, int sysChar,
    int imeChar)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->SendKeyEvent(type, key, modifiers,
      sysChar?true:false, imeChar?true:false);
}

void CEF_CALLBACK browser_send_mouse_click_event(struct _cef_browser_t* self,
    int x, int y, enum cef_mouse_button_type_t type, int mouseUp,
    int clickCount)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->SendMouseClickEvent(x, y, type,
      mouseUp?true:false, clickCount);
}

void CEF_CALLBACK browser_send_mouse_move_event(struct _cef_browser_t* self,
    int x, int y, int mouseLeave)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->SendMouseMoveEvent(x, y, mouseLeave?true:false);
}

void CEF_CALLBACK browser_send_mouse_wheel_event(struct _cef_browser_t* self,
    int x, int y, int delta)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->SendMouseWheelEvent(x, y, delta);
}

void CEF_CALLBACK browser_send_focus_event(struct _cef_browser_t* self,
    int setFocus)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->SendFocusEvent(setFocus?true:false);
}

void CEF_CALLBACK browser_send_capture_lost_event(struct _cef_browser_t* self)
{
  DCHECK(self);
  if(!self)
    return;

  CefBrowserCppToC::Get(self)->SendCaptureLostEvent();
}


// CONSTRUCTOR - Do not edit by hand.

CefBrowserCppToC::CefBrowserCppToC(CefBrowser* cls)
    : CefCppToC<CefBrowserCppToC, CefBrowser, cef_browser_t>(cls)
{
  struct_.struct_.parent_window_will_close = browser_parent_window_will_close;
  struct_.struct_.close_browser = browser_close_browser;
  struct_.struct_.can_go_back = browser_can_go_back;
  struct_.struct_.go_back = browser_go_back;
  struct_.struct_.can_go_forward = browser_can_go_forward;
  struct_.struct_.go_forward = browser_go_forward;
  struct_.struct_.reload = browser_reload;
  struct_.struct_.reload_ignore_cache = browser_reload_ignore_cache;
  struct_.struct_.stop_load = browser_stop_load;
  struct_.struct_.set_focus = browser_set_focus;
  struct_.struct_.get_window_handle = browser_get_window_handle;
  struct_.struct_.get_opener_window_handle = browser_get_opener_window_handle;
  struct_.struct_.is_popup = browser_is_popup;
  struct_.struct_.has_document = browser_has_document;
  struct_.struct_.get_client = browser_get_client;
  struct_.struct_.get_main_frame = browser_get_main_frame;
  struct_.struct_.get_focused_frame = browser_get_focused_frame;
  struct_.struct_.get_frame = browser_get_frame;
  struct_.struct_.get_frame_names = browser_get_frame_names;
  struct_.struct_.find = browser_find;
  struct_.struct_.stop_finding = browser_stop_finding;
  struct_.struct_.get_zoom_level = browser_get_zoom_level;
  struct_.struct_.set_zoom_level = browser_set_zoom_level;
  struct_.struct_.show_dev_tools = browser_show_dev_tools;
  struct_.struct_.close_dev_tools = browser_close_dev_tools;
  struct_.struct_.is_window_rendering_disabled =
      browser_is_window_rendering_disabled;
  struct_.struct_.get_size = browser_get_size;
  struct_.struct_.set_size = browser_set_size;
  struct_.struct_.is_popup_visible = browser_is_popup_visible;
  struct_.struct_.hide_popup = browser_hide_popup;
  struct_.struct_.invalidate = browser_invalidate;
  struct_.struct_.get_image = browser_get_image;
  struct_.struct_.send_key_event = browser_send_key_event;
  struct_.struct_.send_mouse_click_event = browser_send_mouse_click_event;
  struct_.struct_.send_mouse_move_event = browser_send_mouse_move_event;
  struct_.struct_.send_mouse_wheel_event = browser_send_mouse_wheel_event;
  struct_.struct_.send_focus_event = browser_send_focus_event;
  struct_.struct_.send_capture_lost_event = browser_send_capture_lost_event;
}

#ifndef NDEBUG
template<> long CefCppToC<CefBrowserCppToC, CefBrowser,
    cef_browser_t>::DebugObjCt = 0;
#endif
