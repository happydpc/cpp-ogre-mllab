/***************************************************************************
OgrePagingLandScapeTexture_BaseTexture2.h  -  description
  -------------------
  begin                : Mon Apr 26 2004
  copyright            : (C) 2002-2006 by Jose A Milan & Tuan Kuranes
  email                : spoke@supercable.es & tuan.kuranes@free.fr
***************************************************************************/

/***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU Lesser General Public License as        *
*   published by the Free Software Foundation; either version 2 of the    *
*   License, or (at your option) any later version.                       *
*                                                                         *
***************************************************************************/

#ifndef PagingLandScapeTexture_BaseTexture2_H
#define PagingLandScapeTexture_BaseTexture2_H

#include "OgrePagingLandScapePrerequisites.h"

namespace Ogre
{
    class PagingLandScapeTexture_BaseTexture2 : public PagingLandScapeTexture
    {
        public:
	        PagingLandScapeTexture_BaseTexture2(PagingLandScapeTextureManager *textureMgr);
             String getName() const{return String("BaseTexture2");}
			void setOptions(void);
	         ~PagingLandScapeTexture_BaseTexture2(void);

             PagingLandScapeTexture* newTexture();
             bool isMaterialSupported(); 

    };
}
#endif
