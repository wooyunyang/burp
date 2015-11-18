#ifndef _BUILDERS_H
#define _BUILDERS_H

#include "../../src/conf.h"
#include "server/build_storage_dirs.h"
#include "server/protocol2/champ_chooser/build_dindex.h"

#define RMANIFEST_RELATIVE	"rmanifest_relative"
#define CLIENTCONFDIR		"clientconfdir"

extern char **build_paths(int wanted);
extern struct sbuf *build_attribs(enum protocol protocol);
extern struct sbuf *build_attribs_reduce(enum protocol protocol);
extern struct slist *build_manifest(const char *path,
        enum protocol protocol, int entries, int phase);

extern struct blist *build_blist(int wanted);
extern void build_blks(struct blist *blist, int wanted);


extern void build_manifest_phase2_from_slist(const char *path,
	struct slist *slist, enum protocol protocol, int short_write);
extern void build_manifest_phase1_from_slist(const char *path,
	struct slist *slist, enum protocol protocol);

extern char *get_clientconfdir_path(const char *file);
extern void build_clientconfdir_file(const char *file, const char *content);
extern void delete_clientconfdir_file(const char *file);
extern void build_clientconfdir_files(const char *cnames[]);
extern void assert_cstat_list(struct cstat *clist, const char *cnames[]);

#endif
