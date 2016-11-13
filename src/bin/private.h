#ifndef _PRIVATE_H__
#define _PRIVATE_H__ 1

#ifdef HAVE_CONFIG_H
#include "terminology_config.h"
#endif

#if HAVE_GETTEXT && ENABLE_NLS
#define _(string) gettext (string)
#else
#define _(string) (string)
#endif
#define gettext_noop(String) String

extern int _log_domain;

#ifdef __TIZEN__
#include <dlog.h>

#ifndef PACKAGE_NAME
#define PACKAGE_NAME "terminology"
#endif

#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "0.9"
#endif

#define CRITICAL(...) dlog_print(DLOG_FATAL, PACKAGE_NAME, __VA_ARGS__)
#define ERR(...)      dlog_print(DLOG_ERROR, PACKAGE_NAME, __VA_ARGS__)
#define WRN(...)      dlog_print(DLOG_WARN,  PACKAGE_NAME, __VA_ARGS__)
#define INF(...)      dlog_print(DLOG_INFO,  PACKAGE_NAME, __VA_ARGS__)
#define DBG(...)      dlog_print(DLOG_DEBUG, PACKAGE_NAME, __VA_ARGS__)
#else
#define CRITICAL(...) EINA_LOG_DOM_CRIT(_log_domain, __VA_ARGS__)
#define ERR(...)      EINA_LOG_DOM_ERR(_log_domain, __VA_ARGS__)
#define WRN(...)      EINA_LOG_DOM_WARN(_log_domain, __VA_ARGS__)
#define INF(...)      EINA_LOG_DOM_INFO(_log_domain, __VA_ARGS__)
#define DBG(...)      EINA_LOG_DOM_DBG(_log_domain, __VA_ARGS__)
#endif

#ifndef MIN
# define MIN(x, y) (((x) > (y)) ? (y) : (x))
#endif
#ifndef MAX
# define MAX(x, y) (((x) > (y)) ? (x) : (y))
#endif


#ifdef __TIZEN__
#include "TizenHacks.h"


#define TIZEN_STR_(a) (#a)
#define TIZEN_STR(a) TIZEN_STR_(a)
#endif


#endif
