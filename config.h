/* See LICENSE file for copyright and license details. */
#include </usr/include/X11/XF86keysym.h>
/* colors */
static const char norm_fg[] = "#d8dee9";
static const char norm_bg[] = "#2e3440";
static const char norm_border[] = "#5e81ac";

static const char sel_fg[] = "#5e81ac";
static const char sel_bg[] = "#eceff4";
static const char sel_border[] = "#eceff4";

static const char urg_fg[] = "#5e81ac";
static const char urg_bg[] = "#bf616a";
static const char urg_border[] = "#bf616a";
static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [SchemeUrg] =  { urg_fg,      urg_bg,    urg_border },
};
/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const int gappx              = 10;       /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 1;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrains Mono:size=12", "Symbols Nerd Font:size=14", "JoyPixels:pixelsize=12:antialias=true:autohint=true" };
static const char dmenufont[]       = "JetBrains Mono:size=12";

/* tagging */
static const char *tags[] = { "", "ﭮ", "", "", "", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,     NULL,           0,         0,          0,           0,        -1 },
	{ "discord", NULL,     NULL,           1 << 1,    0,          0,          -1,        -1 },
	{ "firefox", NULL,     NULL,           1 << 2,    0,          0,          -1,        -1 },
	{ "Alacritty",   NULL,     NULL,           0,         0,          1,          0,        -1 },
    { "Alacritty",   NULL,    "ncspot",        1 << 4,     0,           1,         0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         1,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL };
static const char *termcmd[]  = { "alacritty", NULL };

/* launching specific terminals */
static const char *ncspotcmd[] = { "alacritty", "-t", "ncspot", "-e", "fish", "-c", "ncspot" };

/* pulseaudio pactl and xbacklight used for this */
static const char *audiomutecmd[]  = { "pactl", "set-sink-mute", "0", "toggle", NULL };
static const char *audiolowercmd[]  = { "pactl", "set-sink-volume", "0", "-2%", NULL };
static const char *audioraisecmd[]  = { "pactl", "set-sink-volume", "0", "+2%", NULL };
/* playerctl not working right now
static const char *termcmd[]  = { "playerctl", NULL };
static const char *termcmd[]  = { "playerctl", NULL };
static const char *termcmd[]  = { "playerctl", NULL };
*/
/* required a chmod on the backlight brightness file, perform at your own risk */
static const char *brightnessupcmd[]  = { "xbacklight", "-inc", "5", NULL };
static const char *brightnessdowncmd[]  = { "xbacklight", "-dec", "5", NULL };
/* screenshots using flameshot */
static const char *scrotselectcmd[]  = { "flameshot", "gui", NULL };
static const char *scrotscreencmd[]  = { "flameshot", "full", "-c", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ 0,                       XF86XK_AudioMute,		spawn,          {.v = audiomutecmd } },
	{ 0,                       XF86XK_AudioLowerVolume,	spawn,          {.v = audiolowercmd } },
	{ 0,                       XF86XK_AudioRaiseVolume,	spawn,          {.v = audioraisecmd } },
	/* playerctl not working right now
	{ 0,                       XF86XK_AudioPrev,      	spawn,          {.v = dmenucmd } },
	{ 0,                       XF86XK_AudioPlay,     	spawn,          {.v = dmenucmd } },
	{ 0,                       XF86XK_AudioNext,      	spawn,          {.v = dmenucmd } },
	*/
	{ 0,                       XF86XK_MonBrightnessUp,	spawn,          {.v = brightnessupcmd } },
	{ 0,                       XF86XK_MonBrightnessDown,	spawn,          {.v = brightnessdowncmd } },
	{ 0|ShiftMask,			XK_Print,  spawn,          {.v = scrotselectcmd } },
	{ 0,				XK_Print,  spawn,          {.v = scrotscreencmd } },
    { MODKEY|ShiftMask,             XK_m,      spawn,          {.v = ncspotcmd } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_f,      fullscreen,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

