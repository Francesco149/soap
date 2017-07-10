/* See LICENSE file for copyright and license details. */

#define PREHTTP "^(http://|https://)(www[.])?"

static const Pair pairs[] =
{
	/* { regex, action } */

	{ "[.](jpg|jpeg|png|tiff|pdf|cbz)$", "mupdf-x11 %s" },
	{ "[.](mp3|ogg|wav|flac|aac)$", "mpv --keep-open %s" },
	{ "[.](mp4|mkv|avi|mov)$", "mpv --keep-open %s" },

	{
		PREHTTP ".*[.]gif$",

		"tmpfile=$(mktemp -u).gif && "
		"wget -O $tmpfile %s && "
		"mpv -loop $tmpfile && "
		"rm $tmpfile"
	},

	{ "[.]gif$", "mpv -loop %s" },

	{
		PREHTTP "(youtube.com/watch[?]|youtu[.]be/)",
		"mpv --keep-open %s"
	},

	{ PREHTTP ".*", "firefox %s" },
};
