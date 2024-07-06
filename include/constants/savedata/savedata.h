#ifndef POKEPLATINUM_CONSTANTS_SAVEDATA_H
#define POKEPLATINUM_CONSTANTS_SAVEDATA_H

enum LoadResult {
    LOAD_RESULT_EMPTY = 0,
    LOAD_RESULT_OK,
    LOAD_RESULT_CORRUPT,
    LOAD_RESULT_ERROR,
};

enum SaveResult {
    SAVE_RESULT_PROCEED = 0,
    SAVE_RESULT_PROCEED_FINAL,
    SAVE_RESULT_OK,
    SAVE_RESULT_CORRUPT,
};

enum SaveSectorResult {
    SECTOR_RESULT_INVALID = 0,
    SECTOR_RESULT_PARTIAL_VALID,
    SECTOR_RESULT_VALID,
};

enum SaveSectorID {
    SECTOR_ID_PRIMARY = 0,
    SECTOR_ID_BACKUP,
    SECTOR_ID_ERROR,

    SECTOR_ID_MAX = SECTOR_ID_ERROR,
};

enum SaveError {
    SAVE_ERROR_DISABLE_WRITE = 0,
    SAVE_ERROR_DISABLE_READ,
};

#define SECONDARY_FOOTER_SIZE 8

#define SECTOR_SIGNATURE 0x20060623

#define PRIMARY_SECTOR_START 0
#define BACKUP_SECTOR_START  64

#define NORMAL_LOAD_CORRUPT   (1 << 0)
#define NORMAL_LOAD_ERROR     (1 << 1)
#define FRONTIER_LOAD_CORRUPT (1 << 2)
#define FRONTIER_LOAD_ERROR   (1 << 3)
#define VIDEO_LOAD_CORRUPT    (1 << 4)
#define VIDEO_LOAD_ERROR      (1 << 5)

#endif // POKEPLATINUM_CONSTANTS_SAVEDATA_H
