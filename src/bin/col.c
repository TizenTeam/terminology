#include "private.h"
#include "col.h"
#include <Edje.h>

typedef struct _Color Color;

struct _Color
{
   unsigned char r, g, b, a;
};


static const Color colors[2][2][12] =
{
   { // normal
        { // normal
             { 0xaa, 0xaa, 0xaa, 0xff }, // COL_DEF
             { 0x00, 0x00, 0x00, 0xff }, // COL_BLACK
             { 0xc0, 0x00, 0x00, 0xff }, // COL_RED
             { 0x00, 0xc0, 0x00, 0xff }, // COL_GREEN
             { 0xc0, 0xc0, 0x00, 0xff }, // COL_YELLOW
             { 0x00, 0x00, 0xc0, 0xff }, // COL_BLUE
             { 0xc0, 0x00, 0xc0, 0xff }, // COL_MAGENTA
             { 0x00, 0xc0, 0xc0, 0xff }, // COL_CYAN
             { 0xc0, 0xc0, 0xc0, 0xff }, // COL_WHITE
             { 0x00, 0x00, 0x00, 0x00 }, // COL_INVIS
             { 0x22, 0x22, 0x22, 0xff }, // COL_INVERSE
             { 0xaa, 0xaa, 0xaa, 0xff }, // COL_INVERSEBG
        },
        { // bright/bold
             { 0xee, 0xee, 0xee, 0xff }, // COL_DEF
             { 0xcc, 0xcc, 0xcc, 0xff }, // COL_BLACK
             { 0xcc, 0x88, 0x88, 0xff }, // COL_RED
             { 0x88, 0xcc, 0x88, 0xff }, // COL_GREEN
             { 0xcc, 0xaa, 0x88, 0xff }, // COL_YELLOW
             { 0x88, 0x88, 0xcc, 0xff }, // COL_BLUE
             { 0xcc, 0x88, 0xcc, 0xff }, // COL_MAGENTA
             { 0x88, 0xcc, 0xcc, 0xff }, // COL_CYAN
             { 0xcc, 0xcc, 0xcc, 0xff }, // COL_WHITE
             { 0x00, 0x00, 0x00, 0x00 }, // COL_INVIS
             { 0x11, 0x11, 0x11, 0xff }, // COL_INVERSE
             { 0xee, 0xee, 0xee, 0xff }, // COL_INVERSEBG
        },
   },
   { // intense
        { // normal
             { 0xdd, 0xdd, 0xdd, 0xff }, // COL_DEF
             { 0x80, 0x80, 0x80, 0xff }, // COL_BLACK
             { 0xff, 0x80, 0x80, 0xff }, // COL_RED
             { 0x80, 0xff, 0x80, 0xff }, // COL_GREEN
             { 0xff, 0xff, 0x80, 0xff }, // COL_YELLOW
             { 0x80, 0x80, 0xff, 0xff }, // COL_BLUE
             { 0xff, 0x80, 0xff, 0xff }, // COL_MAGENTA
             { 0x80, 0xff, 0xff, 0xff }, // COL_CYAN
             { 0xff, 0xff, 0xff, 0xff }, // COL_WHITE
             { 0x00, 0x00, 0x00, 0x00 }, // COL_INVIS
             { 0x11, 0x11, 0x11, 0xff }, // COL_INVERSE
             { 0xcc, 0xcc, 0xcc, 0xff }, // COL_INVERSEBG
        },
        { // bright/bold
             { 0xff, 0xff, 0xff, 0xff }, // COL_DEF
             { 0xcc, 0xcc, 0xcc, 0xff }, // COL_BLACK
             { 0xff, 0xcc, 0xcc, 0xff }, // COL_RED
             { 0xcc, 0xff, 0xcc, 0xff }, // COL_GREEN
             { 0xff, 0xff, 0xcc, 0xff }, // COL_YELLOW
             { 0xcc, 0xcc, 0xff, 0xff }, // COL_BLUE
             { 0xff, 0xcc, 0xff, 0xff }, // COL_MAGENTA
             { 0xcc, 0xff, 0xff, 0xff }, // COL_CYAN
             { 0xff, 0xff, 0xff, 0xff }, // COL_WHITE
             { 0x00, 0x00, 0x00, 0x00 }, // COL_INVIS
             { 0x00, 0x00, 0x00, 0xff }, // COL_INVERSE
             { 0xff, 0xff, 0xff, 0xff }, // COL_INVERSEBG
        }
   }
};

