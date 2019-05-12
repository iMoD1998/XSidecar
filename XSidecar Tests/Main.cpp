#include <Windows.h>
#include <stdio.h>

#include "XSidecar.h"

typedef unsigned long long QWORD;

int main( )
{
	if ( LoadXSidecar( ) )
	{
		auto List = XSidecarOpenEmulatorList( ); // List is actually a structure
		auto ListCount = XSidecarGetListItemCount( List ); // *(DWORD*)(List + 0x4)

		printf( "List: %08X\n", List );

		printf( "List Count: %i\n", ListCount );

		WCHAR ConsoleNameBuffer[ 0x200 ];
		BYTE SerialNumber[ 0x8 ]; // this is most likely a struct

		for ( int i = 0; i < ListCount; ++i )
		{
			auto Sidecar = XSidecarOpenListItem( List, i );

			if ( XSidecarGetName( Sidecar, ConsoleNameBuffer, 50, 0 ) == 0 )
			{
				printf( "Name: %ws\n", ConsoleNameBuffer );
			}

			memset( ConsoleNameBuffer, 0, sizeof( ConsoleNameBuffer ) );

			if ( XSidecarGetConsoleSerialNumber( Sidecar, SerialNumber ) == 0 )
			{
				printf( "Serial Number: %02X%02X%02X%02X%02X%02X \n", SerialNumber[ 1 ], SerialNumber[ 2 ], SerialNumber[ 3 ], SerialNumber[ 4 ], SerialNumber[ 5 ], SerialNumber[ 6 ] );
			}

			XSidecarEmulatorSetPowerState( Sidecar, FALSE );

		}

		XSidecarCloseList( List );
	}

	UnloadXSidecar( );

	getchar( );

	return 0;
}