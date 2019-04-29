#pragma once

#include <Windows.h>

typedef HANDLE( WINAPI * XSidecarOpenEmulatorList_t )					( );
typedef HANDLE( WINAPI * XSidecarEmulatorOpenKdPipe_t )				( HANDLE Handle, LPCWSTR Name );
typedef HANDLE( WINAPI * XSidecarEmulatorCloseKdPipe_t )				( HANDLE Pipe );
typedef void	( WINAPI * XSidecarCloseList_t )						( HANDLE List );
typedef SIZE_T( WINAPI * XSidecarGetListItemCount_t )					( HANDLE List );
typedef HANDLE( WINAPI * XSidecarOpenListItem_t )						( HANDLE List, int ListIndex );
typedef HRESULT( WINAPI * XSidecarEmulatorSetPowerState_t )			( HANDLE Handle, BOOL Status );
typedef HRESULT( WINAPI * XSidecarGetName_t )							( HANDLE Handle, LPWSTR Buffer, int Length, int Something );
typedef HRESULT( WINAPI * XSidecarGetConsoleSerialNumber_t )			( HANDLE Handle, BYTE* Buffer );
typedef HRESULT( WINAPI * XSidecarGetVersionInformation_t )			( HANDLE Handle, BYTE* Buffer );
typedef HRESULT( WINAPI * XSidecarGetVersionInformation_t )			( HANDLE Handle, BYTE* Buffer );

extern XSidecarOpenEmulatorList_t XSidecarOpenEmulatorList;
extern XSidecarEmulatorOpenKdPipe_t XSidecarEmulatorOpenKdPipe;
extern XSidecarEmulatorCloseKdPipe_t XSidecarEmulatorCloseKdPipe;
extern XSidecarCloseList_t XSidecarCloseList;
extern XSidecarGetListItemCount_t XSidecarGetListItemCount;
extern XSidecarOpenListItem_t XSidecarOpenListItem;
extern XSidecarEmulatorSetPowerState_t XSidecarEmulatorSetPowerState;
extern XSidecarGetName_t XSidecarGetName;
extern XSidecarGetConsoleSerialNumber_t XSidecarGetConsoleSerialNumber;
extern XSidecarGetVersionInformation_t XSidecarGetVersionInformation;

bool LoadXSidecar( );

bool UnloadXSidecar( );