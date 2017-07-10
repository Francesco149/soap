/* See LICENSE file for copyright and license details. */

#define PREHTTP "^(http://|https://)(www[.])?"

static const Pair pairs[] =
{
	/* { regex, action } */

	{ "[.](jpg|jpeg|png|tiff|pdf|cbz)$", "mupdf-x11 %s" },
	{ "[.](mp3|ogg|wav|flac|aac)$", "mpv --keep-open %s" },
	{ "[.](mp4|mkv|avi|mov)$", "mpv --keep-open %s" },

	/*
		mpv re-downloads the file on every loop so it's best to
		cache them to /tmp/
	*/
#   define TMP_MPV(ext)						\
	{										\
		PREHTTP ".*[.]" ext "$",			\
											\
		"tmpfile=$(mktemp -u)." ext " && "	\
		"wget -O $tmpfile %s && "			\
		"mpv -loop $tmpfile && "			\
		"rm $tmpfile"						\
	},

	TMP_MPV("gif")
	TMP_MPV("webm")

	{ "[.]gif$", "mpv -loop %s" },

	{
		PREHTTP "(youtube.com/watch[?]|youtu[.]be/)",
		"mpv --keep-open %s"
	},

	{ PREHTTP ".*", "firefox %s" },
};
