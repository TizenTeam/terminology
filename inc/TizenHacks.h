#ifndef _TIZENHACKS_H_
#define _TIZENHACKS_H_ 1

#ifdef __TIZEN__

#include "evas_textgrid.eo.legacy_Hack.h"
#include "E17Hacks.h"
#include "Ecore_File_Hack.h"
#include "Eet_Hack.h"
#include "Eet_Hack.h"
#include "Ecore_File_Hack.h"
#include "evas_textgrid.eo.legacy_Hack.h"
#include "E17Hacks.h"
#include "evas_textgrid.eo.legacy_Hack.h"
#include "Ecore_File_Hack.h"
#include "Ecore_Evas_Hack.h"
extern int posix_openpt (int __oflag) __wur;
extern int grantpt (int __fd) __THROW;
extern char *ptsname (int __fd) __THROW __wur;
extern int unlockpt (int __fd) __THROW;

static inline void elm_need_efreet() {}
static inline void efreet_init() {}
static inline void efreet_shutdown() {}

// struct Eina_list;
//static inline void* ecore_file_ls { return 0; }
static inline void ecore_con_init() {}
static inline void ecore_con_url_init(){}
static inline void ecore_con_url_shutdown() {}
static inline void ecore_con_shutdown() {}

// avaliable:
#if 0
static inline void elm_app_compile_bin_dir_set() {
    DBG("TODO: Main function entry point");
}
static inline void elm_app_compile_lib_dir_set() {}
static inline void elm_app_compile_data_dir_set() {}
#endif
static inline int eina_log_domain_register(char* arg, void * p)
{
    DBG("TODO: Port to tizen");
    return 1;
}

//eina_log_domain_register("terminology", NULL);
//         elm_shutdown();
static inline void eina_log_domain_unregister() {}

#ifndef PACKAGE_NAME
#define PACKAGE_NAME "terminology"
#endif

#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "0.9"
#endif

#define STR_(a) (#a)
#define STR(a) STR_(a)
#endif


#endif

