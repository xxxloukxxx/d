/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 3; /* border pixel of windows */
static const unsigned int snap = 32;	/* snap pixel */
static const int showbar = 1;			/* 0 means no bar */
static const int topbar = 0;			/* 0 means bottom bar */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const char *fonts[] = {"Inconsolata:size=18"};
//static const char *fonts[] = {"Liberation Mono:pixelsize=18:antialias=true:autohint=true"};
static const char dmenufont[] = "Inconsolata:size=18";
//static const char dmenufont[] = "Liberation Mono:pixelsize=18:antialias=true:autohint=true";
//static const char col_gray1[] = "#222222";
static const char col_gray1[] = "#000000";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#002244";
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_cyan, "#770000"},
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
//    {"Jellyfin Media Player", NULL, NULL, 1 << 7, 0, -1},
};

/* layout(s) */
static const float mfact = 0.618; /* factor of master area size [0.05..0.95] */
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
static const char *shutdowncmd[] = {"powermenu.sh", NULL};
static const char *pavucmd[] = {"pavucontrol", NULL};
static const char *flamecmd[] = {"flameshot", "gui", NULL};
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x40", NULL };

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
    {0, 121, spawn, {.v = mutevol}},								   // 121 - Mute
    {0, 122, spawn, {.v = downvol}},								   // 122 - Voldn
    {0, 123, spawn, {.v = upvol}},									   // 123 - Volup
//    {0, 191, spawn, {.v = dmenucmd}},							       // F13
//    {0, 192, spawn, {.v = termcmd}},				                   // F14
    {MODKEY, 33, spawn, {.v = dmenucmd}},							   // Meta + p
//    {MODKEY, 40, spawn, {.v = dmenucmd}},							   // Meta + d
    {MODKEY | ShiftMask , 36, spawn, {.v = termcmd}},	               // Meta + Shift + Return
//    {MODKEY, 36, spawn, {.v = termcmd}},				               // Meta + Return
    {MODKEY | ControlMask | ShiftMask, 22, spawn, {.v = shutdowncmd}}, // Meta + Ctrl + Shift + BS
    {MODKEY | ControlMask | ShiftMask, 33, spawn, {.v = pavucmd}},	   // Meta + Ctrl + Shift + p
    {MODKEY | ControlMask | ShiftMask, 39, spawn, {.v = flamecmd}},	   // Meta + Ctrl + Shift + s
    {MODKEY, 9, togglescratch, {.v = scratchpadcmd }},                 // Meta + Esc
//    {MODKEY, 44, focusstack, {.i = +1}},							   // Meta + j
//    {MODKEY, 45, focusstack, {.i = -1}},							   // Meta + k
    {MODKEY, 113, focusstack, {.i = -1}},							   // Meta + Left
    {MODKEY, 114, focusstack, {.i = +1}},							   // Meta + Right
    {MODKEY, 43, setmfact, {.f = -0.05}},							   // Meta + h
    {MODKEY, 46, setmfact, {.f = +0.05}},							   // Meta + l
    {MODKEY, 36, zoom, {0}},										   // Meta + Return
//    {MODKEY | ShiftMask, 36, zoom, {0}},							   // Meta + Shift + Return
    {MODKEY, 23, view, {0}},										   // Meta + Tab
    {MODKEY | ShiftMask, 54, killclient, {0}},						   // Meta + Shift + c
    {MODKEY, 65, setlayout, {0}},									   // Meta + Space
    {MODKEY | ShiftMask, 57, setlayout, {.v = &layouts[0]}},		   // Meta + Shift + n
    {MODKEY | ShiftMask, 56, setlayout, {.v = &layouts[1]}},		   // Meta + Shift + b
    {MODKEY | ShiftMask, 58, setlayout, {.v = &layouts[2]}},		   // Meta + Shift + m
    {MODKEY | ShiftMask, 65, togglefloating, {0}},					   // Meta + Shift + Space
    {MODKEY, 59, focusmon, {.i = -1}},								   // Meta + comma
    {MODKEY, 60, focusmon, {.i = +1}},								   // Meta + period
    {MODKEY | ShiftMask, 59, tagmon, {.i = -1}},					   // Meta + Shift + comma
    {MODKEY | ShiftMask, 60, tagmon, {.i = +1}},					   // Meta + Shift + period
    TAGKEYS(24, 0)													   // Meta (+ Shift) + q
    TAGKEYS(25, 1)													   // Meta (+ Shift) + w
    TAGKEYS(26, 2)													   // Meta (+ Shift) + e
    TAGKEYS(27, 3)													   // Meta (+ Shift) + r
    TAGKEYS(28, 4)													   // Meta (+ Shift) + t
    TAGKEYS(29, 5)													   // Meta (+ Shift) + y
    TAGKEYS(30, 6)													   // Meta (+ Shift) + u
    TAGKEYS(31, 7)													   // Meta (+ Shift) + i
    TAGKEYS(32, 8)													   // Meta (+ Shift) + o
//    TAGKEYS(33, 9)													   // Meta (+ Shift) + p
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
