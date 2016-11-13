#ifndef _GRAVATAR_H__
#define _GRAVATAR_H__ 1

#include "config.h"

void
gravatar_tooltip(Evas_Object *obj, Config *config, char *email);

void gravatar_init(void);

#ifdef __TIZEN__
static inline void gravatar_shutdown(void) {}
#else
void gravatar_shutdown(void);
#endif

#endif
