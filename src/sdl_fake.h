/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2009 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Sam Lantinga
    slouken@libsdl.org
*/

#ifndef _SDL_FAKE
#define _SDL_FAKE

typedef unsigned char       Uint8;
typedef short int           Sint16;
typedef unsigned short int  Uint16;


/** @name Transparency definitions
 *  These define alpha as the opacity of a surface
 */
/*@{*/
#define SDL_ALPHA_OPAQUE 255
#define SDL_ALPHA_TRANSPARENT 0
/*@}*/

/** @name Useful data types */
/*@{*/
typedef struct SDL_Rect {
	Sint16 x, y;
	Uint16 w, h;
} SDL_Rect;

typedef struct SDL_Color {
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 unused;
} SDL_Color;
#define SDL_Colour SDL_Color

typedef struct SDL_Palette {
	int       ncolors;
	SDL_Color *colors;
} SDL_Palette;
/*@}*/

/** Everything in the pixel format structure is read-only */
typedef struct SDL_PixelFormat {
	SDL_Palette *palette;
	Uint8  BitsPerPixel;
	Uint8  BytesPerPixel;
	Uint8  Rloss;
	Uint8  Gloss;
	Uint8  Bloss;
	Uint8  Aloss;
	Uint8  Rshift;
	Uint8  Gshift;
	Uint8  Bshift;
	Uint8  Ashift;
	Uint32 Rmask;
	Uint32 Gmask;
	Uint32 Bmask;
	Uint32 Amask;

	/** RGB color key information */
	Uint32 colorkey;
	/** Alpha value information (per-surface alpha) */
	Uint8  alpha;
} SDL_PixelFormat;

/** This structure should be treated as read-only, except for 'pixels',
 *  which, if not NULL, contains the raw pixel data for the surface.
 */
typedef struct SDL_Surface {
	Uint32 flags;				/**< Read-only */
	SDL_PixelFormat *format;		/**< Read-only */
	int w, h;				/**< Read-only */
	Uint16 pitch;				/**< Read-only */
	void *pixels;				/**< Read-write */
	int offset;				/**< Private */

	/** Hardware-specific surface info */
	void *hwdata;

	/** clipping information */
	SDL_Rect clip_rect;			/**< Read-only */
	Uint32 unused1;				/**< for binary compatibility */

	/** Allow recursive locks */
	Uint32 locked;				/**< Private */

	/** info for fast blit mapping to other surfaces */
	void *map;		/**< Private */

	/** format version, bumped at every change to invalidate blit maps */
	unsigned int format_version;		/**< Private */

	/** Reference count -- used when freeing surface */
	int refcount;				/**< Read-mostly */
} SDL_Surface;

/** @name SDL_Surface Flags
 *  These are the currently supported flags for the SDL_surface
 */
/*@{*/

/** Available for SDL_CreateRGBSurface() or SDL_SetVideoMode() */
/*@{*/
#define SDL_SWSURFACE	0x00000000	/**< Surface is in system memory */
#define SDL_HWSURFACE	0x00000001	/**< Surface is in video memory */
#define SDL_ASYNCBLIT	0x00000004	/**< Use asynchronous blits if possible */
/*@}*/

/** Available for SDL_SetVideoMode() */
/*@{*/
#define SDL_ANYFORMAT	0x10000000	/**< Allow any video depth/pixel-format */
#define SDL_HWPALETTE	0x20000000	/**< Surface has exclusive palette */
#define SDL_DOUBLEBUF	0x40000000	/**< Set up double-buffered video mode */
#define SDL_FULLSCREEN	0x80000000	/**< Surface is a full screen display */
#define SDL_OPENGL      0x00000002      /**< Create an OpenGL rendering context */
#define SDL_OPENGLBLIT	0x0000000A	/**< Create an OpenGL rendering context and use it for blitting */
#define SDL_RESIZABLE	0x00000010	/**< This video mode may be resized */
#define SDL_NOFRAME	0x00000020	/**< No window caption or edge frame */
/*@}*/

/** Used internally (read-only) */
/*@{*/
#define SDL_HWACCEL	0x00000100	/**< Blit uses hardware acceleration */
#define SDL_SRCCOLORKEY	0x00001000	/**< Blit uses a source color key */
#define SDL_RLEACCELOK	0x00002000	/**< Private flag */
#define SDL_RLEACCEL	0x00004000	/**< Surface is RLE encoded */
#define SDL_SRCALPHA	0x00010000	/**< Blit uses source alpha blending */
#define SDL_PREALLOC	0x01000000	/**< Surface uses preallocated memory */
/*@}*/

/*@}*/

