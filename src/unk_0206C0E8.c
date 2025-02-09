#include "unk_0206C0E8.h"

#include <nitro.h>
#include <string.h>

#include "struct_decls/struct_02061AB4_decl.h"

#include "field/field_system.h"
#include "field/field_system_sub2_t.h"
#include "overlay006/ov6_022426AC.h"
#include "overlay006/ov6_02242984.h"
#include "overlay006/struct_ov6_022426B8_decl.h"
#include "overlay006/struct_ov6_02242A8C_decl.h"

#include "core_sys.h"
#include "field_map_change.h"
#include "field_task.h"
#include "field_transition.h"
#include "heap.h"
#include "location.h"
#include "map_object.h"
#include "player_avatar.h"
#include "system_flags.h"
#include "unk_02005474.h"
#include "unk_02056B30.h"
#include "unk_02070428.h"
#include "vars_flags.h"

typedef struct {
    UnkStruct_ov6_022426B8 *unk_00;
    UnkStruct_ov6_02242A8C *unk_04;
    Location *unk_08;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
} UnkStruct_0206C0E8;

static BOOL sub_0206C120(FieldTask *taskMan);

void sub_0206C0E8(FieldSystem *fieldSystem)
{
    UnkStruct_0206C0E8 *v0 = Heap_AllocFromHeapAtEnd(11, sizeof(UnkStruct_0206C0E8));

    v0->unk_00 = ov6_022426AC(11);
    v0->unk_04 = ov6_02242A10(11, fieldSystem);
    v0->unk_0C = 0;
    v0->unk_0D = 0;

    FieldTask_InitCall(fieldSystem->task, sub_0206C120, v0);
}

static BOOL sub_0206C120(FieldTask *taskMan)
{
    FieldSystem *fieldSystem = FieldTask_GetFieldSystem(taskMan);
    UnkStruct_0206C0E8 *v1 = FieldTask_GetEnv(taskMan);

    switch (v1->unk_0C) {
    case 0:
        sub_02070428(fieldSystem, 1);
        ov6_02242A94(v1->unk_0D, v1->unk_04);
        v1->unk_08 = ov6_02242AEC(v1->unk_04);
        FieldTransition_FadeOut(taskMan);
        v1->unk_0C = 1;
        break;
    case 1:
        FieldTransition_FinishMap(taskMan);
        v1->unk_0C = 2;
        break;
    case 2: {
        VarsFlags *v2 = SaveData_GetVarsFlags(fieldSystem->saveData);

        if (v1->unk_0D == 0) {
            SystemFlag_SetPoketchHidden(v2);
        } else if (v1->unk_0D == 5) {
            SystemFlag_ClearPoketchHidden(v2);
        }
    }

        FieldTask_ChangeMapByLocation(taskMan, v1->unk_08);
        v1->unk_0C = 3;
        break;
    case 3:
        FieldTransition_StartMap(taskMan);
        v1->unk_0C = 4;
        v1->unk_0E = 0;
        break;
    case 4: {
        MapObject *v3 = Player_MapObject(fieldSystem->playerAvatar);
        if (v1->unk_0D <= 5) {
            int v4;

            v4 = ov6_02242984(fieldSystem, v1->unk_0E);
            if (!v4) {
                v1->unk_0C = (++v1->unk_0E < MAX_GRASS_ENCOUNTERS) ? 4 : 6;
                break;
            }
            MapObject_SetHidden(v3, 1);
            ov6_022426C0(v1->unk_00, v4);
            ov6_022427F4(v1->unk_00);
            Sound_PlayEffect(1657);
            sub_02056B30(taskMan, 3, 17, 0xffff, 0x0, 6, 1, 11);
            v1->unk_0C = 5;
        } else {
            MapObject_SetHidden(v3, 0);
            FieldTransition_FadeIn(taskMan);
            v1->unk_0C = 8;
        }
    } break;
    case 5:
        if (gCoreSys.pressedKeys & PAD_BUTTON_A) {
            ov6_02242A94(v1->unk_0D, v1->unk_04);
            v1->unk_08 = ov6_02242AEC(v1->unk_04);
            Sound_PlayEffect(1657);
            sub_02056B30(taskMan, 3, 16, 0xffff, 0x0, 6, 1, 11);
            v1->unk_0C = (++v1->unk_0E < MAX_GRASS_ENCOUNTERS) ? 4 : 6;
        }
        break;
    case 6:
        ov6_02242814(v1->unk_00);
        v1->unk_0C = 7;
        v1->unk_0D++;
        break;
    case 7:
        if (ov6_02242820(v1->unk_00)) {
            ov6_02242828(v1->unk_00);
            v1->unk_0C = 1;
        }
        break;
    case 8:
        sub_02070428(fieldSystem, 0);
        ov6_02242A8C(v1->unk_04);
        ov6_022426B8(v1->unk_00);
        Heap_FreeToHeap(v1);

        return 1;
    }

    return 0;
}
