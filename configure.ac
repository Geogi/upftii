AC_INIT([upftii], [0.2.1], [paulmoa@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_11

SDL_VERSION=2.0.0
AM_PATH_SDL2([$SDL_VERSION], :, AC_MSG_ERROR([*** SDL version $SDL_VERSION not found!]))
PKG_CHECK_MODULES([MAGICK_WAND], [MagickWand])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile res/Makefile res/left/Makefile 
			  res/right/Makefile src/Makefile])
AC_OUTPUT
