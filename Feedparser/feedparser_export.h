
#ifndef FEEDPARSER_EXPORT_H
#define FEEDPARSER_EXPORT_H

#ifdef FEEDPARSER_STATIC_DEFINE
#  define FEEDPARSER_EXPORT
#  define FEEDPARSER_NO_EXPORT
#else
#  ifndef FEEDPARSER_EXPORT
#    ifdef Feedparser_EXPORTS
        /* We are building this library */
#      define FEEDPARSER_EXPORT 
#    else
        /* We are using this library */
#      define FEEDPARSER_EXPORT 
#    endif
#  endif

#  ifndef FEEDPARSER_NO_EXPORT
#    define FEEDPARSER_NO_EXPORT 
#  endif
#endif

#ifndef FEEDPARSER_DEPRECATED
#  define FEEDPARSER_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef FEEDPARSER_DEPRECATED_EXPORT
#  define FEEDPARSER_DEPRECATED_EXPORT FEEDPARSER_EXPORT FEEDPARSER_DEPRECATED
#endif

#ifndef FEEDPARSER_DEPRECATED_NO_EXPORT
#  define FEEDPARSER_DEPRECATED_NO_EXPORT FEEDPARSER_NO_EXPORT FEEDPARSER_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define FEEDPARSER_NO_DEPRECATED
#endif

#endif
