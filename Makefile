# soap - simple xdg-open replacement with fallback

include config.mk

SRC = soap.c
OBJ = ${SRC:.c=.o}
PREFIX ?= ${HOME}

all: options soap

options:
	@echo soap build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo "PREFIX   = ${PREFIX}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

soap: ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f soap ${OBJ}

install: all
	@install -Dm 755 soap ${PREFIX}/bin/soap
	@ln -s soap ${PREFIX}/bin/xdg-open
	@echo remember to rename original xdg-open to xdg-open_ if you have it

uninstall:
	@rm ${PREFIX}/bin/soap
	@rm ${PREFIX}/bin/xdg-open
