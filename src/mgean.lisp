;; This file was automatically generated by SWIG (http://www.swig.org).
;; Version 1.3.40
;;
;; Do not make changes to this file unless you know what you are doing--modify
;; the SWIG interface file instead.

(defpackage :mgean
  (:use :common-lisp :ffi)
  (:export
	:SDL_ALPHA_OPAQUE
	:SDL_ALPHA_TRANSPARENT
	:make-SDL_Rect
	:SDL_Rect-x
	:SDL_Rect-y
	:SDL_Rect-w
	:SDL_Rect-h
	:make-SDL_Color
	:SDL_Color-r
	:SDL_Color-g
	:SDL_Color-b
	:SDL_Color-unused
	:make-SDL_Palette
	:SDL_Palette-ncolors
	:SDL_Palette-colors
	:make-SDL_PixelFormat
	:SDL_PixelFormat-palette
	:SDL_PixelFormat-BitsPerPixel
	:SDL_PixelFormat-BytesPerPixel
	:SDL_PixelFormat-Rloss
	:SDL_PixelFormat-Gloss
	:SDL_PixelFormat-Bloss
	:SDL_PixelFormat-Aloss
	:SDL_PixelFormat-Rshift
	:SDL_PixelFormat-Gshift
	:SDL_PixelFormat-Bshift
	:SDL_PixelFormat-Ashift
	:SDL_PixelFormat-Rmask
	:SDL_PixelFormat-Gmask
	:SDL_PixelFormat-Bmask
	:SDL_PixelFormat-Amask
	:SDL_PixelFormat-colorkey
	:SDL_PixelFormat-alpha
	:make-SDL_Surface
	:SDL_Surface-flags
	:SDL_Surface-format
	:SDL_Surface-w
	:SDL_Surface-h
	:SDL_Surface-pitch
	:SDL_Surface-pixels
	:SDL_Surface-offset
	:SDL_Surface-hwdata
	:SDL_Surface-clip_rect
	:SDL_Surface-unused1
	:SDL_Surface-locked
	:SDL_Surface-map
	:SDL_Surface-format_version
	:SDL_Surface-refcount
	:SDL_SWSURFACE
	:SDL_HWSURFACE
	:SDL_ASYNCBLIT
	:SDL_ANYFORMAT
	:SDL_HWPALETTE
	:SDL_DOUBLEBUF
	:SDL_FULLSCREEN
	:SDL_OPENGL
	:SDL_OPENGLBLIT
	:SDL_RESIZABLE
	:SDL_NOFRAME
	:SDL_HWACCEL
	:SDL_SRCCOLORKEY
	:SDL_RLEACCELOK
	:SDL_RLEACCEL
	:SDL_SRCALPHA
	:SDL_PREALLOC
	:make-SDL_VideoInfo
	:SDL_VideoInfo-hw_available
	:SDL_VideoInfo-wm_available
	:SDL_VideoInfo-UnusedBits1
	:SDL_VideoInfo-UnusedBits2
	:SDL_VideoInfo-blit_hw
	:SDL_VideoInfo-blit_hw_CC
	:SDL_VideoInfo-blit_hw_A
	:SDL_VideoInfo-blit_sw
	:SDL_VideoInfo-blit_sw_CC
	:SDL_VideoInfo-blit_sw_A
	:SDL_VideoInfo-blit_fill
	:SDL_VideoInfo-UnusedBits3
	:SDL_VideoInfo-video_mem
	:SDL_VideoInfo-vfmt
	:SDL_VideoInfo-current_w
	:SDL_VideoInfo-current_h
	:SDL_YV12_OVERLAY
	:SDL_IYUV_OVERLAY
	:SDL_YUY2_OVERLAY
	:SDL_UYVY_OVERLAY
	:SDL_YVYU_OVERLAY
	:make-SDL_Overlay
	:SDL_Overlay-format
	:SDL_Overlay-w
	:SDL_Overlay-h
	:SDL_Overlay-planes
	:SDL_Overlay-pitches
	:SDL_Overlay-pixels
	:SDL_Overlay-hwfuncs
	:SDL_Overlay-hwdata
	:SDL_Overlay-hw_overlay
	:SDL_Overlay-UnusedBits
	:SDL_GL_RED_SIZE
	:SDL_GL_GREEN_SIZE
	:SDL_GL_BLUE_SIZE
	:SDL_GL_ALPHA_SIZE
	:SDL_GL_BUFFER_SIZE
	:SDL_GL_DOUBLEBUFFER
	:SDL_GL_DEPTH_SIZE
	:SDL_GL_STENCIL_SIZE
	:SDL_GL_ACCUM_RED_SIZE
	:SDL_GL_ACCUM_GREEN_SIZE
	:SDL_GL_ACCUM_BLUE_SIZE
	:SDL_GL_ACCUM_ALPHA_SIZE
	:SDL_GL_STEREO
	:SDL_GL_MULTISAMPLEBUFFERS
	:SDL_GL_MULTISAMPLESAMPLES
	:SDL_GL_ACCELERATED_VISUAL
	:SDL_GL_SWAP_CONTROL
	:make-NODE
	:NODE-value
	:NODE-node
	:MG_add
	:MG_destructive_map
	:MG_remove_node
	:MG_add_nth
	:MG_list_length
	:MG_remove_list
	:MG_list_nth
	:MG_add_pair
	:MG_get_nth
	:MG_destroy_pair
	:make-MOUSE
	:MOUSE-x
	:MOUSE-y
	:MOUSE-state
	:make-MACHINE
	:MACHINE-screen
	:MACHINE-game_world
	:MACHINE-keyboard_state
	:MACHINE-mouse
	:MACHINE-events
	:MACHINE-view_rect
	:MG_set_view_rect
	:MG_set_world
	:MG_get_machine
	:MG_init_video
	:MG_quit
	:MG_key_down_p
	:MG_get_keys
	:MG_get_mouse_state
	:MG_get_mouse_y
	:MG_get_mouse_x
	:MG_preload_img
	:MG_get_img
	:MG_preload_audio
	:MG_get_audio
	:MG_set_system_font_size
	:MG_preload_ttf
	:MG_get_ttf
	:TUNKNOWN
	:THASH
	:SYMBOL
	:make-HASH
	:HASH-type
	:HASH-values
	:MG_hash_get_key
	:MG_hash_copy
	:MG_hash_dump
	:MG_hash_free
	:MG_text_list
	:make-ANIMATION
	:ANIMATION-anim_array
	:ANIMATION-rect
	:ANIMATION-count
	:ANIMATION-delay
	:ANIMATION-music
	:MG_make_animation
	:MG_set_animation_rects
	:MG_get_animation
	:MG_set_audio
	:make-POINT
	:POINT-x
	:POINT-y
	:make-VECTOR
	:VECTOR-x
	:VECTOR-y
	:make-PHYSICS
	:PHYSICS-m
	:PHYSICS-f
	:PHYSICS-v
	:MG_get_system_dt
	:MG_compute_physics
	:MG_set_environment_physics
	:make-AUDIO
	:AUDIO-repeat
	:AUDIO-channel
	:AUDIO-played_time
	:MG_play_music
	:make-SPRITE
	:SPRITE-anim
	:SPRITE-src
	:SPRITE-dest
	:SPRITE-img
	:SPRITE-args
	:SPRITE-attached_sprites
	:SPRITE-physics
	:SPRITE-time
	:SPRITE-audio_state
	:SPRITE-type
	:TYPE_UNKNOWN
	:MG_send_msg
	:MG_set_rect
	:MG_set_srcrect
	:MG_make_sprite
	:MG_make_sprite_nth
	:MG_draw_stack
	:MG_set_animation
	:MG_set_power
	:MG_set_speed
	:MG_set_weight
	:MG_install_callback
	:MG_set_key
	:MG_get_key
	:MG_set_img
	:MG_remove_sprite
	:MG_move_sprite
	:MG_drawing_stack
	:MG_unload_sprite
	:MG_drawing_stack_free
	:MG_attach_sprite
	:MG_detach_sprite
	:MG_sprite_set_position
	:MG_apply_physics
	:MG_transform_sprites
	:MG_sprite_play_music))

(in-package :mgean)

(default-foreign-language :stdc)

(defconstant SDL_ALPHA_OPAQUE 255)

(defconstant SDL_ALPHA_TRANSPARENT 0)

(ffi:def-c-struct SDL_Rect
	(x ffi:short)
	(y ffi:short)
	(w ffi:ushort)
	(h ffi:ushort))

(ffi:def-c-struct SDL_Color
	(r ffi:uchar)
	(g ffi:uchar)
	(b ffi:uchar)
	(unused ffi:uchar))

(ffi:def-c-struct SDL_Palette
	(ncolors ffi:int)
	(colors (ffi:c-pointer SDL_Color)))

(ffi:def-c-struct SDL_PixelFormat
	(palette (ffi:c-pointer SDL_Palette))
	(BitsPerPixel ffi:uchar)
	(BytesPerPixel ffi:uchar)
	(Rloss ffi:uchar)
	(Gloss ffi:uchar)
	(Bloss ffi:uchar)
	(Aloss ffi:uchar)
	(Rshift ffi:uchar)
	(Gshift ffi:uchar)
	(Bshift ffi:uchar)
	(Ashift ffi:uchar)
	(Rmask Uint32)
	(Gmask Uint32)
	(Bmask Uint32)
	(Amask Uint32)
	(colorkey Uint32)
	(alpha ffi:uchar))

(ffi:def-c-struct SDL_Surface
	(flags Uint32)
	(format (ffi:c-pointer SDL_PixelFormat))
	(w ffi:int)
	(h ffi:int)
	(pitch ffi:ushort)
	(pixels (ffi:c-pointer NIL))
	(offset ffi:int)
	(hwdata (ffi:c-pointer NIL))
	(clip_rect SDL_Rect)
	(unused1 Uint32)
	(locked Uint32)
	(map (ffi:c-pointer NIL))
	(format_version ffi:uint)
	(refcount ffi:int))

(defconstant SDL_SWSURFACE #x00000000)

(defconstant SDL_HWSURFACE #x00000001)

(defconstant SDL_ASYNCBLIT #x00000004)

(defconstant SDL_ANYFORMAT #x10000000)

(defconstant SDL_HWPALETTE #x20000000)

(defconstant SDL_DOUBLEBUF #x40000000)

(defconstant SDL_FULLSCREEN #x80000000)

(defconstant SDL_OPENGL #x00000002)

(defconstant SDL_OPENGLBLIT #x0000000A)

(defconstant SDL_RESIZABLE #x00000010)

(defconstant SDL_NOFRAME #x00000020)

(defconstant SDL_HWACCEL #x00000100)

(defconstant SDL_SRCCOLORKEY #x00001000)

(defconstant SDL_RLEACCELOK #x00002000)

(defconstant SDL_RLEACCEL #x00004000)

(defconstant SDL_SRCALPHA #x00010000)

(defconstant SDL_PREALLOC #x01000000)

(ffi:def-c-struct SDL_VideoInfo
	(hw_available Uint32)
	(wm_available Uint32)
	(UnusedBits1 Uint32)
	(UnusedBits2 Uint32)
	(blit_hw Uint32)
	(blit_hw_CC Uint32)
	(blit_hw_A Uint32)
	(blit_sw Uint32)
	(blit_sw_CC Uint32)
	(blit_sw_A Uint32)
	(blit_fill Uint32)
	(UnusedBits3 Uint32)
	(video_mem Uint32)
	(vfmt (ffi:c-pointer SDL_PixelFormat))
	(current_w ffi:int)
	(current_h ffi:int))

(defconstant SDL_YV12_OVERLAY #x32315659)

(defconstant SDL_IYUV_OVERLAY #x56555949)

(defconstant SDL_YUY2_OVERLAY #x32595559)

(defconstant SDL_UYVY_OVERLAY #x59565955)

(defconstant SDL_YVYU_OVERLAY #x55595659)

(ffi:def-c-struct SDL_Overlay
	(format Uint32)
	(w ffi:int)
	(h ffi:int)
	(planes ffi:int)
	(pitches (ffi:c-pointer ffi:ushort))
	(pixels (ffi:c-pointer (ffi:c-pointer ffi:uchar)))
	(hwfuncs (ffi:c-pointer NIL))
	(hwdata (ffi:c-pointer NIL))
	(hw_overlay Uint32)
	(UnusedBits Uint32))

(ffi:def-c-enum SDL_GLattr (SDL_GL_RED_SIZE )(SDL_GL_GREEN_SIZE )(SDL_GL_BLUE_SIZE )(SDL_GL_ALPHA_SIZE )(SDL_GL_BUFFER_SIZE )(SDL_GL_DOUBLEBUFFER )(SDL_GL_DEPTH_SIZE )(SDL_GL_STENCIL_SIZE )(SDL_GL_ACCUM_RED_SIZE )(SDL_GL_ACCUM_GREEN_SIZE )(SDL_GL_ACCUM_BLUE_SIZE )(SDL_GL_ACCUM_ALPHA_SIZE )(SDL_GL_STEREO )(SDL_GL_MULTISAMPLEBUFFERS )(SDL_GL_MULTISAMPLESAMPLES )(SDL_GL_ACCELERATED_VISUAL )(SDL_GL_SWAP_CONTROL ))

(ffi:def-c-struct NODE
	(value (ffi:c-pointer NIL))
	(node (ffi:c-pointer NODE)))

(ffi:def-call-out MG_add
	(:name "MG_add")
	(:arguments (root (ffi:c-pointer (ffi:c-pointer NODE)))
		(value (ffi:c-pointer NIL)))
	(:library +library-name+))

(ffi:def-call-out MG_destructive_map
	(:name "MG_destructive_map")
	(:arguments (list (ffi:c-pointer NODE))
		(func (ffi:c-function (:arguments (arg0 (ffi:c-pointer NIL)))
 				(:return-type NIL))))
	(:library +library-name+))

(ffi:def-call-out MG_remove_node
	(:name "MG_remove_node")
	(:arguments (l (ffi:c-pointer (ffi:c-pointer NODE)))
		(value (ffi:c-pointer NIL)))
	(:return-type (ffi:c-pointer NIL))
	(:library +library-name+))

(ffi:def-call-out MG_add_nth
	(:name "MG_add_nth")
	(:arguments (l (ffi:c-pointer (ffi:c-pointer NODE)))
		(val (ffi:c-pointer NIL))
		(nth ffi:int))
	(:return-type (ffi:c-pointer NODE))
	(:library +library-name+))

(ffi:def-call-out MG_list_length
	(:name "MG_list_length")
	(:arguments (l (ffi:c-pointer NODE)))
	(:return-type ffi:int)
	(:library +library-name+))

(ffi:def-call-out MG_remove_list
	(:name "MG_remove_list")
	(:arguments (list (ffi:c-pointer NODE))
		(func (ffi:c-function (:arguments (arg0 (ffi:c-pointer NIL)))
 				(:return-type NIL))))
	(:library +library-name+))

(ffi:def-call-out MG_list_nth
	(:name "MG_list_nth")
	(:arguments (l (ffi:c-pointer NODE))
		(n ffi:int))
	(:return-type (ffi:c-pointer NIL))
	(:library +library-name+))

(ffi:def-call-out MG_add_pair
	(:name "MG_add_pair")
	(:arguments (list (ffi:c-pointer (ffi:c-pointer NODE)))
		(key ffi:c-string)
		(value (ffi:c-pointer NIL)))
	(:library +library-name+))

(ffi:def-call-out MG_get_nth
	(:name "MG_get_nth")
	(:arguments (list (ffi:c-pointer NODE))
		(symbolic_id ffi:c-string))
	(:return-type (ffi:c-pointer NIL))
	(:library +library-name+))

(ffi:def-call-out MG_destroy_pair
	(:name "MG_destroy_pair")
	(:arguments (l (ffi:c-pointer NODE))
		(func (ffi:c-function (:arguments (arg0 (ffi:c-pointer NIL)))
 				(:return-type NIL))))
	(:library +library-name+))

(ffi:def-c-struct MOUSE
	(x ffi:int)
	(y ffi:int)
	(state ffi:uchar))

(ffi:def-c-struct MACHINE
	(screen (ffi:c-pointer SDL_Surface))
	(game_world (ffi:c-pointer SDL_Surface))
	(keyboard_state (ffi:c-pointer ffi:uchar))
	(mouse MOUSE)
	(events (ffi:c-pointer NODE))
	(view_rect SDL_Rect))

(ffi:def-call-out MG_set_view_rect
	(:name "MG_set_view_rect")
	(:arguments (r SDL_Rect))
	(:library +library-name+))

(ffi:def-call-out MG_set_world
	(:name "MG_set_world")
	(:arguments (w ffi:int)
		(h ffi:int))
	(:return-type (ffi:c-pointer SDL_Surface))
	(:library +library-name+))

(ffi:def-call-out MG_get_machine
	(:name "MG_get_machine")
	(:return-type (ffi:c-pointer MACHINE))
	(:library +library-name+))

(ffi:def-call-out MG_init_video
	(:name "MG_init_video")
	(:arguments (width ffi:int)
		(height ffi:int)
		(video_flags Uint32))
	(:return-type ffi:int)
	(:library +library-name+))

(ffi:def-call-out MG_quit
	(:name "MG_quit")
	(:library +library-name+))

(ffi:def-call-out MG_key_down_p
	(:name "MG_key_down_p")
	(:arguments (key ffi:int))
	(:return-type ffi:int)
	(:library +library-name+))

(ffi:def-call-out MG_get_keys
	(:name "MG_get_keys")
	(:library +library-name+))

(ffi:def-call-out MG_get_mouse_state
	(:name "MG_get_mouse_state")
	(:return-type ffi:uchar)
	(:library +library-name+))

(ffi:def-call-out MG_get_mouse_y
	(:name "MG_get_mouse_y")
	(:return-type ffi:int)
	(:library +library-name+))

(ffi:def-call-out MG_get_mouse_x
	(:name "MG_get_mouse_x")
	(:return-type ffi:int)
	(:library +library-name+))

(ffi:def-call-out MG_preload_img
	(:name "MG_preload_img")
	(:arguments (path ffi:c-string))
	(:return-type ffi:int)
	(:library +library-name+))

(ffi:def-call-out MG_get_img
	(:name "MG_get_img")
	(:arguments (path ffi:c-string))
	(:return-type (ffi:c-pointer SDL_Surface))
	(:library +library-name+))

(ffi:def-call-out MG_preload_audio
	(:name "MG_preload_audio")
	(:arguments (path ffi:c-string))
	(:return-type ffi:int)
	(:library +library-name+))

(ffi:def-call-out MG_get_audio
	(:name "MG_get_audio")
	(:arguments (path ffi:c-string))
	(:return-type (ffi:c-pointer Mix_Chunk))
	(:library +library-name+))

(ffi:def-call-out MG_set_system_font_size
	(:name "MG_set_system_font_size")
	(:arguments (size ffi:int))
	(:library +library-name+))

(ffi:def-call-out MG_preload_ttf
	(:name "MG_preload_ttf")
	(:arguments (path ffi:c-string))
	(:return-type (ffi:c-pointer TTF_Font))
	(:library +library-name+))

(ffi:def-call-out MG_get_ttf
	(:name "MG_get_ttf")
	(:arguments (path ffi:c-string))
	(:return-type (ffi:c-pointer TTF_Font))
	(:library +library-name+))

(ffi:def-c-enum HASH_TYPES (TUNKNOWN 0x0)(THASH )(SYMBOL ))

(ffi:def-c-struct HASH
	(type ffi:int)
	(values (ffi:c-pointer NODE)))

(ffi:def-call-out MG_hash_get_key
	(:name "MG_hash_get_key")
	(:arguments (h (ffi:c-pointer HASH))
		(key ffi:c-string))
	(:return-type (ffi:c-pointer HASH))
	(:library +library-name+))

(ffi:def-call-out MG_hash_copy
	(:name "MG_hash_copy")
	(:arguments (h (ffi:c-pointer HASH)))
	(:return-type (ffi:c-pointer HASH))
	(:library +library-name+))

(ffi:def-call-out MG_hash_dump
	(:name "MG_hash_dump")
	(:arguments (h (ffi:c-pointer HASH)))
	(:return-type ffi:c-string)
	(:library +library-name+))

(ffi:def-call-out MG_hash_free
	(:name "MG_hash_free")
	(:arguments (h (ffi:c-pointer HASH)))
	(:library +library-name+))

(ffi:def-call-out MG_text_list
	(:name "MG_text_list")
	(:arguments (in ffi:c-string))
	(:return-type (ffi:c-pointer HASH))
	(:library +library-name+))

(ffi:def-c-struct ANIMATION
	(anim_array (ffi:c-pointer SDL_Rect))
	(rect SDL_Rect)
	(count Uint32)
	(delay Uint32)
	(music (ffi:c-pointer Mix_Chunk)))

(ffi:def-call-out MG_make_animation
	(:name "MG_make_animation")
	(:arguments (s ffi:c-string)
		(count ffi:int)
		(delay Uint32)
		(r (ffi:c-pointer SDL_Rect)))
	(:return-type (ffi:c-pointer ANIMATION))
	(:library +library-name+))

(ffi:def-call-out MG_set_animation_rects
	(:name "MG_set_animation_rects")
	(:arguments (a (ffi:c-pointer ANIMATION))
		(rects (ffi:c-pointer SDL_Rect)))
	(:library +library-name+))

(ffi:def-call-out MG_get_animation
	(:name "MG_get_animation")
	(:arguments (string ffi:c-string))
	(:return-type (ffi:c-pointer ANIMATION))
	(:library +library-name+))

(ffi:def-call-out MG_set_audio
	(:name "MG_set_audio")
	(:arguments (a (ffi:c-pointer ANIMATION))
		(s ffi:c-string))
	(:library +library-name+))

(ffi:def-c-struct POINT
	(x ffi:int)
	(y ffi:int))

(ffi:def-c-struct VECTOR
	(x SINGLE-FLOAT)
	(y SINGLE-FLOAT))

(ffi:def-c-struct PHYSICS
	(m SINGLE-FLOAT)
	(f VECTOR)
	(v VECTOR))

(ffi:def-call-out MG_get_system_dt
	(:name "MG_get_system_dt")
	(:return-type ffi:int)
	(:library +library-name+))

(ffi:def-call-out MG_compute_physics
	(:name "MG_compute_physics")
	(:arguments (p (ffi:c-pointer PHYSICS)))
	(:library +library-name+))

(ffi:def-call-out MG_set_environment_physics
	(:name "MG_set_environment_physics")
	(:arguments (env_physics VECTOR))
	(:library +library-name+))

(ffi:def-c-struct AUDIO
	(repeat ffi:int)
	(channel ffi:int)
	(played_time ffi:int))

(ffi:def-call-out MG_play_music
	(:name "MG_play_music")
	(:arguments (channel (ffi:c-ptr ffi:int))
		(ms_expire ffi:int)
		(current_time ffi:int)
		(m (ffi:c-pointer Mix_Chunk)))
	(:library +library-name+))

(ffi:def-c-struct SPRITE
	(anim (ffi:c-pointer ANIMATION))
	(src SDL_Rect)
	(dest SDL_Rect)
	(img (ffi:c-pointer SDL_Surface))
	(args (ffi:c-pointer NODE))
	(attached_sprites (ffi:c-pointer NODE))
	(physics PHYSICS)
	(time ffi:int)
	(audio_state AUDIO)
	(type ffi:int))

(defconstant TYPE_UNKNOWN 0)

(ffi:def-call-out MG_send_msg
	(:name "MG_send_msg")
	(:arguments (s (ffi:c-pointer SPRITE))
		(msg ffi:c-string))
	(:return-type (ffi:c-pointer NIL))
	(:library +library-name+))

(ffi:def-call-out MG_set_rect
	(:name "MG_set_rect")
	(:arguments (self (ffi:c-pointer SPRITE))
		(r SDL_Rect))
	(:library +library-name+))

(ffi:def-call-out MG_set_srcrect
	(:name "MG_set_srcrect")
	(:arguments (self (ffi:c-pointer SPRITE))
		(r SDL_Rect))
	(:library +library-name+))

(ffi:def-call-out MG_make_sprite
	(:name "MG_make_sprite")
	(:arguments (s (ffi:c-pointer SDL_Surface))
		(src (ffi:c-pointer SDL_Rect)))
	(:return-type (ffi:c-pointer SPRITE))
	(:library +library-name+))

(ffi:def-call-out MG_make_sprite_nth
	(:name "MG_make_sprite_nth")
	(:arguments (s (ffi:c-pointer SDL_Surface))
		(src (ffi:c-pointer SDL_Rect))
		(nth ffi:int))
	(:return-type (ffi:c-pointer SPRITE))
	(:library +library-name+))

(ffi:def-call-out MG_draw_stack
	(:name "MG_draw_stack")
	(:arguments (delay ffi:int))
	(:library +library-name+))

(ffi:def-call-out MG_set_animation
	(:name "MG_set_animation")
	(:arguments (s (ffi:c-pointer SPRITE))
		(string ffi:c-string))
	(:library +library-name+))

(ffi:def-call-out MG_set_power
	(:name "MG_set_power")
	(:arguments (s (ffi:c-pointer SPRITE))
		(v (ffi:c-pointer VECTOR)))
	(:library +library-name+))

(ffi:def-call-out MG_set_speed
	(:name "MG_set_speed")
	(:arguments (s (ffi:c-pointer SPRITE))
		(v (ffi:c-pointer VECTOR)))
	(:library +library-name+))

(ffi:def-call-out MG_set_weight
	(:name "MG_set_weight")
	(:arguments (s (ffi:c-pointer SPRITE))
		(m SINGLE-FLOAT))
	(:library +library-name+))

(ffi:def-call-out MG_install_callback
	(:name "MG_install_callback")
	(:arguments (s (ffi:c-pointer SPRITE))
		(key ffi:c-string)
		(function (ffi:c-pointer NIL)))
	(:library +library-name+))

(ffi:def-call-out MG_set_key
	(:name "MG_set_key")
	(:arguments (s (ffi:c-pointer SPRITE))
		(key ffi:c-string)
		(val (ffi:c-pointer NIL)))
	(:library +library-name+))

(ffi:def-call-out MG_get_key
	(:name "MG_get_key")
	(:arguments (s (ffi:c-pointer SPRITE))
		(key ffi:c-string))
	(:return-type (ffi:c-pointer NIL))
	(:library +library-name+))

(ffi:def-call-out MG_set_img
	(:name "MG_set_img")
	(:arguments (self (ffi:c-pointer SPRITE))
		(surf (ffi:c-pointer SDL_Surface)))
	(:return-type (ffi:c-pointer SDL_Surface))
	(:library +library-name+))

(ffi:def-call-out MG_remove_sprite
	(:name "MG_remove_sprite")
	(:arguments (s (ffi:c-pointer SPRITE)))
	(:library +library-name+))

(ffi:def-call-out MG_move_sprite
	(:name "MG_move_sprite")
	(:arguments (s (ffi:c-pointer SPRITE))
		(dx ffi:int)
		(dy ffi:int))
	(:library +library-name+))

(ffi:def-call-out MG_drawing_stack
	(:name "MG_drawing_stack")
	(:return-type (ffi:c-pointer NODE))
	(:library +library-name+))

(ffi:def-call-out MG_unload_sprite
	(:name "MG_unload_sprite")
	(:arguments (s (ffi:c-pointer SPRITE)))
	(:library +library-name+))

(ffi:def-call-out MG_drawing_stack_free
	(:name "MG_drawing_stack_free")
	(:library +library-name+))

(ffi:def-call-out MG_attach_sprite
	(:name "MG_attach_sprite")
	(:arguments (owner (ffi:c-pointer SPRITE))
		(attached (ffi:c-pointer SPRITE))
		(offset_x ffi:int)
		(offset_y ffi:int))
	(:library +library-name+))

(ffi:def-call-out MG_detach_sprite
	(:name "MG_detach_sprite")
	(:arguments (owner (ffi:c-pointer SPRITE))
		(attached (ffi:c-pointer SPRITE)))
	(:return-type (ffi:c-pointer SPRITE))
	(:library +library-name+))

(ffi:def-call-out MG_sprite_set_position
	(:name "MG_sprite_set_position")
	(:arguments (s (ffi:c-pointer SPRITE))
		(x ffi:int)
		(y ffi:int))
	(:library +library-name+))

(ffi:def-call-out MG_apply_physics
	(:name "MG_apply_physics")
	(:arguments (p (ffi:c-pointer PHYSICS))
		(r SDL_Rect)
		(dt ffi:int))
	(:return-type SDL_Rect)
	(:library +library-name+))

(ffi:def-call-out MG_transform_sprites
	(:name "MG_transform_sprites")
	(:arguments (filter_func (ffi:c-function (:arguments (arg0 (ffi:c-pointer SPRITE)))
 				(:return-type (ffi:c-pointer SPRITE))))
		(move_x ffi:int)
		(move_y ffi:int))
	(:library +library-name+))

(ffi:def-call-out MG_sprite_play_music
	(:name "MG_sprite_play_music")
	(:arguments (self (ffi:c-pointer SPRITE)))
	(:library +library-name+))