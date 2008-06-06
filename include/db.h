#ifndef _DB_H
#define _DB_H
/* This code generated by make_db_h.   Copyright (c) 2007, 2008 Tokutek */
#ident "Copyright (c) 2007, 2008 Tokutek Inc.  All rights reserved."
#include <sys/types.h>
/*stdio is needed for the FILE* in db->verify*/
#include <stdio.h>
#if defined(__cplusplus)
extern "C" {
#endif
#define TOKUDB 1
#define DB_VERSION_MAJOR 4
#define DB_VERSION_MINOR 4
#define DB_VERSION_PATCH 20
#ifndef _TOKUDB_WRAP_H
#define DB_VERSION_STRING "Tokutek: TokuDB 4.4.20"
#else
#define DB_VERSION_STRING_ydb "Tokutek: TokuDB (wrapped bdb)"
#endif
typedef struct __toku_db_btree_stat DB_BTREE_STAT;
typedef struct __toku_db_env DB_ENV;
typedef struct __toku_db_key_range DB_KEY_RANGE;
typedef struct __toku_db_lsn DB_LSN;
typedef struct __toku_db DB;
typedef struct __toku_db_txn DB_TXN;
typedef struct __toku_db_txn_active DB_TXN_ACTIVE;
typedef struct __toku_db_txn_stat DB_TXN_STAT;
typedef struct __toku_dbc DBC;
typedef struct __toku_dbt DBT;
typedef u_int32_t db_recno_t;
typedef enum {
 DB_BTREE=1,
 DB_UNKNOWN=5
} DBTYPE;
#ifndef _TOKUDB_WRAP_H
#define DB_VERB_DEADLOCK 1
#define DB_VERB_RECOVERY 2
#define DB_VERB_REPLICATION 8
#define DB_VERB_WAITSFOR 16
#define DB_DBT_MALLOC 4
#define DB_DBT_REALLOC 16
#define DB_DBT_USERMEM 32
#define DB_DBT_DUPOK 64
#define DB_ARCH_ABS 1
#define DB_ARCH_LOG 4
#define DB_CREATE 1
#define DB_CXX_NO_EXCEPTIONS 1
#define DB_EXCL 8192
#define DB_PRIVATE 1048576
#define DB_RDONLY 16
#define DB_RECOVER 32
#define DB_THREAD 64
#define DB_TXN_NOSYNC 256
#define DB_LOCK_DEFAULT 1
#define DB_LOCK_OLDEST 7
#define DB_LOCK_RANDOM 8
#define DB_DUP 16384
#define DB_DUPSORT 32768
#define DB_KEYFIRST 15
#define DB_KEYLAST 16
#define DB_NODUPDATA 21
#define DB_NOOVERWRITE 22
#define DB_YESOVERWRITE 254
#define DB_OPFLAGS_MASK 255
#define DB_AUTO_COMMIT 16777216
#define DB_INIT_LOCK 16384
#define DB_INIT_LOG 32768
#define DB_INIT_MPOOL 65536
#define DB_INIT_TXN 262144
#define DB_USE_ENVIRON 2048
#define DB_USE_ENVIRON_ROOT 4096
#define DB_KEYEMPTY -30997
#define DB_KEYEXIST -30996
#define DB_LOCK_DEADLOCK -30995
#define DB_LOCK_NOTGRANTED -30994
#define DB_NOTFOUND -30989
#define DB_SECONDARY_BAD -30973
#define DB_DONOTINDEX -30998
#define DB_BUFFER_SMALL -30999
#define DB_BADFORMAT -30500
#define DB_DELETE_ANY 65536
#define DB_FIRST 9
#define DB_GET_BOTH 10
#define DB_GET_BOTH_RANGE 12
#define DB_LAST 17
#define DB_CURRENT 7
#define DB_NEXT 18
#define DB_NEXT_DUP 19
#define DB_NEXT_NODUP 20
#define DB_PREV 25
#define DB_PREV_NODUP 26
#define DB_SET 28
#define DB_SET_RANGE 30
#define DB_CURRENT_BINDING 253
#define DB_RMW 536870912
#define DB_DBT_APPMALLOC 1
#define DB_LOG_AUTOREMOVE 262144
#define DB_TXN_WRITE_NOSYNC 1024
#define DB_TXN_NOWAIT 8192
#define DB_TXN_SYNC 16384
#endif
/* TOKUDB specific error codes */
#define TOKUDB_OUT_OF_LOCKS -100000
#define TOKUDB_SUCCEEDED_EARLY -100001
/* in wrap mode, top-level function txn_begin is renamed, but the field isn't renamed, so we have to hack it here.*/
#ifdef _TOKUDB_WRAP_H
#undef txn_begin
#endif
struct __toku_db_btree_stat {
  char __toku_dummy0[12];
  u_int32_t bt_nkeys; /* 32-bit offset=12 size=4, 64=bit offset=12 size=4 */
  u_int32_t bt_ndata; /* 32-bit offset=16 size=4, 64=bit offset=16 size=4 */
  char __toku_dummy1[60];  /* Padding at the end */ 
};
struct __toku_db_env {
  struct __toku_db_env_internal *i;
  void* __toku_dummy0[10];
  void *app_private; /* 32-bit offset=44 size=4, 64=bit offset=88 size=8 */
  void* __toku_dummy1[40];
  char __toku_dummy2[128];
  void *api1_internal; /* 32-bit offset=336 size=4, 64=bit offset=544 size=8 */
  void* __toku_dummy3[7];
  int  (*close) (DB_ENV *, u_int32_t); /* 32-bit offset=368 size=4, 64=bit offset=608 size=8 */
  void* __toku_dummy4[2];
  void (*err) (const DB_ENV *, int, const char *, ...); /* 32-bit offset=380 size=4, 64=bit offset=632 size=8 */
  void* __toku_dummy5[3];
  int (*get_cachesize) (DB_ENV *, u_int32_t *, u_int32_t *, int *); /* 32-bit offset=396 size=4, 64=bit offset=664 size=8 */
  void* __toku_dummy6[4];
  int (*get_flags) (DB_ENV *, u_int32_t *); /* 32-bit offset=416 size=4, 64=bit offset=704 size=8 */
  void* __toku_dummy7[4];
  int  (*get_lg_max) (DB_ENV *, u_int32_t*); /* 32-bit offset=436 size=4, 64=bit offset=744 size=8 */
  void* __toku_dummy8[4];
  int  (*get_lk_max_locks) (DB_ENV *, u_int32_t *); /* 32-bit offset=456 size=4, 64=bit offset=784 size=8 */
  void* __toku_dummy9[22];
  int  (*log_archive) (DB_ENV *, char **[], u_int32_t); /* 32-bit offset=548 size=4, 64=bit offset=968 size=8 */
  void* __toku_dummy10[2];
  int  (*log_flush) (DB_ENV *, const DB_LSN *); /* 32-bit offset=560 size=4, 64=bit offset=992 size=8 */
  void* __toku_dummy11[25];
  int  (*open) (DB_ENV *, const char *, u_int32_t, int); /* 32-bit offset=664 size=4, 64=bit offset=1200 size=8 */
  void* __toku_dummy12[12];
  int  (*set_cachesize) (DB_ENV *, u_int32_t, u_int32_t, int); /* 32-bit offset=716 size=4, 64=bit offset=1304 size=8 */
  int  (*set_data_dir) (DB_ENV *, const char *); /* 32-bit offset=720 size=4, 64=bit offset=1312 size=8 */
  void* __toku_dummy13[1];
  void (*set_errcall) (DB_ENV *, void (*)(const DB_ENV *, const char *, const char *)); /* 32-bit offset=728 size=4, 64=bit offset=1328 size=8 */
  void (*set_errfile) (DB_ENV *, FILE*); /* 32-bit offset=732 size=4, 64=bit offset=1336 size=8 */
  void (*set_errpfx) (DB_ENV *, const char *); /* 32-bit offset=736 size=4, 64=bit offset=1344 size=8 */
  void* __toku_dummy14[1];
  int  (*set_flags) (DB_ENV *, u_int32_t, int); /* 32-bit offset=744 size=4, 64=bit offset=1360 size=8 */
  void* __toku_dummy15[2];
  int  (*set_lg_bsize) (DB_ENV *, u_int32_t); /* 32-bit offset=756 size=4, 64=bit offset=1384 size=8 */
  int  (*set_lg_dir) (DB_ENV *, const char *); /* 32-bit offset=760 size=4, 64=bit offset=1392 size=8 */
  void* __toku_dummy16[1];
  int  (*set_lg_max) (DB_ENV *, u_int32_t); /* 32-bit offset=768 size=4, 64=bit offset=1408 size=8 */
  void* __toku_dummy17[2];
  int  (*set_lk_detect) (DB_ENV *, u_int32_t); /* 32-bit offset=780 size=4, 64=bit offset=1432 size=8 */
  int  (*set_lk_max) (DB_ENV *, u_int32_t); /* 32-bit offset=784 size=4, 64=bit offset=1440 size=8 */
  void* __toku_dummy18[1];
  int  (*set_lk_max_locks) (DB_ENV *, u_int32_t); /* 32-bit offset=792 size=4, 64=bit offset=1456 size=8 */
  void* __toku_dummy19[16];
  int  (*set_tmp_dir) (DB_ENV *, const char *); /* 32-bit offset=860 size=4, 64=bit offset=1592 size=8 */
  void* __toku_dummy20[2];
  int  (*set_verbose) (DB_ENV *, u_int32_t, int); /* 32-bit offset=872 size=4, 64=bit offset=1616 size=8 */
  void* __toku_dummy21[1];
  int  (*txn_begin) (DB_ENV *, DB_TXN *, DB_TXN **, u_int32_t); /* 32-bit offset=880 size=4, 64=bit offset=1632 size=8 */
  int  (*txn_checkpoint) (DB_ENV *, u_int32_t, u_int32_t, u_int32_t); /* 32-bit offset=884 size=4, 64=bit offset=1640 size=8 */
  void* __toku_dummy22[1];
  int  (*txn_stat) (DB_ENV *, DB_TXN_STAT **, u_int32_t); /* 32-bit offset=892 size=4, 64=bit offset=1656 size=8 */
  void* __toku_dummy23[2]; /* Padding at the end */ 
  char __toku_dummy24[16];  /* Padding at the end */ 
};
struct __toku_db_key_range {
  double less; /* 32-bit offset=0 size=8, 64=bit offset=0 size=8 */
  double equal; /* 32-bit offset=8 size=8, 64=bit offset=8 size=8 */
  double greater; /* 32-bit offset=16 size=8, 64=bit offset=16 size=8 */
  void* __toku_dummy0[194]; /* Padding at the end */ 
  char __toku_dummy1[120];  /* Padding at the end */ 
};
struct __toku_db_lsn {
  char __toku_dummy0[8];  /* Padding at the end */ 
};
struct __toku_db {
  struct __toku_db_internal *i;
  int (*key_range64)(DB*, DB_TXN *, DBT *, u_int64_t *less, u_int64_t *equal, u_int64_t *greater, int *is_exact);
  void* __toku_dummy0[2];
  void *app_private; /* 32-bit offset=16 size=4, 64=bit offset=32 size=8 */
  DB_ENV *dbenv; /* 32-bit offset=20 size=4, 64=bit offset=40 size=8 */
  int (*pre_acquire_read_lock)(DB*, DB_TXN*, const DBT*, const DBT*, const DBT*, const DBT*);
  void* __toku_dummy1[33];
  char __toku_dummy2[96];
  void *api_internal; /* 32-bit offset=256 size=4, 64=bit offset=416 size=8 */
  const DBT* (*dbt_pos_infty)(void);
  void* __toku_dummy3[3];
  int (*associate) (DB*, DB_TXN*, DB*, int(*)(DB*, const DBT*, const DBT*, DBT*), u_int32_t); /* 32-bit offset=276 size=4, 64=bit offset=456 size=8 */
  int (*close) (DB*, u_int32_t); /* 32-bit offset=280 size=4, 64=bit offset=464 size=8 */
  const DBT* (*dbt_neg_infty)(void);
  int (*cursor) (DB *, DB_TXN *, DBC **, u_int32_t); /* 32-bit offset=288 size=4, 64=bit offset=480 size=8 */
  int (*del) (DB *, DB_TXN *, DBT *, u_int32_t); /* 32-bit offset=292 size=4, 64=bit offset=488 size=8 */
  void* __toku_dummy4[2];
  int (*fd) (DB *, int *); /* 32-bit offset=304 size=4, 64=bit offset=512 size=8 */
  int (*get) (DB *, DB_TXN *, DBT *, DBT *, u_int32_t); /* 32-bit offset=308 size=4, 64=bit offset=520 size=8 */
  void* __toku_dummy5[8];
  int (*get_flags) (DB *, u_int32_t *); /* 32-bit offset=344 size=4, 64=bit offset=592 size=8 */
  void* __toku_dummy6[6];
  int (*get_pagesize) (DB *, u_int32_t *); /* 32-bit offset=372 size=4, 64=bit offset=648 size=8 */
  void* __toku_dummy7[8];
  int (*key_range) (DB *, DB_TXN *, DBT *, DB_KEY_RANGE *, u_int32_t); /* 32-bit offset=408 size=4, 64=bit offset=720 size=8 */
  int (*open) (DB *, DB_TXN *, const char *, const char *, DBTYPE, u_int32_t, int); /* 32-bit offset=412 size=4, 64=bit offset=728 size=8 */
  int (*pget) (DB *, DB_TXN *, DBT *, DBT *, DBT *, u_int32_t); /* 32-bit offset=416 size=4, 64=bit offset=736 size=8 */
  int (*put) (DB *, DB_TXN *, DBT *, DBT *, u_int32_t); /* 32-bit offset=420 size=4, 64=bit offset=744 size=8 */
  int (*remove) (DB *, const char *, const char *, u_int32_t); /* 32-bit offset=424 size=4, 64=bit offset=752 size=8 */
  int (*rename) (DB *, const char *, const char *, const char *, u_int32_t); /* 32-bit offset=428 size=4, 64=bit offset=760 size=8 */
  void* __toku_dummy8[2];
  int (*set_bt_compare) (DB *, int (*)(DB *, const DBT *, const DBT *)); /* 32-bit offset=440 size=4, 64=bit offset=784 size=8 */
  void* __toku_dummy9[3];
  int (*set_dup_compare) (DB *, int (*)(DB *, const DBT *, const DBT *)); /* 32-bit offset=456 size=4, 64=bit offset=816 size=8 */
  void* __toku_dummy10[2];
  void (*set_errfile) (DB *, FILE*); /* 32-bit offset=468 size=4, 64=bit offset=840 size=8 */
  void* __toku_dummy11[2];
  int (*set_flags) (DB *, u_int32_t); /* 32-bit offset=480 size=4, 64=bit offset=864 size=8 */
  void* __toku_dummy12[6];
  int (*set_pagesize) (DB *, u_int32_t); /* 32-bit offset=508 size=4, 64=bit offset=920 size=8 */
  void* __toku_dummy13[6];
  int (*stat) (DB *, void *, u_int32_t); /* 32-bit offset=536 size=4, 64=bit offset=976 size=8 */
  void* __toku_dummy14[4];
  int (*verify) (DB *, const char *, const char *, FILE *, u_int32_t); /* 32-bit offset=556 size=4, 64=bit offset=1016 size=8 */
  void* __toku_dummy15[5]; /* Padding at the end */ 
  char __toku_dummy16[16];  /* Padding at the end */ 
};
struct __toku_db_txn_active {
  u_int32_t txnid; /* 32-bit offset=0 size=4, 64=bit offset=0 size=4 */
  void* __toku_dummy0[1];
  char __toku_dummy1[12];
  DB_LSN lsn; /* 32-bit offset=20 size=8, 64=bit offset=24 size=8 */
  char __toku_dummy2[184];  /* Padding at the end */ 
};
struct __toku_db_txn {
  DB_ENV *mgrp /*In TokuDB, mgrp is a DB_ENV not a DB_TXNMGR*/; /* 32-bit offset=0 size=4, 64=bit offset=0 size=8 */
  struct __toku_db_txn_internal *i;
  void* __toku_dummy0[16];
  char __toku_dummy1[16];
  void *api_internal; /* 32-bit offset=88 size=4, 64=bit offset=160 size=8 */
  void* __toku_dummy2[2];
  int (*abort) (DB_TXN *); /* 32-bit offset=100 size=4, 64=bit offset=184 size=8 */
  int (*commit) (DB_TXN*, u_int32_t); /* 32-bit offset=104 size=4, 64=bit offset=192 size=8 */
  void* __toku_dummy3[2];
  u_int32_t (*id) (DB_TXN *); /* 32-bit offset=116 size=4, 64=bit offset=216 size=8 */
  void* __toku_dummy4[5]; /* Padding at the end */ 
};
struct __toku_db_txn_stat {
  void* __toku_dummy0[1];
  char __toku_dummy1[28];
  u_int32_t st_nactive; /* 32-bit offset=32 size=4, 64=bit offset=36 size=4 */
  char __toku_dummy2[8];
  DB_TXN_ACTIVE *st_txnarray; /* 32-bit offset=44 size=4, 64=bit offset=48 size=8 */
  void* __toku_dummy3[1]; /* Padding at the end */ 
  char __toku_dummy4[8];  /* Padding at the end */ 
};
struct __toku_dbc {
  DB *dbp; /* 32-bit offset=0 size=4, 64=bit offset=0 size=8 */
  struct __toku_dbc_internal *i;
  void* __toku_dummy0[19];
  char __toku_dummy1[104];
  int (*c_close) (DBC *); /* 32-bit offset=188 size=4, 64=bit offset=272 size=8 */
  int (*c_count) (DBC *, db_recno_t *, u_int32_t); /* 32-bit offset=192 size=4, 64=bit offset=280 size=8 */
  int (*c_del) (DBC *, u_int32_t); /* 32-bit offset=196 size=4, 64=bit offset=288 size=8 */
  void* __toku_dummy2[1];
  int (*c_get) (DBC *, DBT *, DBT *, u_int32_t); /* 32-bit offset=204 size=4, 64=bit offset=304 size=8 */
  int (*c_pget) (DBC *, DBT *, DBT *, DBT *, u_int32_t); /* 32-bit offset=208 size=4, 64=bit offset=312 size=8 */
  int (*c_put) (DBC *, DBT *, DBT *, u_int32_t); /* 32-bit offset=212 size=4, 64=bit offset=320 size=8 */
  void* __toku_dummy3[8]; /* Padding at the end */ 
};
struct __toku_dbt {
  void*data; /* 32-bit offset=0 size=4, 64=bit offset=0 size=8 */
  u_int32_t size; /* 32-bit offset=4 size=4, 64=bit offset=8 size=4 */
  u_int32_t ulen; /* 32-bit offset=8 size=4, 64=bit offset=12 size=4 */
  char __toku_dummy0[8];
  u_int32_t flags; /* 32-bit offset=20 size=4, 64=bit offset=24 size=4 */
  /* 4 more bytes of alignment in the 64-bit case. */
};
#ifdef _TOKUDB_WRAP_H
#define txn_begin txn_begin_tokudb
#endif
int db_env_create(DB_ENV **, u_int32_t) __attribute__((__visibility__("default")));
int db_create(DB **, DB_ENV *, u_int32_t) __attribute__((__visibility__("default")));
char *db_strerror(int) __attribute__((__visibility__("default")));
const char *db_version(int*,int *,int *) __attribute__((__visibility__("default")));
int log_compare (const DB_LSN*, const DB_LSN *) __attribute__((__visibility__("default")));
int db_env_set_func_fsync (int (*)(int)) __attribute__((__visibility__("default")));
int toku_set_trace_file (char *fname) __attribute__((__visibility__("default")));
int toku_close_trace_file (void) __attribute__((__visibility__("default")));
#if defined(__cplusplus)
}
#endif
#endif
