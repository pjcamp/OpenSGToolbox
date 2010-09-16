//------------------------------------------------------------------------------
// File: DShowUtil.h
//
// Desc: DirectShow sample code - prototypes for utility functions
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//------------------------------------------------------------------------------

#ifndef DSHOWUTIL_H
#define DSHOWUTIL_H

#include <OSGConfig.h>

#include "OSGDirectShowVideoWrapper.h"

#ifdef OSG_WITH_DIRECT_SHOW

#include <windows.h>

#define FAIL_RET(x) do { if( FAILED( hr = ( x  ) ) ) \
    return hr; } while(0)

//
// Function prototypes for DirectShow applications
//
HRESULT GetPin(IBaseFilter * pFilter, PIN_DIRECTION dirrequired, 
               int iNum, IPin **ppPin);
    
HRESULT FindOtherSplitterPin(IPin *pPinIn, GUID guid, 
               int nStream, IPin **ppSplitPin);
    
HRESULT SeekNextFrame(IMediaSeeking * pSeeking, double FPS, long Frame );
    
IPin * GetInPin ( IBaseFilter *pFilter, int Num );
IPin * GetOutPin( IBaseFilter *pFilter, int Num );

HRESULT CountFilterPins(IBaseFilter *pFilter, ULONG *pulInPins, ULONG *pulOutPins);
HRESULT CountTotalFilterPins(IBaseFilter *pFilter, ULONG *pulPins);

HRESULT AddFilterByCLSID(IGraphBuilder *pGraph, const GUID& clsid, LPCWSTR wszName, IBaseFilter **ppFilter);
HRESULT GetNextFilter( IBaseFilter *pFilter, PIN_DIRECTION Dir, IBaseFilter **ppNext, IPin **ppPin);

// Find a renderer filter in an existing graph
HRESULT FindRenderer(IGraphBuilder *pGB, const GUID *mediatype, IBaseFilter **ppFilter);
HRESULT FindAudioRenderer(IGraphBuilder *pGB, IBaseFilter **ppFilter);
HRESULT FindVideoRenderer(IGraphBuilder *pGB, IBaseFilter **ppFilter);

// Finds a filter's server name
void ShowFilenameByCLSID(REFCLSID clsid, TCHAR *szFilename);

// Media file information
HRESULT GetFileDurationString(IMediaSeeking *pMS, TCHAR *szDuration);

// Property pages and capabilities
//BOOL SupportsPropertyPage(IBaseFilter *pFilter);
//HRESULT ShowFilterPropertyPage(IBaseFilter *pFilter, HWND hwndParent);
BOOL CanFrameStep(IGraphBuilder *pGB);

// Debug helper functions
void TurnOnDebugDllDebugging( );
void DbgPrint( char * pText );

// Adds/removes a DirectShow filter graph from the Running Object Table,
// allowing GraphEdit to "spy" on a remote filter graph if enabled.
HRESULT AddGraphToROT(IUnknown *pUnkGraph, DWORD *pdwRegister);
void RemoveGraphFromROT(DWORD pdwRegister);

// Helper function to replace the BaseClasses' DeleteMediaType() method
// implemented in mtype.cpp.
void UtilDeleteMediaType(AM_MEDIA_TYPE *pmt);
void UtilFreeMediaType(AM_MEDIA_TYPE& mt);

// Helper functions to save and load graphs to persistent storage.
// These methods replace the use of RenderFile() with .GRF files,
// which is no longer supported in DirectX 9.
//HRESULT SaveGraphFile(IGraphBuilder *pGraph, WCHAR *wszPath);
//HRESULT LoadGraphFile(IGraphBuilder *pGraph, const WCHAR* wszName);

#endif /* OSG_WITH_DIRECT_SHOW */

#endif