static const Color colors256[256] =
{
   // basic 16 repeated
   { 0x00, 0x00, 0x00, 0xff }, // COL_BLACK
   { 0xc0, 0x00, 0x00, 0xff }, // COL_RED
   { 0x00, 0xc0, 0x00, 0xff }, // COL_GREEN
   { 0xc0, 0xc0, 0x00, 0xff }, // COL_YELLOW
   { 0x00, 0x00, 0xc0, 0xff }, // COL_BLUE
   { 0xc0, 0x00, 0xc0, 0xff }, // COL_MAGENTA
   { 0x00, 0xc0, 0xc0, 0xff }, // COL_CYAN
   { 0xc0, 0xc0, 0xc0, 0xff }, // COL_WHITE
   
   { 0x80, 0x80, 0x80, 0xff }, // COL_BLACK
   { 0xff, 0x80, 0x80, 0xff }, // COL_RED
   { 0x80, 0xff, 0x80, 0xff }, // COL_GREEN
   { 0xff, 0xff, 0x80, 0xff }, // COL_YELLOW
   { 0x80, 0x80, 0xff, 0xff }, // COL_BLUE
   { 0xff, 0x80, 0xff, 0xff }, // COL_MAGENTA
   { 0x80, 0xff, 0xff, 0xff }, // COL_CYAN
   { 0xff, 0xff, 0xff, 0xff }, // COL_WHITE

   // pure 6x6x6 colorcube
   { 0x00, 0x00, 0x00, 0xff },
   { 0x00, 0x00, 0x2a, 0xff },
   { 0x00, 0x00, 0x55, 0xff },
   { 0x00, 0x00, 0x7f, 0xff },
   { 0x00, 0x00, 0xaa, 0xff },
   { 0x00, 0x00, 0xd4, 0xff },

   { 0x00, 0x2a, 0x00, 0xff },
   { 0x00, 0x2a, 0x2a, 0xff },
   { 0x00, 0x2a, 0x55, 0xff },
   { 0x00, 0x2a, 0x7f, 0xff },
   { 0x00, 0x2a, 0xaa, 0xff },
   { 0x00, 0x2a, 0xd4, 0xff },

   { 0x00, 0x55, 0x00, 0xff },
   { 0x00, 0x55, 0x2a, 0xff },
   { 0x00, 0x55, 0x55, 0xff },
   { 0x00, 0x55, 0x7f, 0xff },
   { 0x00, 0x55, 0xaa, 0xff },
   { 0x00, 0x55, 0xd4, 0xff },

   { 0x00, 0x7f, 0x00, 0xff },
   { 0x00, 0x7f, 0x2a, 0xff },
   { 0x00, 0x7f, 0x55, 0xff },
   { 0x00, 0x7f, 0x7f, 0xff },
   { 0x00, 0x7f, 0xaa, 0xff },
   { 0x00, 0x7f, 0xd4, 0xff },

   { 0x00, 0xaa, 0x00, 0xff },
   { 0x00, 0xaa, 0x2a, 0xff },
   { 0x00, 0xaa, 0x55, 0xff },
   { 0x00, 0xaa, 0x7f, 0xff },
   { 0x00, 0xaa, 0xaa, 0xff },
   { 0x00, 0xaa, 0xd4, 0xff },

   { 0x00, 0xd4, 0x00, 0xff },
   { 0x00, 0xd4, 0x2a, 0xff },
   { 0x00, 0xd4, 0x55, 0xff },
   { 0x00, 0xd4, 0x7f, 0xff },
   { 0x00, 0xd4, 0xaa, 0xff },
   { 0x00, 0xd4, 0xd4, 0xff },

   { 0x2a, 0x00, 0x00, 0xff },
   { 0x2a, 0x00, 0x2a, 0xff },
   { 0x2a, 0x00, 0x55, 0xff },
   { 0x2a, 0x00, 0x7f, 0xff },
   { 0x2a, 0x00, 0xaa, 0xff },
   { 0x2a, 0x00, 0xd4, 0xff },

   { 0x2a, 0x2a, 0x00, 0xff },
   { 0x2a, 0x2a, 0x2a, 0xff },
   { 0x2a, 0x2a, 0x55, 0xff },
   { 0x2a, 0x2a, 0x7f, 0xff },
   { 0x2a, 0x2a, 0xaa, 0xff },
   { 0x2a, 0x2a, 0xd4, 0xff },

   { 0x2a, 0x55, 0x00, 0xff },
   { 0x2a, 0x55, 0x2a, 0xff },
   { 0x2a, 0x55, 0x55, 0xff },
   { 0x2a, 0x55, 0x7f, 0xff },
   { 0x2a, 0x55, 0xaa, 0xff },
   { 0x2a, 0x55, 0xd4, 0xff },

   { 0x2a, 0x7f, 0x00, 0xff },
   { 0x2a, 0x7f, 0x2a, 0xff },
   { 0x2a, 0x7f, 0x55, 0xff },
   { 0x2a, 0x7f, 0x7f, 0xff },
   { 0x2a, 0x7f, 0xaa, 0xff },
   { 0x2a, 0x7f, 0xd4, 0xff },

   { 0x2a, 0xaa, 0x00, 0xff },
   { 0x2a, 0xaa, 0x2a, 0xff },
   { 0x2a, 0xaa, 0x55, 0xff },
   { 0x2a, 0xaa, 0x7f, 0xff },
   { 0x2a, 0xaa, 0xaa, 0xff },
   { 0x2a, 0xaa, 0xd4, 0xff },

   { 0x2a, 0xd4, 0x00, 0xff },
   { 0x2a, 0xd4, 0x2a, 0xff },
   { 0x2a, 0xd4, 0x55, 0xff },
   { 0x2a, 0xd4, 0x7f, 0xff },
   { 0x2a, 0xd4, 0xaa, 0xff },
   { 0x2a, 0xd4, 0xd4, 0xff },

   { 0x55, 0x00, 0x00, 0xff },
   { 0x55, 0x00, 0x2a, 0xff },
   { 0x55, 0x00, 0x55, 0xff },
   { 0x55, 0x00, 0x7f, 0xff },
   { 0x55, 0x00, 0xaa, 0xff },
   { 0x55, 0x00, 0xd4, 0xff },

   { 0x55, 0x2a, 0x00, 0xff },
   { 0x55, 0x2a, 0x2a, 0xff },
   { 0x55, 0x2a, 0x55, 0xff },
   { 0x55, 0x2a, 0x7f, 0xff },
   { 0x55, 0x2a, 0xaa, 0xff },
   { 0x55, 0x2a, 0xd4, 0xff },

   { 0x55, 0x55, 0x00, 0xff },
   { 0x55, 0x55, 0x2a, 0xff },
   { 0x55, 0x55, 0x55, 0xff },
   { 0x55, 0x55, 0x7f, 0xff },
   { 0x55, 0x55, 0xaa, 0xff },
   { 0x55, 0x55, 0xd4, 0xff },

   { 0x55, 0x7f, 0x00, 0xff },
   { 0x55, 0x7f, 0x2a, 0xff },
   { 0x55, 0x7f, 0x55, 0xff },
   { 0x55, 0x7f, 0x7f, 0xff },
   { 0x55, 0x7f, 0xaa, 0xff },
   { 0x55, 0x7f, 0xd4, 0xff },

   { 0x55, 0xaa, 0x00, 0xff },
   { 0x55, 0xaa, 0x2a, 0xff },
   { 0x55, 0xaa, 0x55, 0xff },
   { 0x55, 0xaa, 0x7f, 0xff },
   { 0x55, 0xaa, 0xaa, 0xff },
   { 0x55, 0xaa, 0xd4, 0xff },

   { 0x55, 0xd4, 0x00, 0xff },
   { 0x55, 0xd4, 0x2a, 0xff },
   { 0x55, 0xd4, 0x55, 0xff },
   { 0x55, 0xd4, 0x7f, 0xff },
   { 0x55, 0xd4, 0xaa, 0xff },
   { 0x55, 0xd4, 0xd4, 0xff },

   { 0x7f, 0x00, 0x00, 0xff },
   { 0x7f, 0x00, 0x2a, 0xff },
   { 0x7f, 0x00, 0x55, 0xff },
   { 0x7f, 0x00, 0x7f, 0xff },
   { 0x7f, 0x00, 0xaa, 0xff },
   { 0x7f, 0x00, 0xd4, 0xff },

   { 0x7f, 0x2a, 0x00, 0xff },
   { 0x7f, 0x2a, 0x2a, 0xff },
   { 0x7f, 0x2a, 0x55, 0xff },
   { 0x7f, 0x2a, 0x7f, 0xff },
   { 0x7f, 0x2a, 0xaa, 0xff },
   { 0x7f, 0x2a, 0xd4, 0xff },

   { 0x7f, 0x55, 0x00, 0xff },
   { 0x7f, 0x55, 0x2a, 0xff },
   { 0x7f, 0x55, 0x55, 0xff },
   { 0x7f, 0x55, 0x7f, 0xff },
   { 0x7f, 0x55, 0xaa, 0xff },
   { 0x7f, 0x55, 0xd4, 0xff },

   { 0x7f, 0x7f, 0x00, 0xff },
   { 0x7f, 0x7f, 0x2a, 0xff },
   { 0x7f, 0x7f, 0x55, 0xff },
   { 0x7f, 0x7f, 0x7f, 0xff },
   { 0x7f, 0x7f, 0xaa, 0xff },
   { 0x7f, 0x7f, 0xd4, 0xff },

   { 0x7f, 0xaa, 0x00, 0xff },
   { 0x7f, 0xaa, 0x2a, 0xff },
   { 0x7f, 0xaa, 0x55, 0xff },
   { 0x7f, 0xaa, 0x7f, 0xff },
   { 0x7f, 0xaa, 0xaa, 0xff },
   { 0x7f, 0xaa, 0xd4, 0xff },

   { 0x7f, 0xd4, 0x00, 0xff },
   { 0x7f, 0xd4, 0x2a, 0xff },
   { 0x7f, 0xd4, 0x55, 0xff },
   { 0x7f, 0xd4, 0x7f, 0xff },
   { 0x7f, 0xd4, 0xaa, 0xff },
   { 0x7f, 0xd4, 0xd4, 0xff },

   { 0xaa, 0x00, 0x00, 0xff },
   { 0xaa, 0x00, 0x2a, 0xff },
   { 0xaa, 0x00, 0x55, 0xff },
   { 0xaa, 0x00, 0x7f, 0xff },
   { 0xaa, 0x00, 0xaa, 0xff },
   { 0xaa, 0x00, 0xd4, 0xff },

   { 0xaa, 0x2a, 0x00, 0xff },
   { 0xaa, 0x2a, 0x2a, 0xff },
   { 0xaa, 0x2a, 0x55, 0xff },
   { 0xaa, 0x2a, 0x7f, 0xff },
   { 0xaa, 0x2a, 0xaa, 0xff },
   { 0xaa, 0x2a, 0xd4, 0xff },

   { 0xaa, 0x55, 0x00, 0xff },
   { 0xaa, 0x55, 0x2a, 0xff },
   { 0xaa, 0x55, 0x55, 0xff },
   { 0xaa, 0x55, 0x7f, 0xff },
   { 0xaa, 0x55, 0xaa, 0xff },
   { 0xaa, 0x55, 0xd4, 0xff },

   { 0xaa, 0x7f, 0x00, 0xff },
   { 0xaa, 0x7f, 0x2a, 0xff },
   { 0xaa, 0x7f, 0x55, 0xff },
   { 0xaa, 0x7f, 0x7f, 0xff },
   { 0xaa, 0x7f, 0xaa, 0xff },
   { 0xaa, 0x7f, 0xd4, 0xff },

   { 0xaa, 0xaa, 0x00, 0xff },
   { 0xaa, 0xaa, 0x2a, 0xff },
   { 0xaa, 0xaa, 0x55, 0xff },
   { 0xaa, 0xaa, 0x7f, 0xff },
   { 0xaa, 0xaa, 0xaa, 0xff },
   { 0xaa, 0xaa, 0xd4, 0xff },

   { 0xaa, 0xd4, 0x00, 0xff },
   { 0xaa, 0xd4, 0x2a, 0xff },
   { 0xaa, 0xd4, 0x55, 0xff },
   { 0xaa, 0xd4, 0x7f, 0xff },
   { 0xaa, 0xd4, 0xaa, 0xff },
   { 0xaa, 0xd4, 0xd4, 0xff },


   { 0xd4, 0x00, 0x00, 0xff },
   { 0xd4, 0x00, 0x2a, 0xff },
   { 0xd4, 0x00, 0x55, 0xff },
   { 0xd4, 0x00, 0x7f, 0xff },
   { 0xd4, 0x00, 0xaa, 0xff },
   { 0xd4, 0x00, 0xd4, 0xff },

   { 0xd4, 0x2a, 0x00, 0xff },
   { 0xd4, 0x2a, 0x2a, 0xff },
   { 0xd4, 0x2a, 0x55, 0xff },
   { 0xd4, 0x2a, 0x7f, 0xff },
   { 0xd4, 0x2a, 0xaa, 0xff },
   { 0xd4, 0x2a, 0xd4, 0xff },

   { 0xd4, 0x55, 0x00, 0xff },
   { 0xd4, 0x55, 0x2a, 0xff },
   { 0xd4, 0x55, 0x55, 0xff },
   { 0xd4, 0x55, 0x7f, 0xff },
   { 0xd4, 0x55, 0xaa, 0xff },
   { 0xd4, 0x55, 0xd4, 0xff },

   { 0xd4, 0x7f, 0x00, 0xff },
   { 0xd4, 0x7f, 0x2a, 0xff },
   { 0xd4, 0x7f, 0x55, 0xff },
   { 0xd4, 0x7f, 0x7f, 0xff },
   { 0xd4, 0x7f, 0xaa, 0xff },
   { 0xd4, 0x7f, 0xd4, 0xff },

   { 0xd4, 0xaa, 0x00, 0xff },
   { 0xd4, 0xaa, 0x2a, 0xff },
   { 0xd4, 0xaa, 0x55, 0xff },
   { 0xd4, 0xaa, 0x7f, 0xff },
   { 0xd4, 0xaa, 0xaa, 0xff },
   { 0xd4, 0xaa, 0xd4, 0xff },

   { 0xd4, 0xd4, 0x00, 0xff },
   { 0xd4, 0xd4, 0x2a, 0xff },
   { 0xd4, 0xd4, 0x55, 0xff },
   { 0xd4, 0xd4, 0x7f, 0xff },
   { 0xd4, 0xd4, 0xaa, 0xff },
   { 0xd4, 0xd4, 0xd4, 0xff },

   // greyscale ramp (24 not including black and white, so 26 if included)
   { 0x08, 0x08, 0x08, 0xff },
   { 0x12, 0x12, 0x12, 0xff },
   { 0x1c, 0x1c, 0x1c, 0xff },
   { 0x26, 0x26, 0x26, 0xff },
   { 0x30, 0x30, 0x30, 0xff },
   { 0x3a, 0x3a, 0x3a, 0xff },
   { 0x44, 0x44, 0x44, 0xff },
   { 0x4e, 0x4e, 0x4e, 0xff },
   { 0x58, 0x58, 0x58, 0xff },
   { 0x62, 0x62, 0x62, 0xff },
   { 0x6c, 0x6c, 0x6c, 0xff },
   { 0x76, 0x76, 0x76, 0xff },
   { 0x80, 0x80, 0x80, 0xff },
   { 0x8a, 0x8a, 0x8a, 0xff },
   { 0x94, 0x94, 0x94, 0xff },
   { 0x9e, 0x9e, 0x9e, 0xff },
   { 0xa8, 0xa8, 0xa8, 0xff },
   { 0xb2, 0xb2, 0xb2, 0xff },
   { 0xbc, 0xbc, 0xbc, 0xff },
   { 0xc6, 0xc6, 0xc6, 0xff },
   { 0xd0, 0xd0, 0xd0, 0xff },
   { 0xda, 0xda, 0xda, 0xff },
   { 0xe4, 0xe4, 0xe4, 0xff },
   { 0xee, 0xee, 0xee, 0xff },
};

