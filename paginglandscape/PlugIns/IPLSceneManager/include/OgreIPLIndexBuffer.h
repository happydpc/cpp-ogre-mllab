/***************************************************************************
  OgreIPLIndexBuffer.h  

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.

***************************************************************************/

#ifndef __IPLINDEXBUFFER_H__
#define __IPLINDEXBUFFER_H__

#include "OgreIPLPrerequisites.h"
#include "OgreIPLRenderable.h"
#include "OgreIPLIndexBufferCache.h"

#include <OgreSingleton.h>

namespace Ogre
{

class IPLIndexBuffer : public Singleton< IPLIndexBuffer >
{
public:
	IPLIndexBuffer( );

	~IPLIndexBuffer( );

	IndexData *getIndexData( IPLRenderable* renderable );

	/** Override standard Singleton retrieval.
		@remarks
			Why do we do this? Well, it's because the Singleton implementation is in a .h file,
			which means it gets compiled into anybody who includes it. This is needed for the Singleton
            template to work, but we actually only want it compiled into the implementation of the
			class based on the Singleton, not all of them. If we don't change this, we get link errors
			when trying to use the Singleton-based class from an outside dll.
		@par
			This method just delegates to the template version anyway, but the implementation stays in this
			single compilation unit, preventing link errors.
	*/
	static IPLIndexBuffer& getSingleton( void );

protected:
    LevelArray mLevelIndex;

	// Store the indexes for every combination
	IndexData* mIndexes[ 16 ];

	// getting ready for some form of LOD
	IPLIndexBufferCache mIndexCache;
};

}

#endif
