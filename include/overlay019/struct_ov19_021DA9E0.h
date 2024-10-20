#ifndef POKEPLATINUM_STRUCT_OV19_021DA9E0_H
#define POKEPLATINUM_STRUCT_OV19_021DA9E0_H

#include <nnsys.h>

#include "struct_decls/sprite_decl.h"
#include "struct_decls/struct_02007768_decl.h"
#include "struct_decls/struct_0200C440_decl.h"

#include "overlay019/struct_ov19_021D4DF0.h"
#include "overlay019/struct_ov19_021D61B0_decl.h"

#include "bg_window.h"
#include "cell_actor.h"
#include "strbuf.h"
#include "sys_task_manager.h"

typedef struct {
    BOOL unk_00;
    Window *unk_04;
    BgConfig *unk_08;
    CellActorCollection *unk_0C;
    const UnkStruct_ov19_021D4DF0 *unk_10;
    UnkStruct_ov19_021D61B0 *unk_14;
    UnkStruct_0200C440 *unk_18;
    UnkStruct_0200C440 *unk_1C;
    UnkStruct_02007768 *unk_20;
    Sprite *unk_24;
    void *unk_28;
    NNSG2dCellDataBank *unk_2C;
    CellActor *unk_30;
    void *unk_34;
    NNSG2dCellDataBank *unk_38;
    CellActor *unk_3C[2];
    Strbuf *unk_44;
    Strbuf *unk_48;
    SysTask *unk_4C;
    u8 padding_50[4];
} UnkStruct_ov19_021DA9E0;

#endif // POKEPLATINUM_STRUCT_OV19_021DA9E0_H