void
colors_term_init(Evas_Object *textgrid, Evas_Object *bg)
{
   int c, n;
   int r, g, b, a;
   char buf[32];

   for (c = 0; c < 4 * 12; c++)
     {
        snprintf(buf, sizeof(buf) - 1, "color-%d", c);

        n = c + 24 * ( c / 24);

        if (edje_object_color_class_get(bg, buf,
                                        &r, &g, &b, &a,
                                        NULL, NULL, NULL, NULL,
                                        NULL, NULL, NULL, NULL))
          {
             /* normal */
             evas_object_textgrid_palette_set(
                 textgrid, EVAS_TEXTGRID_PALETTE_STANDARD, n,
                 r, g, b, a);
             /* faint */
             evas_object_textgrid_palette_set(
                 textgrid, EVAS_TEXTGRID_PALETTE_STANDARD, n + 24,
                 r/2, g/2, b/2, a/2);
          }
        else
          {
             Color color = colors[c/24][(c%24)/12][c%12];

             /* normal */
             evas_object_textgrid_palette_set(
                 textgrid, EVAS_TEXTGRID_PALETTE_STANDARD, n,
                 color.r, color.g, color.b, color.a);
             /* faint */
             evas_object_textgrid_palette_set(
                 textgrid, EVAS_TEXTGRID_PALETTE_STANDARD, n + 24,
                 color.r/2, color.g/2, color.b/2, color.a/2);
          }
     }
   for (c = 0; c < 256; c++)
     {
        snprintf(buf, sizeof(buf) - 1, "256color-%d", c);

        if (edje_object_color_class_get(bg, buf,
                                        &r, &g, &b, &a,
                                        NULL, NULL, NULL, NULL,
                                        NULL, NULL, NULL, NULL))
          {
             evas_object_textgrid_palette_set(
                 textgrid, EVAS_TEXTGRID_PALETTE_EXTENDED, c,
                 r, g, b, a);
          }
        else
          {
             Color color = colors256[c];

             evas_object_textgrid_palette_set(
                 textgrid, EVAS_TEXTGRID_PALETTE_EXTENDED, c,
                 color.r, color.g, color.b, color.a);
          }
     }
}
