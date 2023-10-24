/* See LICENSE file for copyright and license details. */

/* {} will be substituted with the actual argument when the rule is executed */
struct rule rules[] = {
	{ .regex = "\\.(avi|mp4|mkv|mp3|ogg|flac|mov)$", .file = "mpv", .argv = { "mpv", "{}", NULL } },
	{ .regex = "\\.(c|cpp|h|py|md|tex|txt)$", .file = "vi", .argv = { "vi", "{}", NULL } },
	{ .regex = "\\.(png|jpg|gif)$", .file = "nsxiv", .argv = { "nsxiv", "{}", NULL} },
	{ .regex = "\\.(html|svg)$", .file = "firefox", .argv = { "firefox", "{}", NULL } },
	{ .regex = "\\.pdf$", .file = "zathura", .argv = { "zathura", "{}", NULL} },
	{ .regex = "\\.sh$", .file = "sh", .argv = { "sh", "{}", NULL} },
	{ .regex = ".", .file = "vi", .argv = { "vi", "{}", NULL } },
};