/** Evaluates to true if the surface needs to be locked before access */
#define SDL_MUSTLOCK(surface)	\
  (surface->offset ||		\
  ((surface->flags & (SDL_HWSURFACE|SDL_ASYNCBLIT|SDL_RLEACCEL)) != 0))

/** typedef for private surface blitting functions */
typedef int (*SDL_blit)(struct SDL_Surface *src, SDL_Rect *srcrect,
			struct SDL_Surface *dst, SDL_Rect *dstrect);


/** Useful for determining the video hardware capabilities */
typedef struct SDL_VideoInfo {
	Uint32 hw_available :1;	/**< Flag: Can you create hardware surfaces? */
	Uint32 wm_available :1;	/**< Flag: Can you talk to a window manager? */
	Uint32 UnusedBits1  :6;
	Uint32 UnusedBits2  :1;
	Uint32 blit_hw      :1;	/**< Flag: Accelerated blits HW --> HW */
	Uint32 blit_hw_CC   :1;	/**< Flag: Accelerated blits with Colorkey */
	Uint32 blit_hw_A    :1;	/**< Flag: Accelerated blits with Alpha */
	Uint32 blit_sw      :1;	/**< Flag: Accelerated blits SW --> HW */
	Uint32 blit_sw_CC   :1;	/**< Flag: Accelerated blits with Colorkey */
	Uint32 blit_sw_A    :1;	/**< Flag: Accelerated blits with Alpha */
	Uint32 blit_fill    :1;	/**< Flag: Accelerated color fill */
	Uint32 UnusedBits3  :16;
	Uint32 video_mem;	/**< The total amount of video memory (in K) */
	SDL_PixelFormat *vfmt;	/**< Value: The format of the video surface */
	int    current_w;	/**< Value: The current video mode width */
	int    current_h;	/**< Value: The current video mode height */
} SDL_VideoInfo;


/** @name Overlay Formats
 *  The most common video overlay formats.
 *  For an explanation of these pixel formats, see:
 *	http://www.webartz.com/fourcc/indexyuv.htm
 *
 *  For information on the relationship between color spaces, see:
 *  http://www.neuro.sfc.keio.ac.jp/~aly/polygon/info/color-space-faq.html
 */
/*@{*/
#define SDL_YV12_OVERLAY  0x32315659	/**< Planar mode: Y + V + U  (3 planes) */
#define SDL_IYUV_OVERLAY  0x56555949	/**< Planar mode: Y + U + V  (3 planes) */
#define SDL_YUY2_OVERLAY  0x32595559	/**< Packed mode: Y0+U0+Y1+V0 (1 plane) */
#define SDL_UYVY_OVERLAY  0x59565955	/**< Packed mode: U0+Y0+V0+Y1 (1 plane) */
#define SDL_YVYU_OVERLAY  0x55595659	/**< Packed mode: Y0+V0+Y1+U0 (1 plane) */
/*@}*/

/** The YUV hardware video overlay */
typedef struct SDL_Overlay {
	Uint32 format;				/**< Read-only */
	int w, h;				/**< Read-only */
	int planes;				/**< Read-only */
	Uint16 *pitches;			/**< Read-only */
	Uint8 **pixels;				/**< Read-write */

	/** @name Hardware-specific surface info */
        /*@{*/
	void *hwfuncs;
	void *hwdata;
        /*@{*/

	/** @name Special flags */
        /*@{*/
	Uint32 hw_overlay :1;	/**< Flag: This overlay hardware accelerated? */
	Uint32 UnusedBits :31;
        /*@}*/
} SDL_Overlay;


/** Public enumeration for setting the OpenGL window attributes. */
typedef enum {
    SDL_GL_RED_SIZE,
    SDL_GL_GREEN_SIZE,
    SDL_GL_BLUE_SIZE,
    SDL_GL_ALPHA_SIZE,
    SDL_GL_BUFFER_SIZE,
    SDL_GL_DOUBLEBUFFER,
    SDL_GL_DEPTH_SIZE,
    SDL_GL_STENCIL_SIZE,
    SDL_GL_ACCUM_RED_SIZE,
    SDL_GL_ACCUM_GREEN_SIZE,
    SDL_GL_ACCUM_BLUE_SIZE,
    SDL_GL_ACCUM_ALPHA_SIZE,
    SDL_GL_STEREO,
    SDL_GL_MULTISAMPLEBUFFERS,
    SDL_GL_MULTISAMPLESAMPLES,
    SDL_GL_ACCELERATED_VISUAL,
    SDL_GL_SWAP_CONTROL
} SDL_GLattr;


#endif
