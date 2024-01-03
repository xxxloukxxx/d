/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 2; /* border pixel of windows */
static const unsigned int snap = 32;	/* snap pixel */
static const int showbar = 1;			/* 0 means no bar */
static const int topbar = 0;			/* 0 means bottom bar */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const char *fonts[] = {"agave:size=14"};
static const char dmenufont[] = "agave:size=14";
static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#005577";
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_cyan, "#ff0000"},
};

/* tagging */
static const char *tags[] = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"discord", NULL, NULL, 1 << 8, 0, -1},
    {"Jellyfin Media Player", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.65; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;		 /* number of clients in master area */
static const int resizehints = 1;	 /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                  \
	{MODKEY, KEY, view, {.ui = 1 << TAG}}, \
	{MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}}, //\
//	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
//	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                           \
	{                                                        \
		.v = (const char *[]) { "/bin/sh", "-c", cmd, NULL } \
	}

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL};
static const char *termcmd[] = {"st", NULL};
static const char *shutdowncmd[] = {"/home/cedric/.dwm/powermenu.sh", NULL};
static const char *pavucmd[] = {"pavucontrol", NULL};
static const char *flamecmd[] = {"flameshot", "gui", NULL};

static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

/*
Volume by multimedia keys
*/
#include <X11/XF86keysym.h>
static const char *upvol[] = {"/usr/bin/pactl", "set-sink-volume", "0", "+5%", NULL};
static const char *downvol[] = {"/usr/bin/pactl", "set-sink-volume", "0", "-5%", NULL};
static const char *mutevol[] = {"/usr/bin/pactl", "set-sink-mute", "0", "toggle", NULL};

/*
Binding keys
*/
static const Key keys[] = {
    /* modifier             key     function        argument */
    {0, 121, spawn, {.v = mutevol}},								   // 121
    {0, 122, spawn, {.v = downvol}},								   // 122
    {0, 123, spawn, {.v = upvol}},									   // 123
//	{MODKEY, 33, spawn, {.v = dmenucmd}},							   // p
    {MODKEY, 40, spawn, {.v = dmenucmd}},							   // d
    {MODKEY, 36, spawn, {.v = termcmd}},				               // Return
    {MODKEY | ControlMask | ShiftMask, 22, spawn, {.v = shutdowncmd}}, // BS
    {MODKEY | ControlMask | ShiftMask, 33, spawn, {.v = pavucmd}},	   // p
    {MODKEY | ControlMask | ShiftMask, 39, spawn, {.v = flamecmd}},	   // s
    {MODKEY, 9, togglescratch, {.v = scratchpadcmd }},                 // Esc
    {MODKEY, 56, togglebar, {0}},									   // b
    {MODKEY, 44, focusstack, {.i = +1}},							   // j
    {MODKEY, 45, focusstack, {.i = -1}},							   // k
    {MODKEY, 113, focusstack, {.i = +1}},							   // j
    {MODKEY, 114, focusstack, {.i = -1}},							   // k
    {MODKEY, 55, incnmaster, {.i = +1}},							   // v
//	{ MODKEY,               40,     incnmaster,     {.i = -1 } },      // d
    {MODKEY, 43, setmfact, {.f = -0.05}},							   // h
    {MODKEY, 46, setmfact, {.f = +0.05}},							   // l
    {MODKEY | ShiftMask, 36, zoom, {0}},							   // Return
    {MODKEY, 23, view, {0}},										   // Tab
    {MODKEY | ShiftMask, 54, killclient, {0}},						   // c
    {MODKEY | ShiftMask, 41, setlayout, {.v = &layouts[1]}},		   // f
    {MODKEY | ShiftMask, 56, setlayout, {.v = &layouts[1]}},		   // b
    {MODKEY | ShiftMask, 57, setlayout, {.v = &layouts[0]}},		   // n
    {MODKEY | ShiftMask, 58, setlayout, {.v = &layouts[2]}},		   // m
    {MODKEY, 65, setlayout, {0}},									   // space
    {MODKEY | ShiftMask, 65, togglefloating, {0}},					   // space
//	{ MODKEY,               19,     view,           {.ui = ~0 } },     // 0
//	{ MODKEY|ShiftMask,     19,     tag,            {.ui = ~0 } },     // 0
    {MODKEY, 59, focusmon, {.i = -1}},								   // comma
    {MODKEY, 60, focusmon, {.i = +1}},								   // period
    {MODKEY | ShiftMask, 59, tagmon, {.i = -1}},					   // comma
    {MODKEY | ShiftMask, 60, tagmon, {.i = +1}},					   // period
    TAGKEYS(24, 0)													   // q
    TAGKEYS(25, 1)													   // w
    TAGKEYS(26, 2)													   // e
    TAGKEYS(27, 3)													   // r
    TAGKEYS(28, 4)													   // t
    TAGKEYS(29, 5)													   // y
    TAGKEYS(30, 6)													   // u
    TAGKEYS(31, 7)													   // i
    TAGKEYS(32, 8)													   // o
    //	{ MODKEY|ShiftMask,     24,     quit,           {0} },          // q
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
//	{ClkLtSymbol, 0, Button1, setlayout, {0}},
//	{ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
