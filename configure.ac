AC_INIT([upftii], [0.0.1], [paulmoa@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_11

AC_SEARCH_LIBS([SDL_Init], [SDL2])
PKG_CHECK_MODULES([MAGICK_WAND], [MagickWand])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
