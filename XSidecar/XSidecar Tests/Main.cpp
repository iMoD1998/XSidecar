#include <Windows.h>
#include <stdio.h>

#include "XSidecar.h"

typedef unsigned long long QWORD;

int main( )
{
	if ( LoadXSidecar( ) )
	{
		auto List = XSidecarOpenEmulatorList( );
		auto ListCount = XSidecarGetListItemCount( List );

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

			if ( XSidecarGetConsoleSerialNumber( Sidecar, SerialNumber ) == 0 )
			{
				printf( "Serial Number: %02X%02X%02X%02X%02X%02X \n", SerialNumber[ 1 ], SerialNumber[ 2 ], SerialNumber[ 3 ], SerialNumber[ 4 ], SerialNumber[ 5 ], SerialNumber[ 6 ] );
			}

			XSidecarEmulatorSetPowerState( Sidecar, TRUE );
		}

		XSidecarCloseList( List );
	}

	UnloadXSidecar( );

	getchar( );

	return 0;
}